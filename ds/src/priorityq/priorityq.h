/* version 1.1   ~ Changed the file name to priorityq.h
* 				 ~ no need to include cmp_func inside priorityq struct
*				 ~ Deleted the note about the assert in PQPeek
*				 ~ Added compare function description to PQCreate notes */

/* version 1.2 	 ~ Edited PQErase notes
				 ~ Rephrased compare function description in PQCreate notes*/
				 
/* version 1.3	 ~ PQErase: updated the match_fuc signature to be idntical to
				   the one in SortedListFindIf signature. */

#ifndef __PRIORITYQ_H__
#define __PRIORITYQ_H__

#include <stddef.h> /*size_t*/

#include "sorted_list.h"

typedef struct priorityq pq_ty;

/******************************************************************************
* Function Description: Returns a pointer to an empty priority queue
* DS.   
* Arguments: compare function to determine priority.
* Return value: Pointer to priority queue or NULL in case of failure
* Notes: If cmp_func returns value that is less than, equal to, or greater than
* zero, data2 will have have, respectively, lower priority, equal priority or 
* greater priority than data1.

* Time Complexity: O(1)
*******************************************************************************/
pq_ty *PQCreate\
		(int(*cmp_func)(const void *data1, const void *data2));



/******************************************************************************
* Function Description: Destroys priority queue       
* Arguments: pointer to a priority queue DS.
* Return value: none
* Notes:

* Time Complexity: O(n)
*******************************************************************************/
void PQDestroy(pq_ty *pq);

/******************************************************************************
* Function Description: Enqueue a member holding data in the apropriate
* place according to the cmp_func
* Arguments: pointer to priority queue, void *data to insert.
* Return value: return 0 if success and 1 if fail
* Notes: if the new element has an equal priority to an existing element the 
* order is undefined
* Time Complexity: O(n).
*******************************************************************************/
int PQEnqueue(pq_ty *pq, const void *data);

/******************************************************************************
* Function Description: Removes the member with the highest priority
* Arguments: pointer to priority queue
* Return value: void pointer to the data in the member
* Notes: Removes from an empty queue is undefined
* Time Complexity: O(1).
*******************************************************************************/
void *PQDequeue(pq_ty *pq);

/******************************************************************************
* Function Description: Returns the data of the member with the highest 
* priority
* Arguments: pointer to priority queue
* Return value: void pointer to the data
* Notes: Peek an empty queue is undefined 
* Time Complexity: O(1).
*******************************************************************************/
void *PQPeek(const pq_ty *pq);

/******************************************************************************
* Function Description: return a boolean if the priority queue is empty	       
* Arguments: pointer to a priority queue DS
* Return value: 1 empty 0 not
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int PQIsEmpty(const pq_ty *pq);

/******************************************************************************
* Function Description: count num of elements in priority queue.   
* Arguments: 
* Return value: size of the priority queue
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
size_t PQSize(const pq_ty *pq);

/******************************************************************************
* Function Description: Remove all the elements fron the priority queue.   
* Arguments: pointer to priority queue
* Return value: 
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
void PQClear(pq_ty *pq);

/******************************************************************************
* Function Description: Erase the first occurance with the highest priority
* that matches according to
* match function   
* Arguments: pointer to priority queue, match function and a parameter
* Return value: returns the data that was erased, if there is no match returns
* NULL 
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
void *PQErase(pq_ty *pq,
			  int(*match_func)(const void *data1, void *param),
			  void *param); 
				  

#endif /*__PRIORITYQ_H__*/
