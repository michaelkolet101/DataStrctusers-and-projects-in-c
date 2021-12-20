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


/***************************Macros Functions *********************************/
#define ALLOC_CHK(a,b)		 \
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
    node_ty next;
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
    
    dummy->data = slist;
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
		iter = iter->next;
		
		free(ptr_to_free);
	}
}

int SlistIsEmpty(const slist_ty *slist)
{
	return slist->head = slist->tail;
}

iterator_ty SlistInsertBefore(iterator_ty where, const void *data)
{
	node_ty new_node = (node_ty *)malloc(sizeof(slist_ty));
	
	ALLOC_CHK(new_node,NULL);
	
	new_node->data = *data;
	
	new_node->next = ;
	
}

size_t SlistCount(const slist_ty *slist)
{
	node_ty *iter = slist->head;
	
	while (iter->next != NULL)
	{
		++count;
		iter = iter->next;
	}
	return count;
}


