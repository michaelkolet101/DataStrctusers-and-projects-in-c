#ifndef __QUEUE_H__
#define __QUEUE_H__


/*	version 1.2 - QueueEnqueue return value has changed to int instead of status ty.  */

typedef struct queue queue_ty;



/******************************************************************************
* Function Description:  creates new queue data structure
* Arguments: - none	
* Return value: pointer to new queue
* Notes: returns NULL if memory allocation fails

* Time Complexity: O(1)
*******************************************************************************/
queue_ty *QueueCreate(void);

/******************************************************************************
* Function Description:  destroys given queue by freeing the memory allocated by it
* Arguments: - pointer to a queue
* Return value: none
* Notes: if receives null - undefined behaviour.

* Time Complexity: O(n)
*******************************************************************************/
void QueueDestroy(queue_ty *queue);

/******************************************************************************
* Function Description:  insert element to the tail of the queue
* Arguments: - pointer to the queue, pointer to an element
* Return value: 0 = good, 1 = fail.
* Notes: returns FAIL Status if memory allocation failed

* Time Complexity: O(1)
*******************************************************************************/
int QueueEnqueue(queue_ty *queue, void *data);

/******************************************************************************
* Function Description:  remove element from the head of the queue.
* Arguments: - pointer to the queue.
* Return value: -
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
void QueueDequeue(queue_ty *queue);

/******************************************************************************
* Function Description: returns the pointer to the queue's head.
* Arguments: - pointer to the queue
* Return value: pointer to the data. 
* Notes: if the queue is empty - undefined behaviour.

* Time Complexity: O(1)

*******************************************************************************/
void *QueuePeek(const queue_ty *queue);

/******************************************************************************
* Function Description: returns number of elements currently in the queue
* Arguments: - pointer to the queue.
* Return value: non-negative number of elements.
* Notes: 

* Time Complexity: O(n)
*******************************************************************************/
size_t QueueSize(const queue_ty *queue);

/******************************************************************************
* Function Description: returns true is queue is empty, false otherwise
* Arguments: - pointer to the queue
* Return value: int (boolean) with value of either 0 (false) or 1 (true). 
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
int QueueIsEmpty(const queue_ty *queue);

/******************************************************************************
* Function Description: appends one queue to another.
* Arguments: pointers to first and second queue
* Return value: -
* Notes: The second queue will be invalid after this operation.
			   both queue will be merged into the first queue.
			   (create in slist - SlistAppend function);

* Time Complexity: O(1)
*******************************************************************************/
void QueueAppend(queue_ty *first, queue_ty *second);




#endif /*__QUEUE_H__*/
