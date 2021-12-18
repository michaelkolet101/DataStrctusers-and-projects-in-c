/*******************************************************************************
Data Structures WorkSheet 2: Stack.

Written by: Michael Kolet
Reviewd by: Gabriel Poshumenski

Tests for WS
*******************************************************************************/

#include <stdio.h>	/* printf */
#include <assert.h>	/* assert */

#include "stack.h"

/* Typedefs: */
typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
test_stat_ty TestStack(void);

/**************************** Main Function ***********************************/

int main(void)
{
	printf("\nSTACK final test result: %s\n", TestStack()?"FAIL":"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

test_stat_ty TestStack(void)
{
	size_t num_of_elements = 4;
	size_t size_of_element = sizeof(int);
	int n = 10;
	size_t stack_size = 0;
	stack_ty *p_stack = StackCreate(size_of_element, num_of_elements);
	
	/* Test for create stack */
	
	if(NULL == p_stack)
	{
		puts("Failed to create stack");
		
		return TEST_FAIL;
	}
	else
	{
		puts("Your stack is ready to use");
	}
	
	/************************************************************************/
	/* Test for stack is empty (after creation the stack is empty) */
	
	if (1 == StackIsEmpty(p_stack))
	{
		puts("StackIsEmpty SUCCESS");
	}
	else
	{
		puts("StackIsEmpty FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for stack size (how many elements) */
	if (0 == StackSize(p_stack))
	{
		puts("StackSize SUCCESS");
	}
	
	else
	{
		puts("StackSize FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for push  */
	
	stack_size = StackSize(p_stack);
	StackPush(p_stack, &n);
	StackPush(p_stack, &n);
	StackPush(p_stack, &n);
	
	
	if(3 == (StackSize(p_stack) - stack_size))
	{
		puts("StackPush SUCCESS");
	}
	else
	{
		puts("StackPush FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for peek */
 	
 	StackPush(p_stack, &n);
	
	if (*(int *)StackPeek(p_stack) == n)
	{
		puts("StackPeek SUCCESS");
	}
	else
	{
		puts("StackPeek FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for pop  */
	
	stack_size = StackSize(p_stack);
	StackPop(p_stack);
	
	if(1 == stack_size - StackSize(p_stack))
	{
		puts("StackPop SUCCESS");
	}
	
	else
	{
		puts("StackPop FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for capacity  */
	
	if (StackCapacity(p_stack) ==  num_of_elements)
	{
		puts("StackCapacity SUCCESS");
	}
	
	else
	{
		puts("StackCapacity FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	
	/* Destroy stack: */
	StackDestroy(p_stack);
	
	return TEST_PASS;
}
