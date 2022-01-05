/*******************************************************************************
Data Structures : sort list->

Written by: Michael Kolet
Reviewd by: olga

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc free*/


#include "utils.h"
#include "sorted_list.h"
#include "sorted_list.c"
#include "priorityq.h"

#define SUCCESS 0
#define FAIL 1

static int AddCount(void *data, void *count);
 
/* Structs: */


struct priorityq
{
	sortlist_ty *sortlist;
};


pq_ty *PQCreate\
		(int(*cmp_func)(const void *data1, const void *data2))
		{
			pq_ty *new_q = malloc(sizeof(pq_ty));
			ALLOC_CHK(new_q, NULL, NULL);
			
			new_q->sortlist = SortedListCreate(cmp_func);
			
			return new_q;
		}

void PQDestroy(pq_ty *pq)
{
	SortedListDestroy(pq->sortlist);
	
	free(pq);
	pq = NULL;
}
/*
int PQEnqueue(pq_ty *pq, const void *data)
{	
	assert(pq);
	assert(pq->sortlist);
	
	return SortedListInsert(pq->sortlist, data);
}

void *PQDequeue(pq_ty *pq)
{
	assert(pq);
	assert(pq->sortlist);
	
	return SortedListPopBack(pq->sortlist);
}

void *PQPeek(const pq_ty *pq)
{
	assert(!PQIsEmpty(pq));
	assert(pq);
	assert(pq->sortlist);
	
	return SortedListGetData(SortedListEnd(pq->sortlist));
}

int PQIsEmpty(const pq_ty *pq)
{
	assert(pq);
	assert(pq->sortlist);
	
	return SortedListIsEmpty(pq->sortlist);
}

size_t PQSize(const pq_ty *pq)
{
	assert(pq);
	assert(pq->sortlist);
	
	return SortedListSize(pq->sortlist);
}

void PQClear(pq_ty *pq)
{
	while (!PQIsEmpty(pq))
	{
		SortedListRemove(SortedListEnd(pq->sortlist));
	}
}

void *PQErase(pq_ty *pq,
				   int(*match_func)(const void *data1, const void *data2),
				   void *param)
{
	SortedListRemove(SortedListFindIf(SortedListBegin(pq->sortlist),
						SortedListEnd(pq->sortlist), 
									   match_func,
											   param));
}*/
