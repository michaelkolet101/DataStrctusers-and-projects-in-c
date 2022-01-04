#include <stdio.h> /* printf */
#include <stddef.h> /* size_t*/
#include <unistd.h>/* sleep */

#include "sorted_list.h"
#include "utils.h"

#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
static void Welcome();

/*Service functions*/
static test_stat_ty TestDlist(void);
int IsMatch(const void *data, const void *param);


/**************************** Main Function ***********************************/

int main(void)
{
	
	/*Welcome();*/
	printf("\nSORT LIST final test result: %s\n", TestDlist()?RED"FAIL\n":GREEN"PASS\n");
	
	return 0;
}

/*************************** Test Functions ***********************************/

static test_stat_ty TestDlist(void)
{
	int n = 15, a = 1, b = 2, c = 3, d = 4;
	int g = 6, i = 0, find_me = 101;
	void *elem = (void *)&n;
	void *elem1 = (void *)&a;
	void *elem2 = (void *)&b;
	void *elem3 = (void *)&c;
	void *elem4 = (void *)&d;
	void *num_to_find = (void *)&find_me;
	iterator_ty iter1;
	iterator_ty iter10;
	iterator_ty iter20;
	
	
	sortlist_ty *p_sort_list = SortedListCreate(IsMatch);

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
	
	
	
	/************************************************************************/
	/* Test for SortedListInsert  */
	
	SortedListInsert(p_sort_list, elem );           /*15*/
	SortedListInsert(p_sort_list, elem1);            /*1*/
	SortedListInsert(p_sort_list, num_to_find);    /*101*/
	SortedListInsert(p_sort_list, elem3);           /*3*/
	SortedListInsert(p_sort_list, elem4);			/*4*/
	
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
	
	/*TODO what if i wont to remove the first num in list ?*/
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
	
	if (g == 3)
	{
		puts("SortedListPopFront" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SortedListPopFront FAIL");
		return TEST_FAIL;
	}
	
	/*	************************************************************************/
	/* Test for SortedListPopBack */
	
	g = *((int *)SortedListPopBack(p_sort_list));
	
	printf("%d\n",g);
	if (4 == g)
	{
		puts("SortedListPopBack" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SortedListPopBack " RED " FAIL");
		return TEST_FAIL;
	}
	
/*	************************************************************************/
	
	/* Test for DlistFind */
	
	
	
/*	iter1 = DlistFind(SortedListBegin(p_sort_list),
 					   DlistEnd(p_sort_list), 
					    IsMatch,
					     num_to_find);
					     
	g = *((int *)SortedListGetData(iter1));
					     
	if (101 == g)
	{
		puts("DlistFind" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistFind " RED " FAIL");
		return TEST_FAIL;
	}
	
	
/*	************************************************************************/
	/* Test for DlistMultiFind */
	
/*	g = DlistMultiFind(SortedListBegin(p_sort_list),
 					   DlistEnd(p_sort_list),
 					    p_dest, 
					     IsMatch,
					      elem3);
				      
	if (-1 == g)
	{
		puts("DlistMultiFind" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistMultiFind " RED " FAIL");
		return TEST_FAIL;
	}
	
	
	g = DlistMultiFind(SortedListBegin(p_sort_list),
 					   DlistEnd(p_sort_list),
 					    p_dest, 
					     IsMatch,
					      num_to_find);
			      
	if (1 == g)
	{
		puts("DlistMultiFind" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistMultiFind " RED " FAIL");
		return TEST_FAIL;
	}
	
	/* Test for DlistDestroy */
	
	
/*	DlistDestroy(p_sort_list);
	/************************************************************************/
		
	return TEST_PASS;
}	


int IsMatch(const void *data,const void *param)
{
	return (*(int*)data - *(int*)param);
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






