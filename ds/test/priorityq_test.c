
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/

#include "priorityq.h"
#include "utils.h"

/*#include "sort_list.h" */

#define F_STATUS(x) x? "FAILED" : "SUCCESS"
#define INT_ARRAY_SIZE 9
enum status
{
	SUCCESS = 0,
	FAILED
};

#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/**********************************Declarations********************************/

static test_stat_ty TestPQ(void);
int Match(const void *data1, void *data2);
int CompareInt(const void *data1, const void *data2);

static void Welcome();

/***************************service function definitions***********************/

/*void PrintSortedList(pq_ty *sorted_list);*/


void PrintList(pq_ty *sortlist);
/******************************************************************************/
int main(void)
{
	Welcome();
	printf("\nP_Q final test result: %s\n", TestPQ()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	return 0;
}
/**********************************Definitions*********************************/



/*void PrintSortedList(pq_ty *sorted_list)
{
	srt_iter_ty iter = SortedListBegin(sorted_list);
	size_t size = SortedListSize(sorted_list);	
	size_t i = 0;
	
	iter = SortedListBegin(sorted_list);
	
	for(i = 0; i < size; ++i)
	{
		printf("%d ", *(int*)SortedListGetData(iter));
		iter = SortedListNext(iter);
	}

	putchar('\n');
}*/


static test_stat_ty TestPQ(void)
{
	int  a = 1, b = 2, c = 3, d = 4;
	int g = 6, i = 0, find_me = 101;
	int r = 0;
	int n = 15;
	
	void *elem = (void *)&n;
	void *elem1 = (void *)&a;
	void *elem2 = (void *)&b;
	void *elem3 = (void *)&c;
	void *elem4 = (void *)&d;
	
	void *num_to_find = (void *)&find_me;
	
	
	
	
	pq_ty *new_pq = PQCreate(CompareInt);

	/* Test for create a Dlist */
	
	if(NULL == new_pq)
	{
		puts("Failed to create a p_q");
		
		return TEST_FAIL;
	}
	else
	{
		
		puts("\n Your list is ready to use !!!\n");
	}

/************************************************************************/
	/* Test for PQEnqueue  */
	
	if (0 == PQEnqueue(new_pq, elem))
	{
		puts("SortedListSize" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListSize " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for PQIsEmpty  */
	
	if (0 == PQIsEmpty(new_pq))
	{
		puts("PQIsEmpty" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQIsEmpty" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for PQSize  */
	
	if (1 == PQSize(new_pq))
	{
		puts("PQSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
	
	PQEnqueue(new_pq, elem2);
	PQEnqueue(new_pq, elem1);
	PQEnqueue(new_pq, elem4);
	PQEnqueue(new_pq, elem3);
	
	
	
	if (5 == PQSize(new_pq))
	{
		puts("PQSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	/************************************************************************/
	/* Test for PQDequeue */
	elem = PQDequeue(new_pq);
	
	if (4 == PQSize(new_pq))
	{
		puts("PQDequeue" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQDequeue" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for PQPeek */
	
	g = *((int *)PQPeek(new_pq));
	
	/*printf("%d\n", g);*/

	if (4 == g)
	{
		puts("PQPeek" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("PQPeek " RED " FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for PQClear */
	
	PQClear(new_pq);
	
	if (1 == PQIsEmpty(new_pq))
	{
		puts("PQClear" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQClear" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	PQEnqueue(new_pq, elem2);
	PQEnqueue(new_pq, elem1);
	PQEnqueue(new_pq, elem4);
	PQEnqueue(new_pq, elem3);
	PQEnqueue(new_pq, elem3);
	
	if (5 == PQSize(new_pq))
	{
		puts("PQSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
	/************************************************************************/
	/* Test for PQErase */
	PQErase(new_pq, Match, elem3);
	
	if (4 == PQSize(new_pq))
	{
		puts("PQSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	PQDestroy(new_pq);
	/************************************************************************/
		
	return TEST_PASS;
}	


static void Welcome()
{
	int i = 0;
	system("clear");
	for (i = 0; i < 2; ++i)
	{
		puts(YELLOW" WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(BLUE"        WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(GREEN"            WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(RED"                   WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(WHITE"                      WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	}
}

int CompareInt(const void *data1,const void *data2)
{
	return (*(int *)data2 - *(int *)data1);
}

int Match(const void *data1, void *data2)
{
	return (*(int *)data2 == *(int *)data1);
}


