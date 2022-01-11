/*******************************************************************************
Data Structures : sort list->

Written by: Michael Kolet
Reviewd by: olga

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc free*/



#include "sorted_list.h"
#include "utils.h"

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
	ALLOC_CHK(new_list, NULL, NULL);
	
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
	
	sortlist = NULL;
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
	assert(current.iterator.dlist_node);
	
	current.iterator = DlistNext(current.iterator);
	
	return current;
}

/************************************************************************/

srt_iter_ty SortedListPrev(srt_iter_ty current)
{
	assert(current.iterator.dlist_node);
	
	current.iterator = DlistPrev(current.iterator);
	
	return current;
}

/************************************************************************/

int SortedListIsSameIter(srt_iter_ty first, srt_iter_ty second)
{
	/*DEBUG_ONLY */
	DEBUG_ONLY(iter->list = (dlist_ty *)dlist);
	
	return first.iterator.dlist_node == second.iterator.dlist_node;
}

/************************************************************************/

void *SortedListGetData(srt_iter_ty current)
{
	assert(current.iterator.dlist_node);
	
	return DlistGetData(current.iterator);
}


/************************************************************************/

srt_iter_ty SortedListRemove(srt_iter_ty where)
{
	assert(where.iterator.dlist_node);
	
	where.iterator = DlistRemove(where.iterator);
	
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

	return DlistForEach(start.iterator, end.iterator, op_func_ty, param);
}
/*
sortlist_ty *SortedListMerge(sortlist_ty *first ,sortlist_ty *second)
{
	srt_iter_ty start1;
	srt_iter_ty start2;
	srt_iter_ty current2;
	srt_iter_ty end2;
	srt_iter_ty dest;

	assert(first);
	assert(second);
	assert(first->dlist);
	assert(second->dlist);

	start1 = SortedListBegin(first);
	start2 = SortedListBegin(second);
	current2 = SortedListBegin(second);
	end2 = SortedListEnd(second);


	/* While the second list is not empty */
/*	while(!SortedListIsEmpty(second))
	{	
		/* find the first element in first list that is bigger than the first element 
		 * in the second list, this is the dest */	
/*		while(!IsDummy(start1) &&
			(first->cmp_func(SortedListGetData(start1), SortedListGetData(start2)) <= 0))
		{
			start1 = SortedListNext(start1);
		}
		dest = start1;

		/* if bigger element not found and the first's list dummy is reached,
		 * merge the rest of second to dest and return */
/*	if(IsDummy(dest))
		{
			DlistSplice(start2.iterator, end2.iterator, dest.iterator);
			return first;
		}

		/* find all the elements from the second list that should be merged to dest
		 * i.e the first element in second that is bigger than the dest */
/*	while(!IsDummy(current2) &&
			(second->cmp_func(SortedListGetData(current2), SortedListGetData(dest)) <= 0))
		{
			current2 = SortedListNext(current2);
		} 

		/*move elements from start2 to one before the current, to the dest (before) */
/*		DlistSplice(start2.iterator, current2.iterator, dest.iterator);
		start2 = current2;
	}
	/* return pointer to first sorted list that is now merged */
/*	return first;
}
*/


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
	
	/*TODO it's not must can use match_func insted of op*/
	op_func = (match_func_ty)match_func;
		iter.iterator = DlistFind( start.iterator, end.iterator, op_func, param);
	
	return iter;
}

/*static int IsDummy(iterator_ty iterator)
{
	return (iterator.dlist_node -> next == NULL || 
								iterator.dlist_node -> prev == NULL);
}

*/




