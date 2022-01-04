/*******************************************************************************
Data Structures : dlist->

Written by: Michael Kolet
Reviewd by: 

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */

#include "utils.h"
#include "sorted_list.h"

#define SUCCESS 0
#define FAIL 1

static int AddCount(void *data, void *count);
 
/* Structs: */

struct sortlist
{
	dlist_ty *dlist;	
	cmp_func_ty cmp_func;
};



/*static int IsDummy(iterator_ty iterator);*/
/******************************************************************************/

/*creat dlist */
sortlist_ty *SortedListCreate(cmp_func_ty cmp_func)
{
    sortlist_ty *new_list = NULL;
    
    new_list = (sortlist_ty *)malloc(sizeof(sortlist_ty));
	ALLOC_CHK(new_list, NULL);
	
	new_list->dlist = DlistCreate();
	if (new_list->dlist == NULL)
	{
		free(new_list);
		return NULL;
	}
	new_list->cmp_func = cmp_func;
    
    return new_list;
}

/************************************************************************/


void SortedListDestroy(sortlist_ty *sortlist)
{
	assert(sortlist);
	assert(sortlist->dlist);
	
	DlistDestroy(sortlist->dlist);
	
	free(sortlist);
}

/************************************************************************/

size_t SortedListSize(const sortlist_ty *sortlist)
{
	assert(sortlist);
	assert(sortlist->dlist);
	
	return DlistSize(sortlist->dlist);
}

/************************************************************************/

int SortedListIsEmpty(const sortlist_ty *sortlist)
{
	assert(sortlist);
	assert(sortlist->dlist);
	
	return DlistIsEmpty(sortlist->dlist);
}

/************************************************************************/

srt_iter_ty SortedListBegin(const sortlist_ty *sortlist)
{
	srt_iter_ty current = {NULL};
	
	assert(sortlist);
	assert(sortlist->dlist);
	
	/*DEBUG_ONLY*/
	DEBUG_ONLY(iter->list = (sortlist_ty *)sortlist);
	
	current.iterator = DlistBegin(sortlist->dlist);
	
	return current;
}

/************************************************************************/

srt_iter_ty SortedListEnd(const sortlist_ty *sortlist)
{
	srt_iter_ty current = {NULL};
	
	assert(sortlist);
	assert(sortlist->dlist);
	
	/*DEBUG_ONLY */
	DEBUG_ONLY(iter->list = (dlist_ty *)dlist);
	
	current.iterator = DlistEnd(sortlist->dlist);
	
	return current;
}

/************************************************************************/

srt_iter_ty SortedListNext(srt_iter_ty current)
{
	/*	assigning iterator with next address and dlist (in debug mode) */
	DEBUG_ONLY(next->list = iterator_to_next->list);
	
	current.iterator = DlistNext(current.iterator);
	
	return current;
}

/************************************************************************/

srt_iter_ty SortedListPrev(srt_iter_ty current)
{
	/*	assigning iterator with next address and dlist (in debug mode) */
	DEBUG_ONLY(next->list = current->list);
	
	current.iterator = DlistPrev(current.iterator);
	return current;
}

/************************************************************************/

int SortedListIsSameIter(srt_iter_ty first, srt_iter_ty second)
{
	return first.iterator.dlist_node == second.iterator.dlist_node;
}

/************************************************************************/

void *SortedListGetData(srt_iter_ty current)
{
	return DlistGetData(current.iterator);
}


/*****************************************************************************/

/************************************************************************/

/************************************************************************/

srt_iter_ty SortedListRemove(srt_iter_ty where)
{
	DlistRemove(where.iterator);
	return where;
}

/************************************************************************/

void *SortedListPopFront(sortlist_ty *sortlist)
{
	assert(sortlist);
	assert(sortlist->dlist);
	
	return DlistPopFront(sortlist->dlist);
}

