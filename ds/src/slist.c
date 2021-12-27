/*******************************************************************************
Data Structures WorkSheet 2: list.

Written by: Michael Kolet
Reviewd by: Larisa

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */

#include "slist.h"
#include "utils.h"

#define SUCCESS 0
#define FAIL 1

/***************************Macros Functions *********************************/
#define ALLOC_CHK(a,b,c)	 	\
{				 	 			\
	if(NULL == a) 			 	\
	{						 	\
			free(b);			\
			return c;		 	\
	} 							\
}


 
 
/* Structs: */

/* Structure of each node in the list*/
struct node
{
	void *data;
	struct node *next;
} ;

/* Structure of the list */
struct slist
{
    node_ty *head;
    node_ty *tail;
};

static int AddCount(void *data, void *count);

/******************************************************************************/

/*creat slist */
slist_ty *SlistCreate(void)
{
    slist_ty *new_list = NULL;
    node_ty *dummy = NULL;
    
    new_list = (slist_ty *)malloc(sizeof(slist_ty));
	ALLOC_CHK(new_list, NULL, NULL);
	
    dummy = (node_ty *)malloc(sizeof(slist_ty));
    ALLOC_CHK(dummy, new_list, NULL);	
    
    dummy->data = new_list;
    dummy->next = NULL;
    
    new_list->tail = dummy;
    new_list->head = dummy;
    
    return new_list;
}

void SlistDestroy(slist_ty *slist)
{
	/*	pointers for assigning and freeing nodes */
	node_ty *next_node = NULL;
	node_ty *current_node = NULL;
	
	assert(slist);
	
	/*	assigning "cur" pointer to head - for start freeing nodes */
	current_node = slist->head;
	
	while (current_node != NULL)
	{
		/*	get next node's address to free */
		next_node = current_node -> next;
		
		/*	free current node */
		free(current_node);

		/*	assign next node to current */
		current_node = next_node;
	}
	
	free(slist);
}

int SlistIsEmpty(const slist_ty *slist)
{
	assert(slist);
	
	return slist->head == slist->tail;
}

iterator_ty SlistInsertBefore(iterator_ty where, const void *data)
{
	
	node_ty *new_node = NULL;
	slist_ty *tmp = NULL;
	
	/* check if where is dummy */
	if(NULL == where.slist_node->next)
	{
	 	tmp = where.slist_node->data;
	}
	
	/*    allocate new node */
	new_node = (node_ty *)malloc(sizeof(slist_ty));
	
	if (new_node == NULL)
	{
		while(where.slist_node->next)
		{
			where = SlistNext(where);
		}
		return where;
	}
	
	tmp = (slist_ty *)(where.slist_node->data); 
	
	/*DEBUG_ONLY*/
	DEBUG_ONLY(return where.list->tail);
	
	assert(where.slist_node);
	assert(data);
	
	/*copy current node to new node*/
	new_node->data = where.slist_node->data;
	new_node->next = where.slist_node->next;
	
	 /*insert new data to current node*/
	where.slist_node->data = (void *)data;
	where.slist_node->next = new_node;
	
	if (NULL == new_node->next)
	{
		tmp->tail = new_node;/* if the insertion was before the end - update 
																	  the tail*/
	}
	
	return where;
}

iterator_ty SlistRemove(iterator_ty where)
{
	node_ty *next_address = NULL;
    
    assert(where.slist_node);
    assert(where.slist_node -> next); /* this is no not dummy */
    
    next_address = where.slist_node -> next; /* address of the next node */

    /* copy the contents of the next node to the where node */
    where.slist_node -> data = next_address -> data;
    where.slist_node -> next = next_address -> next;
    
    if (NULL == next_address -> next) /* if the removal was before dummy */
    {
         ((slist_ty *)(where.slist_node -> data)) -> tail = where.slist_node; 
                                                         /* update the tail */
    }
    
    /* remove the next node */
    free(next_address);
    
	/*	return next_node's content (where) */
	return where;
}

size_t SlistCount(const slist_ty *slist)
{
	
	size_t count = 0;
	size_t status = SUCCESS;
	
	assert(slist);
	 
	status = SlistForEach(SlistBegin(slist), SlistEnd(slist), AddCount,
															 (void *)&count);
	
	if (status != SUCCESS)
	{
		return 8;
	}
	
	return count;
}

iterator_ty SlistBegin(const slist_ty *slist)
{
	iterator_ty iter = {NULL};
	
	assert(slist);
	
	iter.slist_node = slist->head;
	
	/*DEBUG_ONLY*/
	DEBUG_ONLY(iter.list = (slist_ty *)slist);
	
	return iter;
}

iterator_ty SlistEnd(const slist_ty *slist)
{
	iterator_ty iter = {NULL};
	
	assert(slist);
	
	iter.slist_node = slist->tail;
	
	/*DEBUG_ONLY */
	DEBUG_ONLY(iter.list = (slist_ty *)slist);
	
	return iter;
}

iterator_ty SlistNext(const iterator_ty iterator)
{
 	iterator_ty iterator_to_next = iterator;
 	
	iterator_to_next.slist_node = iterator_to_next.slist_node->next;
	
	assert(iterator.slist_node);
	/*	assigning iterator with next address and slist (in debug mode) */
	DEBUG_ONLY(next.list = iterator_to_next.list);
	 
	return iterator_to_next;
}

int SlistForEach(iterator_ty start,
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
	
	while (start.slist_node != end.slist_node)
	{
		status = op_func(start.slist_node -> data, param);
		
		if (FAIL == status)
		{
			return FAIL;
		}
		
		start.slist_node = start.slist_node -> next;
	}
	return SUCCESS;
}

iterator_ty SlistFind(iterator_ty start, iterator_ty end, match_func_ty op_func,
																    void *param)
{
	assert(start);
	assert(end);
	assert(op_func);
	assert(param);
	
	while (start.slist_node != end.slist_node)
	{
		if (op_func(start.slist_node->data, param) == SUCCESS) 
		{
			return start;
		}	
		start.slist_node= start.slist_node->next;
	}
	
	return end; /*TODO need to return dummy*/
	
}
				 
void *SlistGetData(const iterator_ty iterator)
{
	assert(iterator.slist_node->next); /*asserting this isn't dummy*/
	return iterator.slist_node->data;
}


void SlistSetData(iterator_ty iterator, void *data)
{
	assert(iterator.slist_node);
	assert(data);
	
	/*	user trying to reach out dummy */
	if (NULL == iterator.slist_node -> next)
	{
		return;
	}
	
	iterator.slist_node->data = data;
}

void SlistAppend(slist_ty *first, slist_ty *second)
{
	
	slist_ty *tmp = NULL;
	
	assert(first);
	assert(second);
	
	/* point the dummy of the first to the head of the second */
	first->tail->next = second->head;

	/* make the data of the second list dummy to point to the first list */
	second->tail->data = first->tail->data;

	/* remove the first's dummy from the list */
	SlistRemove(SlistEnd(first));	
	
	/* update the tail */
	tmp = second->tail->data;
	tmp->tail = second->tail;

	/* free the second list structure */
	free(second);
}

/********************Service Functions Implementations *********************/

static int AddCount(void *data, void *count)
{	
	assert(data);
	assert(count);
	
	UNUSED(data);
	 /*TODO unuse data*/
	(*(size_t *)count)++;	
	
	return SUCCESS;
}










