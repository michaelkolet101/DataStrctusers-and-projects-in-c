/*******************************************************************************
Data Structures queue

Written by: Michael Kolet
Reviewd by: Tal

Functions for WS
*******************************************************************************/

#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc free */

#include "queue.h"
#include "utils.h"
#include "slist.h"

#define SUCCESS 0
#define FAIL 1

struct queue
{
	slist_ty *list;
};
/***************************Macros Functions *********************************/
#define ALLOC_CHK(a,b,c)	 	\
{				 	 			\
	if(NULL == a) 			 	\
	{						 	\
			free(b);			\
			return c;		 	\
	} 							\
}

queue_ty* QueueCreate(void)
{
	queue_ty *new_queue = (queue_ty *)malloc(sizeof(queue_ty));
	
	if (NULL == new_queue)
	{
		return NULL;
	}
	
	new_queue->list = SlistCreate();
	
	ALLOC_CHK(new_queue->list ,new_queue, NULL)

	return new_queue;
}

void QueueDestroy(queue_ty *queue)
{
	assert(queue);
	
	SlistDestroy(queue->list);
	
	free(queue);
}

int QueueEnqueue(queue_ty *queue, void *data)
{
	iterator_ty iter = {NULL};
	
	assert(queue);
	assert(data);
	
	iter = SlistEnd(queue->list);
	
	iter = SlistInsertBefore(iter, data);
	
	/* check if itrator points to dummy */
	if (iter.slist_node == SlistEnd(queue->list).slist_node)
	{
		return FAIL;
	}
	
	return SUCCESS;
}

void QueueDequeue(queue_ty *queue)
{
	assert(queue);
	
	SlistRemove(SlistBegin(queue->list));
}

void *QueuePeek(const queue_ty *queue)
{
	assert(queue);
	
	return SlistGetData(SlistBegin(queue->list));
}

size_t QueueSize(const queue_ty *queue)
{
	assert(queue);
	
	return SlistCount(queue->list);
}

int QueueIsEmpty(const queue_ty *queue)
{
	assert(queue);
	
	return SlistIsEmpty(queue->list);
}

void QueueAppend(queue_ty *first, queue_ty *second)
{
	assert(first);
	assert(second);
	
	SlistAppend(first->list, second->list);
	free(second);
}