void *SortedListPopBack(sortlist_ty *sortlist)
{
	assert(sortlist);
	assert(sortlist->dlist);
	
	return DlistPopBack(sortlist->dlist);
}

/***************************************************************************/

srt_iter_ty SortedListInsert(sortlist_ty *sortlist, const void *data)
{
    srt_iter_ty runner = {NULL};
    srt_iter_ty dummy = {NULL};
    
    assert(sortlist);
	assert(sortlist->dlist);
    
    runner = SortedListBegin(sortlist);
    dummy = SortedListEnd(sortlist);
    
    while(!SortedListIsSameIter(runner, dummy)) /* run from start to end */
    {
        if (0 > sortlist->cmp_func((const void *)SortedListGetData(runner), 
                                                                        data))
                /* while the data in the runner is "smaller" than user's data */
        {
            runner = SortedListNext(runner); /* keep running */
        }
        else
        {
            break;
        }
    }
    
    runner.iterator = DlistInsertBefore(runner.iterator, data);
    DEBUG_ONLY(runner.list = sortlist)
    
    return runner;
}


int SortedListForEach(srt_iter_ty start,
				 srt_iter_ty end,
				 int(*op_func_ty)(void *data, void *param),
				 void *param)
{
	assert (start.list != end.list);
	assert(start);
	assert(end);
	assert(op_func);

	return DlistForEach(start.iterator, end.iterator, op_func, param);
}

sortlist_ty *SortedListMerge(sortlist_ty *first ,sortlist_ty *second)
{
	srt_iter_ty start = {NULL};
	srt_iter_ty end = {NULL};
	srt_iter_ty dest = {NULL};

	assert(first);
	assert(second);
	assert(first->dlist);
	assert(second->dlist);
	
	start = SortedListBegin(second); /*take start and end of the second*/
	end = SortedListBegin(second);
	
	dest = SortedListBegin(first);

	while(end.iterator.dlist_node != SortedListEnd(second).iterator.dlist_node &&
		 dest.iterator.dlist_node != SortedListEnd(first).iterator.dlist_node)
	{
		if((first->cmp_func( SortedListGetData(dest), SortedListGetData(start)))>=0)
		{
			dest= SortedListNext(dest);
		}
		else if((first->cmp_func( SortedListGetData(dest), SortedListGetData(end))) < 0)
		{
			end = SortedListNext(end);
			
		} 
		else if((first->cmp_func( SortedListGetData(dest), SortedListGetData(end))) >= 0)
		{	
			DlistSplice( start.iterator, end.iterator, dest.iterator);
			dest= SortedListNext(dest);
			start = end;
		}

	}
	if(!SortedListIsEmpty(second))
	{
		end = SortedListEnd(second);
		DlistSplice( start.iterator, end.iterator, dest.iterator);	
	}

	return first;
}

srt_iter_ty SortedListFind(sortlist_ty *list,srt_iter_ty start, srt_iter_ty end,
														const void *to_find)
{
	void *temp = NULL;
	srt_iter_ty iter = {NULL};
	match_func_ty op_func = NULL;
	assert(list);
	assert(list->dlist);
	assert(start.iterator.dlist_node);
	assert(end.iterator.dlist_node);
	
	temp = (void*)to_find;
	op_func = (match_func_ty)list->cmp_func;
	
	iter.iterator = DlistFind( start.iterator, end.iterator, op_func, temp);
	
	return iter;
}

srt_iter_ty SortedListFindIf(srt_iter_ty start,
 					   srt_iter_ty end, 
					   int(*match_func)(const void *data, void *param),
					     void *param)
{
	match_func_ty op_func = NULL;
	srt_iter_ty iter = {NULL};
	
	assert(start.iterator.dlist_node);
	assert(end.iterator.dlist_node);
	
	op_func = (match_func_ty)match_func;
	iter.iterator = DlistFind( start.iterator, end.iterator, op_func, param);
	
	return iter;
}







