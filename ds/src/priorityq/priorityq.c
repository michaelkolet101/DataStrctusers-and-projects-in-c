/*******************************************************************************
Data Structures : P_Q->

Written by: Michael Kolet
Reviewd by: shiran

Functions for WS
*******************************************************************************/

#include <stddef.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc, free, sizeof, NULL */

#include "utils.h"
#include "sorted_list.h"
#include "priorityq.h"

#define SUCCESS 0
#define FAIL 1

/* DS: */

struct priorityq
{
	sortlist_ty *sortlist;
};

 /*************************************************************************/
 
pq_ty *PQCreate(int(*cmp_func)(const void *data1, const void *data2))
{
	pq_ty *new_q = {0};
	
	assert(cmp_func);
	
	new_q = malloc(sizeof(pq_ty));
	ALLOC_CHK(new_q, NULL, NULL);
	
	new_q->sortlist = SortedListCreate(cmp_func);
	ALLOC_CHK(new_q->sortlist, new_q, NULL);
	
	return new_q;
}

void PQDestroy(pq_ty *pq)
{
	assert(pq);
	assert(pq->sortlist);
	
	SortedListDestroy(pq->sortlist);
	
	free(pq);
	pq = NULL;
}

int PQEnqueue(pq_ty *pq, const void *data)
{	
	srt_iter_ty runner = {0};
	
	assert(pq);
	assert(pq->sortlist);
	
	runner = SortedListInsert(pq->sortlist, data);

	return SortedListIsSameIter(runner, SortedListEnd(pq->sortlist));
}

void *PQDequeue(pq_ty *pq)
{
	assert(pq);
	assert(pq->sortlist);
	assert(!PQIsEmpty(pq));
	
	return SortedListPopFront(pq->sortlist);
}


void *PQPeek(const pq_ty *pq)
{
	assert(!PQIsEmpty(pq));
	assert(pq);
	assert(pq->sortlist);
	
	return SortedListGetData(SortedListBegin(pq->sortlist));
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
	assert(pq);
	assert(pq->sortlist);
	
	while (!PQIsEmpty(pq))
	{
		PQDequeue(pq);
	}
}

void *PQErase(pq_ty *pq,
			  int(*match_func)(const void *data1, void *param),
			  void *param)
{
	srt_iter_ty match = {0};
	void *data = NULL;
	
	assert(pq);
	assert(pq->sortlist);
	assert(match_func);
	assert(!PQIsEmpty(pq));
	
	/* find the match node */
	match = (SortedListFindIf(SortedListBegin(pq->sortlist), 
		   	 					SortedListEnd(pq->sortlist), 
		   						match_func, param));
	
	if (SortedListIsSameIter(match, SortedListEnd(pq->sortlist)))
	{
		return NULL;
	}
	
	/* save the data of match in data var */
	data = SortedListGetData(match); 
	
	/* remove match */
	SortedListRemove(match);
	
	return data;
	
}
