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

#include "dlist.h"
#include "utils.h"

#define SUCCESS 0
#define FAIL 1

static int AddCount(void *data, void *count);
 
/* Structs: */

/* Structure of each node in the list*/
struct node
{
	void *data;
	node_ty *prev;
	node_ty *next;
};

/* Structure of the list */
struct dlist
{
	node_ty *head;
	node_ty *tail;
};


/*static int IsDummy(iterator_ty iterator);*/
/******************************************************************************/

/*creat dlist */
dlist_ty *DlistCreate(void)
{
    dlist_ty *new_list = NULL;
    node_ty *dummy1 = NULL;
    node_ty *dummy2 = NULL;
    
    new_list = (dlist_ty *)malloc(sizeof(dlist_ty));
	ALLOC_CHK(new_list, NULL);
	
    dummy1 = (node_ty *)malloc(sizeof(node_ty));
    ALLOC_CHK_FREE(dummy1, new_list, NULL);	
    
    dummy2 = (node_ty *)malloc(sizeof(node_ty));
    if (dummy2 == NULL)
    {
    	free(dummy1);
    	free(new_list);
    	return NULL;
    }	
    
    
   
    dummy1->data = new_list;
    dummy1->next = dummy2;
    dummy1->prev = NULL;
    
    dummy2->data = new_list;
    dummy2->next = NULL;
    dummy2->prev = dummy1;
    
    new_list->tail = dummy2;
    new_list->head = dummy1;
    
    return new_list;
}

/************************************************************************/


void DlistDestroy(dlist_ty *dlist)
{
	/*	pointers for assigning and freeing nodes */
	node_ty *next_node = NULL;
	node_ty *current_node = NULL;
	
	assert(dlist);
	
	/*	assigning "current_node" pointer to head - for start freeing nodes */
	current_node = dlist->head;
	
	while (current_node != NULL)
	{
		/*	get next node's address to free */
		next_node = current_node -> next;
		
		/*	free current node */
		free(current_node);

		/*	assign next node to current */
		current_node = next_node;
	}
	
	free(dlist);
}

/************************************************************************/

size_t DlistSize(const dlist_ty *dlist)
{
	size_t count = 0;
	size_t status = SUCCESS;
	
	assert(dlist);
	 
	status = DlistForEach(DlistBegin(dlist), DlistEnd(dlist), AddCount,
															 (void *)&count);
	
	if (status != SUCCESS)
	{
		return -1; /*for failure*/
	}

	return count;
}

/************************************************************************/

int DlistIsEmpty(const dlist_ty *dlist)
{
	assert(dlist);
	
	return (dlist->head->next == dlist->tail);
}

/************************************************************************/

iterator_ty DlistBegin(const dlist_ty *dlist)
{
	iterator_ty iter = {NULL};
	
	assert(dlist);
	
	iter.dlist_node = dlist->head->next;
	
	/*DEBUG_ONLY*/
	DEBUG_ONLY(iter->list = (dlist_ty *)dlist);
	
	return iter;
}

/************************************************************************/

iterator_ty DlistEnd(const dlist_ty *dlist)
{
	iterator_ty iter = {NULL};
	
	assert(dlist);
	
	iter.dlist_node = dlist->tail;
	
	/*DEBUG_ONLY */
	DEBUG_ONLY(iter->list = (dlist_ty *)dlist);
	
	return iter;
}

/************************************************************************/

iterator_ty DlistNext(iterator_ty current)
{
 	iterator_ty iterator_to_next = {NULL};
 	
 	assert(current.dlist_node);
 	
 	iterator_to_next = current;
 	
	iterator_to_next.dlist_node = iterator_to_next.dlist_node->next;
	
	/*	assigning iterator with next address and dlist (in debug mode) */
	DEBUG_ONLY(next->list = iterator_to_next->list);
	 
	return iterator_to_next;
}

/************************************************************************/

iterator_ty DlistPrev(iterator_ty current)
{
	iterator_ty iterator_to_back = current;
	
 	assert(iterator->dlist_node);
 	
	iterator_to_back.dlist_node = iterator_to_back.dlist_node->prev;
	
		/*assigning iterator with next address and dlist (in debug mode) */
	DEBUG_ONLY(back->list = iterator_to_back->list);
	 
	return iterator_to_back;
}

/************************************************************************/

int DlistIsSameIter(iterator_ty first, iterator_ty second)
{
	return first.dlist_node == second.dlist_node;
}

/************************************************************************/

void *DlistGetData(iterator_ty current)
{
	assert(current.dlist_node->next); /*asserting this isn't dummy*/
	return current.dlist_node->data;
}


/*****************************************************************************/


void DlistSetData(iterator_ty current, void *data)
{
	assert(current.dlist_node);
	
	/*	user trying to reach out dummy */
	if (NULL == current.dlist_node->next)
	{
		return;
	}
	
	current.dlist_node->data = data;
}

/************************************************************************/

iterator_ty DlistInsertBefore(iterator_ty where, const void *data)
{
	node_ty *new_node = {NULL};
	
	assert(where.dlist_node);
	
	/* Creates a new node */
	new_node = (node_ty *)malloc(sizeof(node_ty));
	
	if (new_node == NULL)
	{
		while (where.dlist_node->next != NULL)
		{
			where = DlistNext(where);
		}
		
		return where;
	}
	
	/*  put in the data  */
	new_node->data = (void *)data;
	/*Tells the new node to indicate the location of the iterator*/
	new_node->next = where.dlist_node;
	/*Tells the previous node to point to the new node*/
	where.dlist_node->prev->next = new_node;
	/*The new node will point backwards to the same value as the iterator 
														points backwards*/
	new_node->prev = where.dlist_node->prev;
	/*The backward pointer of our iterator will point to the new node*/
	where.dlist_node->prev = new_node;
	/*We will move the iterator to the new node we created in the list*/
	where.dlist_node = where.dlist_node->prev;
	
	return where;
}

