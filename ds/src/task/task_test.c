
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/

#include <time.h> /*time_t*/
#include <sys/types.h>

#include "task.h"
#include "utils.h"
#include "simple_UID.h"


/*#include "sort_list.h" */

#define F_STATUS(x) x? "FAILED" : "SUCCESS"
#define INT_ARRAY_SIZE 9
enum status
{
	SUCCESS = 0,
	FAILED = 1
};

#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/**********************************Declarations********************************/

static test_stat_ty TestTask(void);
int Match(const void *data1, void *data2);
int CompareInt(const void *data1, const void *data2);

int Printhellow();

static void Welcome();

/***************************service function definitions***********************/





/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nTask final test result: %s\n", TestTask()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty TestTask(void)
{
	uid_ty id = {0};
	
	
	
	
	time_t t = time(NULL);
	time_t *ptr_t = &t;
	
	
	
	task_ty *new_task = TaskCreate(Printhellow, NULL, 3);
	
	task_ty *first_task = TaskCreate(Printhellow, NULL, 2);
	task_ty *second_task = TaskCreate(Printhellow, NULL, 10);
	
	/* Test for create a TaskCreate */
	
	if(NULL == new_task)
	{
		puts("Failed to create a Task");
		
		return TEST_FAIL;
	}
	else
	{
		puts("\n Your Task is ready to use !!!\n");
	}
		
	
/************************************************************************/
	/* Test for TaskGetUid  */
	
	
	if (0 == SimpleUIDCmp(TaskGetUid(new_task), BadUID))
	{
		puts("TaskGetUid" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("TaskGetUid " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for TaskMatchUID  */
	
	id = TaskGetUid(new_task);
	
	if (1 == TaskMatchUID(new_task, &id))
	{
		puts("TaskIsMatch" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("TaskMatchUID" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for TaskExecute  */
	
	if (0 == TaskExecute(new_task))
	{
		puts("TaskExecute" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("TaskExecute" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
	/************************************************************************/
	/* Test for TaskGetTime */
	
	
	if (time(NULL) + 3 == TaskGetTime(new_task))
	
	{
		puts("TaskGetTime" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("TaskGetTime" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for TaskUpdateTime */
	
	if (TaskUpdateTime(new_task) == 0)
	
	{
		puts("TaskUpdateTime" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("TaskUpdateTime " RED " FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for TaskIsBefore */
	
	if (1 == TaskIsBefore(first_task, second_task))
	{
		puts("TaskIsBefore" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("TaskIsBefore" RED " FAIL"WHITE);
		return TEST_FAIL;
	}

	TaskDestroy(new_task);
	TaskDestroy(first_task);
	TaskDestroy(second_task);
	/************************************************************************/
	return TEST_PASS;
}


static void Welcome()
{
	int i = 0;
	system("clear");
	for (i = 0; i < 2; ++i)
	{
		puts(YELLOW" WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(BLUE"        WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(GREEN"            WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(RED"                   WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(WHITE"                      WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	}
}

int Printhellow()
{
	puts("hellow");
	
	return 0;
}

