
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/
#include <time.h>


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
static int CompareInt(const void *data1, const void *data2);

static void Welcome();

/***************************service function definitions***********************/

/*void PrintSortedList(pq_ty *sorted_list);*/


void PrintList(pq_ty *sortlist);
/******************************************************************************/
int main(void)
{
	/*Welcome();*/
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
	int n = 15, a = 1, b = 2, c = 3, d = 4;
	int g = 6, i = 0, find_me = 101;
	int r = 0;
	time_t t;
	void *elem = (void *)&n;
	void *elem1 = (void *)&a;
	void *elem2 = (void *)&b;
	void *elem3 = (void *)&c;
	void *elem4 = (void *)&d;
	void *num_to_find = (void *)&find_me;
	srt_iter_ty iter1;
	srt_iter_ty iter10;
	srt_iter_ty iter20;
	
	
	
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
	/* Test for SortedListSize  */
	
/*	if (0 == SortedListSize(p_sort_list))
	{
		puts("SortedListSize" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListSize " RED " FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for SortedListIsEmpty  */
	
/*	if (1 == SortedListIsEmpty(p_sort_list))
	{
		puts("SortedListIsEmpty" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListIsEmpty" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
srand((unsigned) time(&t));	
	/************************************************************************/
	/* Test for SortedListInsert  */
	
/*	SortedListInsert(p_sort_list, elem); 
	SortedListInsert(p_sort_list, elem1);            /*1*/
/*	SortedListInsert(p_sort_list, num_to_find);    /*101*/
/*	SortedListInsert(p_sort_list, elem3);           /*3*/
/*	SortedListInsert(p_sort_list, elem4);			/*4*/
	
/*	PrintList(p_sort_list);
	
	
	
	if (0 == SortedListIsEmpty(p_sort_list))
	{
		puts("SortedListInsert" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListInsert" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
	if (5 == SortedListSize(p_sort_list))
	{
		puts("SortedListInsert" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListInsert " RED " FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for SortedListGetData */
	
/*	g = *((int *)SortedListGetData(SortedListBegin(p_sort_list)));
	
	if (g == 1)
	{
		puts("SortedListGetData" GREEN " SUCCESS"WHITE);
		puts("SortedListBegin" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListGetData FAIL");
		return TEST_FAIL;
	}
	
	
	
	
	/************************************************************************/
	/* Test for SortedListNext */
	
/*	g = *((int *)SortedListGetData(SortedListNext(SortedListBegin(p_sort_list))));
	
	if (g == 3)
	{
		puts("SortedListNext" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListNext FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SortedListPrev */
	
/*	g = *((int *)SortedListGetData(SortedListPrev(SortedListEnd(p_sort_list))));
	
	
	if (g == 101)
	{
		puts("SortedListPrev" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListPrev FAIL");
		return TEST_FAIL;
	}

/************************************************************************/
	/* Test for SortedListRemove */
	
	
/*	SortedListRemove(SortedListNext(SortedListBegin(p_sort_list)));
	
	if (4 == SortedListSize(p_sort_list))
	{
		puts("SortedListRemove" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListRemove " RED " FAIL");
		return TEST_FAIL;
	}
	/*	************************************************************************/
	/* Test for SortedListPopFront */
	
/*	g = *((int *)SortedListPopFront(p_sort_list));
	
	if (3 == SortedListSize(p_sort_list))
	{
		puts("SortedListPopFront" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListPopFront " RED " FAIL");
		return TEST_FAIL;
	}
	
	
	

	if (g == 1)
	{
		puts("SortedListPopFront" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListPopFront FAIL");
		return TEST_FAIL;
	}
	
	/*	**********************************************************************/
	/* Test for SortedListPopBack */
	
/*	g = *((int *)SortedListPopBack(p_sort_list));
	

	if (4 == g)
	{
		puts("SortedListPopBack" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListPopBack " RED " FAIL");
		return TEST_FAIL;
	}
	

	/* Test for SortedListDestroy */
	
	
/*	SortedListDestroy(p_sort_list);
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

static int CompareInt(const void *data1, const void *data2)
{
	return (*(int *)data1 - *(int *)data2);
}

/*
void PrintList(pq_ty *sortlist)
{
	int g = 0;
	srt_iter_ty iter1 = SortedListBegin(sortlist);
	
	
	
	while (!(SortedListIsSameIter(iter1, SortedListEnd(sortlist))))
	{
		g = *((int *)SortedListGetData(iter1));
		
		printf("%d, ", g);
		
		iter1 = SortedListNext(iter1);
	}
		
	printf("\n");
}*/
