#include <unistd.h>/* sleep */
#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc free*/
#include <time.h> /*time_t*/
#include <sys/types.h>

/*#include "scheduler.h"*/
#include "task.h"
#include "utils.h"
#include "simple_UID.h"


struct task
{ 
	time_t op_time; 		 /*next time exe op_func */
	op_functask_ty op_func; 
	void *params;
	uid_ty uid;
	time_t time_interval; 	 /*time between func run   */
} ;

task_ty *TaskCreate(op_functask_ty op_func, 
					void *params,
					time_t interval)
{
	time_t now = time(NULL); /*TODO do all the fails checks in first*/
	
	task_ty *new_task = (task_ty *)malloc(sizeof(task_ty));
	ALLOC_CHK(new_task ,NULL, NULL);
	
	if (now < 0)
	{
		free(new_task);
		return NULL;
	}
	
	new_task->op_time = now + interval;
	new_task->op_func = op_func;
	new_task->params = params;
	new_task->time_interval = interval;
	new_task->uid = SimpleUIDCreate();
	
	if (SimpleUIDCmp(new_task->uid, BadUID))/*TODO do all the fails checks in first*/
	{
		return NULL;
		free(new_task);
	}
	
	return new_task;
}

void TaskDestroy(task_ty *task)
{
	assert(task);
	
	free(task);
}

uid_ty TaskGetUid(const task_ty *task)
{
	assert(task);
	
	return task->uid;
}

int TaskMatchUID(const task_ty *task, uid_ty *uid)
{
	assert(task);
	assert(uid);
	
	return SimpleUIDCmp(task->uid , *uid);
}

int TaskExecute(task_ty *task)
{	
	time_t now = time(NULL);
	
	assert(task);
	
	if (now < 0)
	{
		return 1;
	}
	sleep(task->op_time - now);
	
	return task->op_func(task->params);
}

time_t TaskGetTime(const task_ty *task)
{
	assert(task);
	
	return task->op_time;
}

int TaskUpdateTime(task_ty *task)
{
	time_t now = time(NULL);
	
	assert(task);
	
	if (-1 == now)
	{
		return -1;
	}
	
	task->op_time = now + task->time_interval;
	
	return 0;
}

int TaskIsBefore(const task_ty *task1, const task_ty *task2)
{
	assert(task1);
	assert(task2);
	
	return TaskGetTime(task2) > TaskGetTime(task1);/*TODO check the if why its work?*/
}

