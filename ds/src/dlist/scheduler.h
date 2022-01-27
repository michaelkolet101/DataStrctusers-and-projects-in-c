/*  API changelog

Version 1.3.1
	* moved the Destroy note to its rightful place
	* added the description in the Run 'Return Value' section
	* added a note in the description of Run:
	"Notes: undefined behavior if called with a running scheduler"
--------------------------------------------------------------------------------
Version 1.3
	* added a note in the description of Destroy:
		"Notes: undefined behavior if called with a running scheduler"
	* renamed the scheduler struct member 'remove_head' to 'remove_curr'
	* added desciption of sched_func_ty function possible return values:
		"must return either 0 for SUCCESS, or 1 for FAIL"
	* changed the return type of Run to 'run_exec_stat_ty' (see the respective enum)		
--------------------------------------------------------------------------------
Version 1.2.3:
	* changed the definition of the return value of the Run function:
		"Return value: -1 if failed, 1 if PQ is empty at the end of a call, 0 otherwise."
--------------------------------------------------------------------------------
Version 1.2.2:
	* changed the return value of the Remove function when it fails from -1 to 1:
		"returns 0 if succeeded, 1 if UID was not found"
--------------------------------------------------------------------------------
Version 1.2.1:
	* changed type of the last argument of Add from 'time_t *' to 'time_t'
--------------------------------------------------------------------------------
Version 1.2:
	* changed the definition of the Run function: 
		"Return value: 1 if PQ is empty at the end of a call, 0 otherwise".
	* changed the complexity of Run to be O(n).
	* added type definition for the scheduler function type (to use in Add)
	* changed the respective argument of the Add function.
--------------------------------------------------------------------------------
Version 1.1: 
	* changed function arguments description of Add, Remove.
	* added description to the Add function - "returning BadUID if failed"
	* changed the definition of the Run function:
		" Return value: number of the tasks still in the scheduler after the 
			end of the run"
	* minor language corrections 
--------------------------------------------------------------------------------
*/


#ifndef __SCHEDULER_H__
#define __SCHEDULER_H__

#include <stddef.h> /*size_t*/

#include "simple_UID.h"

typedef struct scheduler scheduler_ty;

/* must return either 0 for SUCCESS, or 1 for FAIL */
typedef int(*sched_func_ty)(void *params);

typedef enum run_execution_status
{
	FAILED   = -1,
	FINISHED =  0,
	STOPPED  =  1
} run_exec_stat_ty;


/* in src file 
#include "priorityq.h"
#include "task.h"

struct scheduler
{ 
	pq_ty *pq;
	task_ty *curr_task; 
	int should_run;
	int remove_curr; 
};



*/

/******************************************************************************
* Function Description: returns a pointer to scheduler data structure  
* Arguments: none
* Return value: Pointer to scheduler or NULL in case of failure
* Notes: 
* Time Complexity: O(1)
*******************************************************************************/
scheduler_ty *SchedulerCreate();


/******************************************************************************
* Function Description: Ddestroys scheduler data structure, freeing all the 
* memory allocated by it.     
* Arguments: pointer to scheduler data structure.
* Return value: none
* Notes: undefined behavior if called with a running scheduler

* Time Complexity: O(n)
*******************************************************************************/
void SchedulerDestroy(scheduler_ty *scheduler);

/******************************************************************************
* Function Description: adds a task to the given scheduler.
* Arguments: pointer to scheduler data structure, operation function, pointer
* to the parameters object, reschedual time interval.
* Return value: uid of the added scheduler, BadUID if failed
* Notes: 

* Time Complexity: O(n).
*******************************************************************************/
uid_ty SchedulerAdd(scheduler_ty *scheduler,
					sched_func_ty sched_func,
					void *params,
					time_t interval);

/******************************************************************************
* Function Description: removes the task with the given UID.
* Arguments: pointer to scheduler data structure, UID of the task to remove.
* Return value: returns 0 if succeeded, 1 if UID was not found
* Notes: 

* Time Complexity: O(n)
*******************************************************************************/
int SchedulerRemove(scheduler_ty *scheduler, uid_ty uid);


/******************************************************************************
* Function Description: run the scheduler
* Arguments: pointer to scheduler
* Return value: 
	-1 if failed
	 0 if finished
	 1 if stopped (non-empty scheduler in the end of a call)
* Notes: undefined behavior is called with an already running scheduler

* Time Complexity: O(n).
*******************************************************************************/
run_exec_stat_ty SchedulerRun(scheduler_ty *scheduler);


/******************************************************************************
* Function Description: stops the scheduler from running tasks.
* Arguments: pointer to a scheduler data structure
* Return value: none
* Notes: 

* Time Complexity: O(1).
*******************************************************************************/
void SchedulerStop(scheduler_ty *scheduler);


/******************************************************************************
* Function Description: checks if the scheduler is empty.
* Arguments: pointer to a scheduler data structure.
* Return value: 1 empty,  0 non-empty.
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int SchedulerIsEmpty(const scheduler_ty *scheduler);

/******************************************************************************
* Function Description: count number of currently scheduled tasks  
* Arguments: pointer to a scheduler data structure
* Return value: size of the scheduler
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
size_t SchedulerSize(const scheduler_ty *scheduler);

/******************************************************************************
* Function Description: removes all the tasks fron the scheduler 
* Arguments: pointer to a scheduler data structure
* Return value: none 
* Notes: 
*  
* Time Complexity: O(n)
*******************************************************************************/
void SchedulerClear(scheduler_ty *scheduler);



#endif /*__SCHEDULER_H__*/
