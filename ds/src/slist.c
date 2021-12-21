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
    node_ty *next;
};

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

int IsMatch(void *a, void *b);
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
	node_ty *iter = slist->head;
	node_ty *ptr_to_free = NULL;
	
	while (iter->next != NULL)
	{
		ptr_to_free = iter;
		iter = iter->next->next;
		
		free(ptr_to_free);
	}
	free(iter);
	free(slist);
}

int SlistIsEmpty(const slist_ty *slist)
{
	return slist->head == slist->tail;
}

iterator_ty SlistInsertBefore(iterator_ty where, const void *data)
{
	/*    allocate new node */
	node_ty *new_node = (node_ty *)malloc(sizeof(slist_ty));
	/*ALLOC_CHK(new_node,NULL, NULL);*/
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
	node_ty *next_addres = where.slist_node->next;
	
	slist_ty *tmp = (slist_ty *)((where.slist_node->data));
	
	where.slist_node->data = where.slist_node->next->data;
	where.slist_node->next = where.slist_node->next->next;
	
	if (NULL == next_addres)
	{
		tmp->tail = next_addres;
	}
	
	/*myby need to make it free*/
	tmp = NULL;
}

size_t SlistCount(const slist_ty *slist)
{
	
/*	
	 
	SlistForEach(SlistBegin(slist),
				 Slistend(slist),
				 AddCount,
				 &count);
*/				 
	size_t count = 0;
	size_t *ptr_count = &count;
	
	node_ty *iter = slist->head;
	
	while (iter->next != NULL)
	{
		++count;
		iter = iter->next;
	}
	return count;
}

iterator_ty SlistBegin(const slist_ty *slist)
{
	iterator_ty iter = {NULL};
	
	iter.slist_node = slist->head;
	
	return iter;
}

iterator_ty Slistend(const slist_ty *slist)
{
	iterator_ty iter = {NULL};
	iter.slist_node = slist->tail;
	
	return iter;
}

iterator_ty SlistNext(const iterator_ty iterator)
{
	iterator_ty iter;
	iter.slist_node->next = iter.slist_node->next->next;
	 
	return iter;
}

int SlistForEach(iterator_ty start,
				 iterator_ty end,
				 op_func_ty op_func,
				 void *param)
{
	int data = 0;
	
	int status = SUCCESS;
	while (start.slist_node != end.slist_node)
	{
		status = op_func((void *)&data, param);
		if (FAIL == status)
		{
			return FAIL;
		}
		
		SlistNext(start);
	}
	return SUCCESS;
}

iterator_ty SlistFind(iterator_ty start, iterator_ty end, match_func_ty op_func,
					  void *param)
{
	
	while (start.slist_node != end.slist_node)
	{
		if (op_func(start.slist_node->data, param) == 0)
		{
			return start;
		}	
		start.slist_node->next = start.slist_node->next->next;
	}
	
	return end;
	
}
				 
void *SlistGetData(const iterator_ty iterator)
{
	return iterator.slist_node->data;
}

void SlistSetData(iterator_ty iterator, void *data)
{
	iterator.slist_node->data = data;
}



static int AddCount(void *data, void *count)
{	
	
	(*(size_t *)count)++;	
	
	return SUCCESS;
}


int IsMatch(void *a, void *b)
{
	int ret = 0;
	
	ret = memcmp(a,b,1);
	
	return ret;
}
