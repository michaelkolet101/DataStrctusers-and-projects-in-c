#include <stdlib.h> /*malloc*/
#include "scheduler.h"
#include "priorityq.h"
#include "sorted_list.h"


#include "task.h"
#include "utils.h"
#include "simple_UID.h"

#define SUCCESS 0
#define FAIL 1

struct scheduler
{ 
	pq_ty *pq;
	task_ty *curr_task; /*TODO if the user tries to add a task to the head and 
													might cause infinite loop*/
	int should_run;		/*1 running, 0 stop */
	int remove_curr;  	/*1 - should remove 0 shouldnt TODO if they 
												try to remove the current task*/
};



int ConvertToNegetiv(const task_ty *task1, const task_ty *task2);


scheduler_ty *SchedulerCreate()
{
	/* alloc memory for struct*/
	scheduler_ty *new_scheduler = (scheduler_ty *)malloc(sizeof(scheduler_ty));
	
	/*check alloc */
	ALLOC_CHK(new_scheduler, NULL, NULL);
	
	/*init all struct members*/
	new_scheduler->pq = PQCreate((int(*)(const void *, const void *))&ConvertToNegetiv);
	new_scheduler->curr_task = NULL;
	new_scheduler->should_run = 0;	
	new_scheduler->	remove_curr = 0;
	
	/*return pointer to scheduler_ty*/
	return new_scheduler;
}

/*
void SchedulerDestroy(scheduler_ty *scheduler)
{
	assert(scheduler);
	assert(scheduler->pq);
	
	SchedulerClear(scheduler);
	PQDestroy(scheduler->pq);
	
	free(scheduler);
	scheduler = NULL;
}
*/

uid_ty SchedulerAdd(scheduler_ty *scheduler,
					sched_func_ty sched_func,
					void *params,
					time_t interval)
{
	task_ty *new_task = TaskCreate(sched_func, params, interval);
	if (new_task == NULL)
	{
		return BadUID;
	}
	
	PQEnqueue(scheduler->pq, new_task);
	
	return TaskGetUid(new_task);
}


int SchedulerRemove(scheduler_ty *scheduler, uid_ty uid)
{
	task_ty *task_to_delete = NULL;
	
	task_to_delete = PQErase(scheduler->pq, (int(*)(const void *, void *))TaskMatchUID, &uid);
	
	if (task_to_delete == NULL)
	{
		return FAIL;
	}
	return SUCCESS;
}

run_exec_stat_ty SchedulerRun(scheduler_ty *scheduler)
{
	int repeat = 1;
	uid_ty id = {0};
	int check = SUCCESS;
	
	scheduler->should_run = 1;
	
	/*Check if the scheduler is not empty and the flag is also running*/
	while (!SchedulerIsEmpty(scheduler) && scheduler->should_run)
	{
		scheduler->curr_task = (task_ty *)PQDequeue(scheduler->pq);
		
		/*Check the value of the return from the task to know if to 
													repeat it again*/
		repeat = TaskExecute(scheduler->curr_task);
		
		/*If the task needs to be performed again the time must be 
		updated and re-entered the queue*/
		if (repeat)
		{
			check = TaskUpdateTime(scheduler->curr_task);
			
			PQEnqueue(scheduler->pq, scheduler->curr_task);
		}
		
		if (TaskMatchUID((const task_ty*)scheduler->curr_task, (uid_ty *)&BadUID) || FAILED == check)
		{
			return FAILED;
		}
			
	}	
			
	if (!(scheduler->should_run))
	{
		return STOPPED;
	}
	
	return FINISHED;
}

void SchedulerStop(scheduler_ty *scheduler)
{
	scheduler->should_run = 0;
}

int SchedulerIsEmpty(const scheduler_ty *scheduler)
{
	return PQIsEmpty(scheduler->pq);
}

size_t SchedulerSize(const scheduler_ty *scheduler)
{
	return PQSize(scheduler->pq);
}
/*
void SchedulerClear(scheduler_ty *scheduler)
{
	PQClear(scheduler->pq);
}
*/


int ConvertToNegetiv(const task_ty *task1, const task_ty *task2)
{
	if (TaskIsBefore(task1, task2))
	{
		return -1;
	}
	return 0;
}
