/*******************************************************************************
Data Structures WorkSheet 4: btset.

Written by: Michael Kolet
Reviewd by: larisa

Tests for WS
*******************************************************************************/

#include <stdio.h>	/* printf */
#include <assert.h>	/* assert */

#include "btset.h"
#include "utils.h"

/* Typedefs: */
typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
test_stat_ty Testbtset(void);

/*Service functions*/
int IsMatch(void *a, void *b);

int foo(const void* d1, const void* d2, const void* d3)
{
    return 0;
}
/**************************** Main Function ***********************************/

int main(void)
{
	printf("\nbtset final test result: %s\n", Testbtset()?"FAIL":"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

test_stat_ty Testbtset(void)
{
	int arr[10] = {8,5,4,9,1,2,32,45,32,65};
    int n = 5;
    void *ptr = (void *)&n;
    void *elem ;
    size_t size = 0;
	btset_ty *p_btset = BTSetCreate(foo, ((void *)&n));
    btset_iter_ty test_itr = {NULL};

	/* Test for create a btset */
	
	if(NULL == p_btset)
	{
		puts("Failed to create btset");
		
		return TEST_FAIL;
	}
	else
	{
		puts("Your set is ready to use !!!");
	}

	/************************************************************************/
	/* Test for btsetIsEmpty (after creation the list is empty) */
    
	if (1 == BTSetIsEmpty(p_btset))
	{
		puts("btsetIsEmpty " GREEN "SUCCESS"WHITE);
	}
	else
	{
		puts(RED"btsetIsEmpty FAIL"WHITE);
		return TEST_FAIL;
	}
   

	/************************************************************************/
	/* Test for BTSetInsert */
	BTSetInsert(p_btset, ptr);
	
    if (0 == BTSetIsEmpty(p_btset))
    {
    	puts("BTSetInsert " GREEN "SUCCESS"WHITE);
    }
    else
    {
    	puts(RED"BTSetInsert FAIL"WHITE);
    	return TEST_FAIL;
    }
	
	/************************************************************************/
	/* Test for btsetGetData  TODO check what is in the begin/ next/ end*/
	test_itr = BTSetBegin(p_btset);

    
    ptr = BTSetGetData(test_itr);
    
	if (*(int *)ptr == 5)
	{
		puts("btsetGetData SUCCESS");
	}
	else
	{
		puts("btsetGetData FAIL");
	}
	
	/************************************************************************/
	/* Test for btsetSetData TODO check what is in the begin/ next/ end */
	puts("here test 114");
	size = BTSetSize(p_btset);
	puts("here test 116");
	if (size == 1 )
	{
		puts("BTSetSize SUCCESS");
	}
	else
	{
		puts("BTSetSize FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for btsetFind  */
/*	
	iter1 = btsetFind(btsetBegin(p_btset), btsetend(p_btset), IsMatch, ptr2) ;/*find 20*/
/*	
	if (iter1.btset_node->data == 20)
	{
		puts("btsetFind SUCCESS");
	}
	else
	{
		puts("btsetFind FAIL");
		return TEST_FAIL;
	}
	
	btsetDestroy(p_btset);
	p_btset = NULL;
*/	
	return TEST_PASS;
}

int IsMatch(void *data, void *param)
{
	assert(data);
	assert(param);
	
	return !(*(int*)data == *(int*)param);
}









