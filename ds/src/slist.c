/*******************************************************************************
Data Structures WorkSheet 2: list.

Written by: Michael Kolet
Reviewd by: Gabriel Poshumenski

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */

#include "../includ/slist.h"

#define GROWTH_FACTOR 2
#define SUCCESS 0
#define FAIL 1
/***************************Macros Functions *********************************/
#define ALLOC_CHK(a,b,c)	 \
do 							 \
{						 	 \
	if(NULL == a) 			 \
	{						 \
		free(b);			 \
		return c;		 	 \
} 							 \
} 							 \
while(0)


 
 
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

struct itrator
{
	node_ty *slist_node;
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
	
	
	/*    allocate new node */
	node_ty *new_node = (node_ty *)malloc(sizeof(slist_ty));
	
	if (new_node == NULL)
	{
		free(new_node);
	}
	
	slist_ty *tmp = (slist_ty *)(where.slist_node->data); 
	
	/*copy current node to new node*/
	new_node->data = where.slist_node->data;
	new_node->next = where.slist_node->next;
	
	 /*insert new data to current node*/
	where.slist_node->data = (void *)data;
	where.slist_node->next = new_node;
	
	if (NULL == new_node->next)
	{
		tmp->tail = new_node;
	}
	
	return where;
}

iterator_ty SlistRemove(iterator_ty where)
{
	/*	save next node pointer */
	node_ty *next_node = where.slist_node -> next;
	
	/*	assert iterator is not dummy */
	assert (next_node != NULL);
	
	/*	assign current pointer with next_node's content (data & pointer) */
	where.slist_node -> data = (void *) next_node -> data;
	where.slist_node -> next = next_node -> next;
	
	/*	remove (free allocation) of next node */
	free(next_node);

	/*	if we changed the tail location - assign new tail at slist level */
	if (NULL == where.slist_node -> next)
	{
		((slist_ty *)where.slist_node -> data) -> tail = where.slist_node;
	} 
	
	/*	return next_node's content (where) */
	return where;
}

size_t SlistCount(const slist_ty *slist)
{
	
	size_t count = 0;
	 
	SlistForEach(SlistBegin(slist), Slistend(slist), AddCount, &count);

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

iterator_ty Slistend(const slist_ty *slist)
{
	iterator_ty iter = {NULL};
	
	assert(slist);
	
	iter.slist_node = slist->tail;
	
	/*DEBUG_ONLY*/
	DEBUG_ONLY(iter.list = (slist_ty *)slist);
	
	return iter;
}

iterator_ty SlistNext(const iterator_ty iterator)
{
	iterator_ty iter = {NULL};
	
	iter.slist_node = iter.slist_node->next;
	
	/*	assigning iterator with next address and slist (in debug mode) */
	DEBUG_ONLY(next.list = iterator.list);
	 
	return iter;
}

int SlistForEach(iterator_ty start,
				 iterator_ty end,
				 op_func_ty op_func,
				 void *param)
{
	
	int status = SUCCESS;
	
	assert (start.list == end.list);
	
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

iterator_ty SlistFind(iterator_ty start, iterator_ty end, match_func_ty op_func, void *param)
{
	
	while (start.slist_node != end.slist_node)
	{
		if (op_func(start.slist_node->data, param) == 1)
		{
			return start;
		}	
		start.slist_node= start.slist_node->next;
	}
	
	return end;
	
}
				 
void *SlistGetData(const iterator_ty iterator)
{
	/*	not allowing vision of dummy */
	if (NULL == iterator.slist_node -> next)
	{
		/*	user trying to reach out dummy */
		return NULL;
	}
	
	return iterator.slist_node->data;
}

void SlistSetData(iterator_ty iterator, void *data)
{
	/*	user trying to reach out dummy */
	if (NULL == iterator.slist_node -> next)
	{
		
		return;
	}
	
	iterator.slist_node->data = data;
}


/********************Service Functions Implementations *********************/

static int AddCount(void *data, void *count)
{	
	
	(*(size_t *)count)++;	
	
	return SUCCESS;
}










