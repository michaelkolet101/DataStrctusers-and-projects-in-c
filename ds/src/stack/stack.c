/*******************************************************************************
Data Structures WorkSheet 2: Stack.

Written by: Michael Kolet
Reviewd by: Gabriel Poshumenski

Functions for WS
*******************************************************************************/

#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc */
#include <string.h>	/* memcpy */

#include "stack.h"

/* Structs: */
struct stack
{
    char *top;
    char *arr;
    size_t elem_size;
    size_t capacity;
};

/******************************************************************************/

/*Function Description: returns a pointer to an empty stack data structure */
stack_ty *StackCreate(size_t element_size, size_t capacity)
{
    stack_ty *new_stack = (stack_ty *)malloc(sizeof(stack_ty));
    
    if (NULL == new_stack)
    {
    	return NULL;
    }
    
    new_stack->arr = (char *)(new_stack + 1) ;
    
    new_stack->capacity = capacity;
    new_stack->elem_size = element_size;
    new_stack->top = new_stack->arr;
    
    return new_stack;
}

/*deleting the stack*/
void StackDestroy(stack_ty *stack)
{	
	assert(stack);
	
	free(stack->arr);
	stack->arr = NULL;

	free(stack);	
	*(&stack) = NULL;
}

/*return the top of the stack to the user*/
void *StackPeek(const stack_ty *stack)
{
	assert(stack);
	
	return (void *)(stack->top);
}

/*delete a element from the top fo the stack */
void StackPop(stack_ty *stack)
{
	assert(stack);
	
	stack->top = stack->top - stack->elem_size;
}

/*insert a element to the stack*/
void StackPush(stack_ty *stack, const void *elem)
{
	assert(stack);
	assert(elem);
	
	memcpy(stack->top ,elem ,stack->elem_size);
	
	stack->top = stack->top + stack->elem_size;
}

/*returns the number of stacked elements */
size_t StackSize(const stack_ty *stack)
{
	assert(stack);
	
	return ((size_t)(stack->top - stack->arr) / (stack->elem_size));
}

/*returns true if stack is empty, false otherwise.*/
int StackIsEmpty(const stack_ty *stack)
{
	assert(stack);
	
    return (StackSize(stack) == 0);
}

/*the return capacity of the stack*/
size_t StackCapacity(const stack_ty *stack)
{
	assert(stack);
	
	return stack->capacity;
}
