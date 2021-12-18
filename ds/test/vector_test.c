/*******************************************************************************
Data Structures WorkSheet 2: Stack.

Written by: Michael Kolet
Reviewd by: Gabriel Poshumenski

Tests for WS
*******************************************************************************/

#include <stdio.h>	/* printf */
#include <assert.h>	/* assert */

#include "../includ/vector.h"

/* Typedefs: */
typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
test_stat_ty TestVector(void);

/**************************** Main Function ***********************************/

int main(void)
{
	printf("\nVECTOR final test result: %s\n", TestVector()?"FAIL":"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

test_stat_ty TestVector(void)
{
	size_t num_of_elements = 10;
	size_t size_of_element = sizeof(int);
	int n = 10;
	void *ptr = &n;
	size_t vector_size = 0;
	vector_ty *p_vector = VectorCreate(size_of_element, num_of_elements);
	void *elem = NULL;
	/* Test for create a vector */
	
	if(NULL == p_vector)
	{
		puts("Failed to create vector");
		
		return TEST_FAIL;
	}
	else
	{
		puts("Your vector is ready to use");
	}

	/************************************************************************/
	/* Test for vector is empty (after creation the vector is empty) */

	if (0 == VectorSize(p_vector))
	{
		puts("VectorSize SUCCESS");
	}
	else
	{
		puts("VectorSize FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for VectorPushBack  */
		
	vector_size = VectorSize(p_vector);
	VectorPushBack(p_vector, ptr);
	VectorPushBack(p_vector, ptr);
	VectorPushBack(p_vector, ptr);
	
	if (3 == (VectorSize(p_vector) - vector_size))
	{
		puts("VectorPushBack SUCCESS");
	}
	else
	{
		puts("VectorPushBack FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for VectorPushBack  */
	VectorPopBack(p_vector);
	
	if (2 == (VectorSize(p_vector) - vector_size))
	{
		puts("VectorPopBack SUCCESS");
	}
	else
	{
		puts("VectorPopBack FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for VectorGetElem  */
	elem = VectorGetElem(p_vector,2);
	if (*(int*)elem == 10)
	{
		puts("VectorGetElem SUCCESS");
	}
	
	/************************************************************************/
	/* Test for VectorCapacity  */
	
	if (VectorCapacity(p_vector) ==  num_of_elements)
	{
		puts("VectorCapacity SUCCESS");
	}
	
	else
	{
		puts("VectorCapacity FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for VectorReserveSize  */
	
	VectorReserveSize(p_vector, 50);
	
	if (VectorCapacity(p_vector) ==  50)
	{
		puts("VectorReserveSize SUCCESS");
	}
	
	else
	{
		puts("VectorReserveSize FAIL");
		return TEST_FAIL;
	}	
	
	/************************************************************************/
	/* Test for VectorShrinkToSize  */
	
	VectorShrinkToSize(p_vector);
	if (VectorCapacity(p_vector) == 2)
	{
		puts("VectorShrinkToSize SUCCESS");
	}
	
	else
	{
		puts("VectorShrinkToSize FAIL");
		return TEST_FAIL;
	}	
	
	/************************************************************************/
	
	/* Destroy vector: */
	VectorDestroy(p_vector);

	return TEST_PASS;
}
