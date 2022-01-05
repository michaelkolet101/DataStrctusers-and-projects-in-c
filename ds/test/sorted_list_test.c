
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/
#include <time.h>

#include "dlist.h" 
#include "sorted_list.h"
#include "utils.h"

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
static void Test(void);
static test_stat_ty TestDlist(void);
static int CompareInt(const void *data1, const void *data2);
static int TestSortedListForEach(sortlist_ty *sorted_list);
static int TestSortedListMerge(sortlist_ty *sorted_list);
static void Welcome();

/***************************service function definitions***********************/
int Greater(const void *data, const void *param);
void PrintArrayOfInt(int *nums);
void PrintSortedList(sortlist_ty *sorted_list);
int PrintGreater(void *data, void *param);
static int TestSortedListFind(sortlist_ty *sorted_list);
static int TestSortedListFindIf(sortlist_ty *sorted_list);
int IntGreater(const void *data, void *param);

void PrintList(sortlist_ty *sortlist);
/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nSORT LIST final test result: %s\n", TestDlist()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	Test();
	return 0;
}
/**********************************Definitions*********************************/
static void Test(void)
{
	int nums[] = { 1, 5, 3, 2, 8, 33, 80, 5, 9};
	cmp_func_ty cmp_func = &Greater;
	sortlist_ty *sorted_list = SortedListCreate(cmp_func);
	
	printf("- TestSortedListForEach...........%s\n",F_STATUS(TestSortedListForEach(sorted_list)));
	printf("- TestSortedListFind..............%s\n",F_STATUS(TestSortedListFind(sorted_list)));
	printf("- TestSortedListFindIf............%s\n",F_STATUS(TestSortedListFindIf(sorted_list)));
	printf("- TestSortedListMerge.............%s\n",F_STATUS(TestSortedListMerge(sorted_list)));
	
	SortedListDestroy(sorted_list);
}


static int TestSortedListForEach(sortlist_ty *sorted_list)
{
	int status = 0;
	int param = 5;
	srt_iter_ty iter_start = SortedListBegin(sorted_list);
	srt_iter_ty iter_end = SortedListEnd(sorted_list);
	
	op_func_ty operation = &PrintGreater;
	status = SortedListForEach( iter_start, iter_end, operation, (void*)&param);
	printf("\n");
	return status;
}

static int TestSortedListFind(sortlist_ty *sorted_list)
{
	int status = 0;
	int param = 5;
	srt_iter_ty iter_start = SortedListBegin(sorted_list);
	srt_iter_ty iter_end = SortedListEnd(sorted_list);
		
	iter_start = SortedListFind( sorted_list, iter_start, iter_end, (void*)&param);
	printf("%d\n",(*(int*)SortedListGetData(iter_start)));
	return status;

}

static int TestSortedListFindIf(sortlist_ty *sorted_list)
{
	int status = 0;
	int param = 5;

	srt_iter_ty iter_start = SortedListBegin(sorted_list);
	srt_iter_ty iter_end = SortedListEnd(sorted_list);
		
	iter_start = SortedListFindIf( iter_start, iter_end, IntGreater,(void*)&param);
	printf("%d\n",(*(int*)SortedListGetData(iter_start)));
	return status;

}

static int TestSortedListMerge(sortlist_ty *sorted_list)
{
	int numbers[] = {100,300,0,-2 ,5};
	int i = 0;
	cmp_func_ty cmp_func = &Greater;
	sortlist_ty *second_sorted_list = SortedListCreate(cmp_func);
	
	for(i = 0; i < 5; ++i)
	{
		SortedListInsert(second_sorted_list , (void*)&numbers[i]);
	}
	PrintSortedList(second_sorted_list);
	
	SortedListMerge( sorted_list , second_sorted_list);
	PrintSortedList(sorted_list);
	SortedListDestroy(second_sorted_list);
	return SUCCESS;
}

/***********************service functions*******************************/
int Greater(const void *data, const void *param)
{
	return (*(int*)data - *(int*)param);
}

int IntGreater(const void *data, void *param)
{
	return (((*(int*)data - *(int*)param) >0)? 0:1);
}

void PrintArrayOfInt(int *nums)
{
	int i = 0;
 
	for(i=0; i<INT_ARRAY_SIZE; ++i)
	{	
	 	printf("%d ", nums[i]);
	}
	putchar('\n');
}

void PrintSortedList(sortlist_ty *sorted_list)
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
}

int PrintGreater(void *data, void *param)
{
	if(*(int*)data > *(int*)param)
	{
		printf("%d ->" , *(int*)data); 
		return 0;
	}
	return  -1;
}

static test_stat_ty TestDlist(void)
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
	
	
	
	sortlist_ty *p_sort_list = SortedListCreate(CompareInt);

	/* Test for create a Dlist */
	
	if(NULL == p_sort_list)
	{
		puts("Failed to create a dlist");
		
		return TEST_FAIL;
	}
	else
	{
		
		puts("\n Your dlist is ready to use !!!\n");
	}

/************************************************************************/
	/* Test for SortedListSize  */
	
	if (0 == SortedListSize(p_sort_list))
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
	
	if (1 == SortedListIsEmpty(p_sort_list))
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
	
	SortedListInsert(p_sort_list, elem); 
	SortedListInsert(p_sort_list, elem1);            /*1*/
	SortedListInsert(p_sort_list, num_to_find);    /*101*/
	SortedListInsert(p_sort_list, elem3);           /*3*/
	SortedListInsert(p_sort_list, elem4);			/*4*/
	
	PrintList(p_sort_list);
	
	
	
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
	
	g = *((int *)SortedListGetData(SortedListBegin(p_sort_list)));
	
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
	
	g = *((int *)SortedListGetData(SortedListNext(SortedListBegin(p_sort_list))));
	
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
	
	g = *((int *)SortedListGetData(SortedListPrev(SortedListEnd(p_sort_list))));
	
	
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
	
	
	SortedListRemove(SortedListNext(SortedListBegin(p_sort_list)));
	
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
	
	g = *((int *)SortedListPopFront(p_sort_list));
	
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
	
	g = *((int *)SortedListPopBack(p_sort_list));
	

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
	
	
	SortedListDestroy(p_sort_list);
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


void PrintList(sortlist_ty *sortlist)
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
}
