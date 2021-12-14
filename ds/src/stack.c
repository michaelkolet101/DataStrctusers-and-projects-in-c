#include <stdio.h> 
#include <assert.h> /* assert */
#include <stdlib.h>/*malloc*/


#include "stack.h"

#define INT_BITS ( sizeof(int) * CHAR_BITS)
#define CHAR_BITS 8/*size of character*/



/* Definitions */
#define BIT_ARRAY_MSB_MASK (bit_array_ty)0x8000000000000000
#define BIT_ARRAY_LSB_MASK (bit_array_ty)0x0000000000000001
#define BITS_IN_BYTE 8
#define BITS_IN_WORD 64

#define UNUSED(x)	{(void)x;}

typedef struct stack
{
	void *top;
	char *arr;
	size_t elem_size;
	size_t capacity;
} stack_ty;

/***************************************************************************/

stack_ty *StackCreate(size_t element_size, size_t capacity)
{
    stack_ty* new_stack = (stack_ty*)malloc(sizeof(stack_ty));
    
    new_stack->capacity = capacity;
    new_stack->top = new_stack->arr;
    new_stack->arr = (char*)malloc(capacity * sizeof(int));
    
    return new_stack;
}
/*
void StackDestroy(stack_ty *stack)
{
	;
}

void StackPop(stack_ty *stack)
{
	;
}

int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
/* Stack is full when top is equal to the last index
int isFull(struct Stack* stack)
{
    return stack->top == stack->capacity - 1;
}
 
// Stack is empty when top is equal to -1
int isEmpty(struct Stack* stack)
{
    return stack->top == -1;
}
 
// Function to add an item to stack.  It increases top by 1
void push(struct Stack* stack, int item)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}
 
// Function to remove an item from stack.  It decreases top by 1
int pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}
 
// Function to return the top from stack without removing it
int peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}
 
// Driver program to test above functions
int main()
{
    struct Stack* stack = createStack(100);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
 
    return 0;
}
*/











