/* version 1.5 function TaskIsMatch changed to TaskMatchUID!!
 * change in this function description: Returns 0 if the UID match the task's
 * UID, 1 otherwise
 * the arguments of this function is now (const task_ty *task, uid_ty *uid)
 * instead of (const task_ty *task, uid_ty uid)
  
/* version 1.4 change description of create function, return value NULL in case
 of failure */
 
 /* version 1.3 changes in struct task, change type of op func from op_func_ty
 * to op_functask_ty in create function, change pointer to time_t to time_t in
 * arguments of create function */
 
 /* version 1.2 change typedef from op_func_ty to op_functask_ty */
 
 /*version 1.1 change description IsBefore func */
 
#ifndef __TASK_H__
#define __TASK_H__

#include <stddef.h> /*size_t*/

#include "simple_UID.h"

typedef struct task task_ty;

/* in src file 
 */

/* returns REPEAT = 1 or DONT_REPEAT = 0 */
typedef int(* op_functask_ty)(void *params);


/******************************************************************************
* Function Description: Creates a new task
* Arguments: operation function, params for the operation function and time
* interval
* Return value: pointer to a new task or NULL in case of failure
* Notes: The first time to run the task is time of creation + interval

* Time Complexity: O(1)
*******************************************************************************/
task_ty *TaskCreate(op_functask_ty op_func, 
					void *params,
					time_t interval);


/******************************************************************************
* Function Description: Destroys the task 
* Arguments: pointer to task 
* Return value: 
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
void TaskDestroy(task_ty *task);


/******************************************************************************
* Function Description: Returns the task UID
* Arguments:  pointer to task 
* Return value:  task UID
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
uid_ty TaskGetUid(const task_ty *task);


/******************************************************************************
* Function Description: Returns 0 if the UID match the task's UID, 
* 1 otherwise
* Arguments: pointer to task and pointer to task UID
* Return value: boolean
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int TaskMatchUID(const task_ty *task, uid_ty *uid);


/******************************************************************************
* Function Description: Executes the task 
* Arguments: pointer to task
* Return value: REPEAT = 1 or DONT_REPEAT = 0 
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int TaskExecute(task_ty *task);


/******************************************************************************
* Function Description: returns the next operation time
* Arguments: pointer to task	
* Return value: next operation time
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
time_t TaskGetTime(const task_ty *task);


/******************************************************************************
* Function Description: updates operation time to current time + interval time
* Arguments: pointer to task
* Return value: returns -1 if fails to fetch current time, 0 otherwise
* Notes: 

* Time Complexity: O(1)
*******************************************************************************/
int TaskUpdateTime(task_ty *task);


/******************************************************************************
* Function Description: Returns a boolean if task2 should be executed before task1
* Arguments: two pointers to tasks to compare
* Return value: 1 if should insert before otherwise 0. 
* Notes: for tasks with the same operation time, the order is undefined

* Time Complexity: O(1)
*******************************************************************************/
int TaskIsBefore(const task_ty *task1, const task_ty *task2);



#endif /*__TASK_H__*/
