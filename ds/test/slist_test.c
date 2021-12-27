/*******************************************************************************
Data Structures WorkSheet 4: Slist.

Written by: Michael Kolet
Reviewd by: larisa

Tests for WS
*******************************************************************************/

#include <stdio.h>	/* printf */
#include <assert.h>	/* assert */

#include "slist.h"

/* Typedefs: */
typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
test_stat_ty Testslist(void);
/*Service functions*/
int IsMatch(void *a, void *b);


/**************************** Main Function ***********************************/

int main(void)
{
	printf("\nSLIST final test result: %s\n", Testslist()?"FAIL":"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

test_stat_ty Testslist(void)
{
	int n = 10;
	int n2 = 20;
	void *ptr = &n;
	void *ptr2 = &n2;
	void *elem = NULL;
	size_t list_size = 0;
	iterator_ty iter1;
	
	slist_ty *p_slist = SlistCreate();

	/* Test for create a slist */
	
	if(NULL == p_slist)
	{
		puts("Failed to create slist");
		
		return TEST_FAIL;
	}
	else
	{
		puts("Your list is ready to use !!!");
	}

	/************************************************************************/
	/* Test for SlistIsEmpty (after creation the list is empty) */

	if (1 == SlistIsEmpty(p_slist))
	{
		puts("SlistIsEmpty SUCCESS");
	}
	else
	{
		puts("SlistIsEmpty FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for SlistInsertBefore  */
	iter1 = SlistBegin(p_slist);
	/*TODO make every data different*/
	iter1 = SlistInsertBefore(iter1, ptr2); /*20*/
	iter1 = SlistInsertBefore(iter1, ptr);  /*10*/
	iter1 = SlistInsertBefore(iter1, ptr2); /*20*/
	iter1 = SlistInsertBefore(iter1, ptr2); /*20*/
	iter1 = SlistInsertBefore(iter1, ptr);  /*10*/
	iter1 = SlistInsertBefore(iter1, ptr2); /*20*/
	
	list_size = SlistCount(p_slist);
	
	if (6 == list_size)
	{
		puts("SlistInsertBefore SUCCESS");
		puts("SlistCount SUCCESS");
		puts("SlistBegin SUCCESS");
	}
	else
	{
		puts("SlistInsertBefore FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SlistRemove */
	SlistRemove(iter1);
	
	if (5 == (SlistCount(p_slist)))
	{
		puts("SlistRemove SUCCESS");
	}
	else
	{
		puts("SlistRemove FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SlistGetData  TODO check what is in the begin/ next/ end*/
	elem = SlistGetData(iter1);
	
	if (*(int*)elem == 10)
	{
		puts("SlistGetData SUCCESS");
	}
	else
	{
		puts("SlistGetData FAIL");
	}
	
	/************************************************************************/
	/* Test for SlistSetData TODO check what is in the begin/ next/ end */
	
	SlistSetData(iter1, ptr2);
	
	if (SlistGetData(iter1) == ptr2 )
	{
		puts("SlistSetData SUCCESS");
	}
	else
	{
		puts("SlistSetData FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for SlistFind  */
	
	iter1 = SlistFind(SlistBegin(p_slist), Slistend(p_slist), IsMatch, ptr2) ;/*find 20*/
	
	if (iter1.slist_node->data == 20)
	{
		puts("SlistFind SUCCESS");
	}
	else
	{
		puts("SlistFind FAIL");
		return TEST_FAIL;
	}
	
	SlistDestroy(p_slist);
	p_slist = NULL;
	
	return TEST_PASS;
}

int IsMatch(void *data, void *param)
{
	assert(data);
	assert(param);
	
	return !(*(int*)data == *(int*)param);
}










