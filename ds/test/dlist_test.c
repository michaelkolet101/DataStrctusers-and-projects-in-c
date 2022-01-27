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
int IsMatch(const void *data, void *param);


/**************************** Main Function ***********************************/

int main(void)
{
	
	/*Welcome();*/
	printf("\nDLIST final test result: %s\n", TestDlist()?RED"FAIL\n":GREEN"PASS\n");
	
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
	
	dlist_ty *p_dest = DlistCreate();
	dlist_ty *p_dlist = DlistCreate();

	/* Test for create a Dlist */
	
	if(NULL == p_dlist)
	{
		puts("Failed to create a dlist");
		
		return TEST_FAIL;
	}
	else
	{
		
		puts("\n Your dlist is ready to use !!!\n");
	}

/************************************************************************/
	/* Test for DlistSize  */
	
	if (0 == DlistSize(p_dlist))
	{
		puts("DlistSize" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistSize " RED " FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for DlistIsEmpty  */
	
	if (1 == DlistIsEmpty(p_dlist))
	{
		puts("DlistIsEmpty" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("DlistIsEmpty" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for DlistPushFront  */
	
	DlistPushFront(p_dlist, elem );
	DlistPushFront(p_dlist, elem1);
	DlistPushFront(p_dlist, num_to_find);
	DlistPushFront(p_dlist, elem3);
	DlistPushFront(p_dlist, elem4);
	
	if (0 == DlistIsEmpty(p_dlist))
	{
		puts("DlistPushFront" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("DlistPushFront" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	if (5 == DlistSize(p_dlist))
	{
		puts("DlistPushFront" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistPushFront " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for DlistPushBack  */
/*	
	DlistPushBack(p_dlist, elem );
	
	if (6 == DlistSize(p_dlist))
	{
		puts("DlistPushBack" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistPushBack " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for DlistGetData */
/*	
	g = *((int *)DlistGetData(DlistBegin(p_dlist)));
	
	if (g == d)
	{
		puts("DlistGetData" GREEN " SUCCESS"WHITE);
		puts("DlistBegin" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("DlistGetData FAIL");
		return TEST_FAIL;
	}
	
	
	/************************************************************************/
	/* Test for DlistNext */
/*	
	g = *((int *)DlistGetData(DlistNext(DlistBegin(p_dlist))));
	
	if (g == c)
	{
		puts("DlistNext" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("DlistNext FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for DlistPrev */
/*	
	g = *((int *)DlistGetData(DlistPrev((DlistNext(DlistBegin(p_dlist))))));
	
	
	if (g == d)
	{
		puts("DlistPrev" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("DlistPrev FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for DlistSetData */
/*	
	DlistSetData(DlistBegin(p_dlist), elem3);
	
	g = *((int *)DlistGetData(DlistBegin(p_dlist)));
	
	
	if (g == c)
	{
		puts("DlistSetData" GREEN " SUCCESS"WHITE);
	
	}
	else
	{
		puts("DlistSetData FAIL");
		return TEST_FAIL;
	}
/*	************************************************************************/
	/* Test for DlistInsertBefore */
/*	
	iter1 = DlistBegin(p_dlist);
	iter1 = DlistNext(iter1);
	iter1 = DlistNext(iter1);
	
	iter1 = DlistInsertBefore(iter1, elem);
	
	g = *((int *)DlistGetData(iter1));
	
	if (g == n)
	{
		puts("DlistInsertBefore" GREEN " SUCCESS"WHITE);
	
	}
	else
	{
		puts("DlistInsertBefore FAIL");
		return TEST_FAIL;
	}

/************************************************************************/
	/* Test for DlistRemove */
/*	
	iter1 = DlistRemove(iter1);
	
	if (6 == DlistSize(p_dlist))
	{
		puts("DlistRemove" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistRemove " RED " FAIL");
		return TEST_FAIL;
	}
	/*	************************************************************************/
	/* Test for DlistIsSameIter */
/*	
	iter1 = DlistBegin(p_dlist);
	iter10 = DlistBegin(p_dlist);
	
	for (i = 0; i < 3; ++i)
	{
		iter1 = DlistNext(iter1);
		iter10 = DlistNext(iter10);
	}
	
	g = DlistIsSameIter(iter1 ,iter10);
	
	if (1 == g)
	{
		puts("DlistIsSameIter" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistIsSameIter " RED " FAIL");
		return TEST_FAIL;
	}
	
/*	************************************************************************/
	/* Test for DlistPopFront */
/*	
	elem4 = DlistPopFront(p_dlist);

	if (5 == DlistSize(p_dlist))
	{
		puts("DlistPopFront" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistPopFront " RED " FAIL");
		return TEST_FAIL;
	}
	
	/*	************************************************************************/
	/* Test for DlistPopFront */
/*	
	elem4 = DlistPopBack(p_dlist);

	if (4 == DlistSize(p_dlist))
	{
		puts("DlistPopBack" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistPopBack " RED " FAIL");
		return TEST_FAIL;
	}
	
	/*	************************************************************************/
	/* Test for DlistFind */
/*	
	
	
	iter1 = DlistFind(DlistBegin(p_dlist),
 					   DlistEnd(p_dlist), 
					    IsMatch,
					     num_to_find);
					     
	g = *((int *)DlistGetData(iter1));
					     
	if (101 == g)
	{
		puts("DlistFind" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistFind " RED " FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
/*	************************************************************************/
	/* Test for DlistSplice */
/*
	for (i = 0; i < 50; ++i)
	{
		DlistPushFront(p_dlist, elem );
	}
	
	printf("%ld\n",DlistSize(p_dlist));	
	
	iter10 = DlistBegin(p_dlist);
	iter20 = DlistBegin(p_dlist);
	
	for (i = 0; i < 10; ++i)
	{
		iter10 = DlistNext(iter10);
	}
	
	for (i = 1; i < 20; ++i)
	{
		iter20 = DlistNext(iter20);
	}
		
	iter1 = DlistSplice(iter10, iter20, DlistBegin(p_dest));
	
	printf("%ld\n",DlistSize(p_dlist));
	
	
	if (45 == DlistSize(p_dlist))
	{
		puts("DlistSplice" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("DlistSplice " RED " FAIL");
		return TEST_FAIL;
	}
	
/*	************************************************************************/
	/* Test for DlistMultiFind */
/*	
	g = DlistMultiFind(DlistBegin(p_dlist),
 					   DlistEnd(p_dlist),
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
	
	
	g = DlistMultiFind(DlistBegin(p_dlist),
 					   DlistEnd(p_dlist),
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
	
/*	
	DlistDestroy(p_dlist);
	/************************************************************************/
	
	return TEST_PASS;
}

int IsMatch(const void *data, void *param)
{
	return !(*(int*)data == *(int*)param);
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