/************************************************************************/

iterator_ty DlistPushFront(dlist_ty *dlist, const void *data)
{
	assert(dlist);
	
	return DlistInsertBefore(DlistBegin(dlist), data);
}

/************************************************************************/

iterator_ty DlistPushBack(dlist_ty *dlist, const void *data)
{
	assert(dlist);
	
	return DlistInsertBefore(DlistEnd(dlist), data);
}

/************************************************************************/

iterator_ty DlistRemove(iterator_ty where)
{
	iterator_ty delete = {NULL};
	
	assert(where.dlist_node);
	
	delete.dlist_node = where.dlist_node->prev;
	
	where.dlist_node->prev->prev->next = where.dlist_node;
	
	where.dlist_node->prev = where.dlist_node->prev->prev;
	
	free(delete.dlist_node);
	
	where.dlist_node = where.dlist_node->next;
	
	return where;
}

/************************************************************************/

void *DlistPopFront(dlist_ty *dlist)
{
	void *ret_val = NULL;
	iterator_ty delete = {NULL};
	
	assert(dlist);
	
	ret_val = DlistGetData(DlistBegin(dlist));
	
	
	delete = DlistBegin(dlist);
	delete = DlistNext(delete);
	
	DlistRemove(delete);
	
	return ret_val;
}

void *DlistPopBack(dlist_ty *dlist)
{
	void *ret_val = NULL;
	iterator_ty delete = {NULL};
	
	assert(dlist);
	
	ret_val = DlistGetData(DlistBegin(dlist));
	
	delete = DlistEnd(dlist);
	delete = DlistPrev(delete);
	
	DlistRemove(delete);
	
	return ret_val;
}

int DlistForEach(iterator_ty start,
				 iterator_ty end,
				 op_func_ty op_func,
				 void *param)
{
	int status = SUCCESS;
	
	assert (start.list != end.list);
	assert(start);
	assert(end);
	assert(op_func);
	assert(param);
	
	while (start.dlist_node != end.dlist_node)
	{
		status = op_func(start.dlist_node -> data, param);
		
		if (FAIL == status)
		{
			return status;
		}
		
		start.dlist_node = start.dlist_node -> next;
	}
	return status;
}

iterator_ty DlistFind(iterator_ty start,
 					   iterator_ty end, 
					    match_func_ty op_func,
					     void *param)
{
	int status = FAIL;
	
	assert(start.dlist_node);
	assert(end.list_node);
	assert(op_func);
	
	while (start.dlist_node != end.dlist_node)
	{
		if ((op_func(start.dlist_node->data, param)) == SUCCESS) 
		{
			status = SUCCESS;
			return start;
		}	
		start = DlistNext(start);
	}
	
	while (end.dlist_node->next != NULL)
	{
		end = DlistNext(end);
	}
	
	return end;
	
}

iterator_ty DlistSplice(iterator_ty start, iterator_ty end, iterator_ty dest)
{
    node_ty *before_end = NULL;
    node_ty *after_dest = NULL;
    
    
    assert(dest.dlist_node);
    assert(dest.dlist_node->prev);
    
    dest = DlistPrev(dest);
    
    assert(start.dlist_node);
    assert(start.dlist_node->prev);
    assert(start.dlist_node->prev->next);
    assert(end.dlist_node);
    assert(end.dlist_node->prev);
    assert(end.dlist_node->prev->next);
    assert(dest.dlist_node->next);
    assert(dest.dlist_node->next->prev);
    
    before_end = end.dlist_node->prev;
    after_dest = dest.dlist_node->next;
    
    /* connect the node before start to the end node */
    start.dlist_node->prev->next = end.dlist_node;
    end.dlist_node->prev = start.dlist_node->prev;
    
    /* connect the node before dest node to start node */
    dest.dlist_node->next = start.dlist_node;
    start.dlist_node->prev = dest.dlist_node;
    
    /* connect the node before end to the dest node */
    before_end->next = after_dest;
    after_dest->prev = before_end;

    return DlistNext(dest);
}

/****************************************************************************/

int DlistMultiFind(iterator_ty start,
 					   iterator_ty end,
 					    dlist_ty *dest, 
					     match_func_ty op_func,
					      void *param)
{
	int count = 0;
	iterator_ty runner = {NULL};
	
	assert(start);
	assert(end);
	assert(op_func);
	assert(param);
	
	runner.dlist_node = dest->head;
	
	while (start.dlist_node != end.dlist_node)
	{
		if (op_func(start.dlist_node->data, param) == SUCCESS) 
		{
			runner.dlist_node->data = start.dlist_node->data;
			runner = DlistNext(runner);
			++count;
		}	
		start = DlistNext(start);
	}
	return (count > 0) ? count : -1; /* -1 is fail */
}

/********************Service Functions Implementations *********************/

static int AddCount(void *data, void *count)
{	
	assert(data);
	assert(count);
	
	UNUSED(data);
	 
	(*(size_t *)count)++;	
	
	return SUCCESS;
}










