#ifndef __STACK_H__
#define __STACK_H__

typedef struct stack stack_ty;

/******************************************************************************
* Function Description: returns a pointer to an empty stack data structure      
* Arguments: size of stack element, capacity of the stack
* Return value: pointer to a stack structure
* Notes: Memory allocation is made inside the function. 
  It is user's responsibility to call 'Destroy' when the ds is no more needed.
  return NULL in case of failure

* Time Complexity: NA
*******************************************************************************/
stack_ty *StackCreate(size_t element_size, size_t capacity);

/******************************************************************************
* Function Description: destroys the structure, by freeing the memory	       
* Arguments: pointer to a stack structure
* Return value: none
* Notes: 

* Time Complexity: NA
*******************************************************************************/
void StackDestroy(stack_ty *stack);

/******************************************************************************
* Function Description: removes the last inserted element from the stack.	       
* Arguments: none, the function is being called an the existing stack instance
* Return value:
* Notes: undefined in case of empty stack

* Time Complexity: NA
*******************************************************************************/
void StackPop(stack_ty *stack);

/******************************************************************************
* Function Description: inserts	an element to the array on the outermost posistion
* Arguments: pointer to the inserted element.
* Return value:
* Notes: undefined if stack is full

* Time Complexity: NA
*******************************************************************************/
void StackPush(stack_ty *stack, const void *elem);

/******************************************************************************
* Function Description: returns the value of the top-most element without popping	       
* Arguments: none
* Return value: pointer to the top-most element.
* Notes: 

* Time Complexity: NA
*******************************************************************************/
void *StackPeek(const stack_ty *stack);

/******************************************************************************
* Function Description: returns the number of stacked elements.	       
* Arguments: 
* Return value: number of elements.
* Notes: 

* Time Complexity: NA
*******************************************************************************/
size_t StackSize(const stack_ty *stack);

/******************************************************************************
* Function Description: returns true if stack is empty, false otherwise.	       
* Arguments: none
* Return value: result of size check
* Notes: 

* Time Complexity: NA
*******************************************************************************/
int StackIsEmpty(const stack_ty *stack);

/******************************************************************************
* Function Description: max capacity of the stack.	       
* Arguments: none
* Return value: number of free slots available
* Notes: 

* Time Complexity: NA
*******************************************************************************/
size_t StackCapacity(const stack_ty *stack);

#endif /*__STACK_H__*/
