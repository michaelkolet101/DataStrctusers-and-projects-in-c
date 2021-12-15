#include <stdio.h> 
#include <assert.h> /* assert */
#include <stdlib.h>/*malloc*/
#include <string.h>/*memcpy*/


#include "stack.h"

#define INT_BITS ( sizeof(int) * CHAR_BITS)
#define CHAR_BITS 8/*size of character*/



/* Definitions */
#define BIT_ARRAY_MSB_MASK (bit_array_ty)0x8000000000000000
#define BIT_ARRAY_LSB_MASK (bit_array_ty)0x0000000000000001
#define BITS_IN_BYTE 8
#define BITS_IN_WORD 64

#define UNUSED(x)	{(void)x;}

struct stack
{
    char *top;
    char *arr;
    size_t elem_size;
    size_t capacity;
} ;
/***************************************************************************/





/***************************************************************************/

/*Function Description: returns a pointer to an empty stack data structure */
stack_ty *StackCreate(size_t element_size, size_t capacity)
{
    stack_ty* new_stack = (stack_ty*)malloc(sizeof(stack_ty));
    if (NULL == new_stack)
    {
    	return NULL;
    }
    
    new_stack->capacity = capacity;
    
    
    new_stack->arr = (char*)malloc(capacity * element_size * sizeof(char));
    
    if (NULL == new_stack->arr)
    {
    	free(new_stack);
    	return NULL;
    }
    
    new_stack->top = new_stack->arr;
    
    return new_stack;
}

void StackDestroy(stack_ty *stack)
{
	assert(stack);
	
	free(stack->arr);
	free(stack);
	
	stack = NULL;
}

void *StackPeek(const stack_ty *stack)
{
	assert(stack);
	
	return (void*)(stack->top - stack->elem_size);
}

void StackPop(stack_ty *stack)
{
	assert(stack);
	
	stack->top = stack->top - stack->elem_size;
}

void StackPush(stack_ty *stack, const void *elem)
{
	assert(stack);
	assert(elem);
	
	stack->top = stack->top + stack->elem_size;
	memcpy(stack->top , elem, stack->elem_size);
	
}

size_t StackSize(const stack_ty *stack)
{
	assert(stack);
	
	return ((stack->top) - (stack->arr)) / (stack->elem_size);
}

/*Stack is empty when top is equal to -1*/
int StackIsEmpty(const stack_ty *stack)
{
	assert(stack);
    return StackSize(stack) == 0;
}

size_t StackCapacity(const stack_ty *stack)
{
	assert(stack);
	return stack->capacity;
}




















