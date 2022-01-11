
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/

#include <time.h> /*time_t*/
#include <sys/types.h>

#include "scheduler.h"
#include "task.h"
#include "utils.h"
#include "simple_UID.h"


/*#include "sort_list.h" */

#define F_STATUS(x) x? "FAILED" : "SUCCESS"
#define INT_ARRAY_SIZE 9


#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/**********************************Declarations********************************/

static test_stat_ty TestSchduler(void);
int Match(const void *data1, void *data2);
int CompareInt(const void *data1, const void *data2);

int Printhello();
int PrintMichael();
int Stop(void *data);

static void Welcome();

/***************************service function definitions***********************/





/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nSchduler final test result: %s\n", TestSchduler()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty TestSchduler(void)
{
	
	uid_ty id1 = {0};
	uid_ty id2 = {0};
	uid_ty id3 = {0};
	uid_ty id4 = {0};
	
	run_exec_stat_ty status = FAILED;
	scheduler_ty *new_Schduler = SchedulerCreate();

	/* Test for create a Schduler */
	
	if(NULL == new_Schduler)
	{
		puts("Failed to create a Schduler");
		
		return TEST_FAIL;
	}
	else
	{
		puts("\n Your Schduler is ready to use !!!\n");
	}

/************************************************************************/
	/* Test for SchedulerAdd  */
	
	id1 = SchedulerAdd(new_Schduler, Printhello ,NULL ,2);
	id1 = SchedulerAdd(new_Schduler, PrintMichael ,NULL ,2);
	id3 = SchedulerAdd(new_Schduler, PrintMichael ,NULL ,2);
	
	if (0 == SchedulerIsEmpty(new_Schduler))
	{
		puts("SchedulerAdd" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SchedulerAdd " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SchedulerSize  */
	
	if (3 == SchedulerSize(new_Schduler))
	{
		puts("SchedulerSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SchedulerSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SchedulerRemove  */
	SchedulerRemove(new_Schduler, id3);
	
	if (2 == SchedulerSize(new_Schduler))
	{
		puts("SchedulerRemove" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SchedulerRemove" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	/************************************************************************/
	/* Test for SchedulerRun  */
	
	status = SchedulerRun(new_Schduler);
	
	if (0 == status)
	{
		puts("SchedulerRun" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SchedulerRun" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SchedulerClear  */
	
	SchedulerClear(new_Schduler);
	
	if (1 == SchedulerIsEmpty(new_Schduler))
	{
		puts("SchedulerClear" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SchedulerClear " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for SchedulerStop  */
	
	id1 = SchedulerAdd(new_Schduler, Printhello ,NULL ,2);
	id1 = SchedulerAdd(new_Schduler, PrintMichael ,NULL ,2);
	id1 = SchedulerAdd(new_Schduler, Stop, new_Schduler, 3);
	id3 = SchedulerAdd(new_Schduler, PrintMichael ,NULL ,2);
	
	status = SchedulerRun(new_Schduler);
	
	if (STOPPED == status)
	{
		puts("SchedulerStop" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SchedulerStop" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
/************************************************************************/
	/* Test for SchedulerDestroy  */
	SchedulerClear(new_Schduler);
	SchedulerDestroy(new_Schduler);
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

int CompareInt(const void *data1,const void *data2)
{
	return (*(int *)data2 - *(int *)data1);
}

int Match(const void *data1, void *data2)
{
	return (*(int *)data2 == *(int *)data1);
}

int Printhello()
{
	static int count = 3;
	
	puts("hello");
	
	--count;
	
	return !(count <= 0);
}

int PrintMichael()
{
	static int count = 4;
	
	puts("michael");
	
	--count;
	
	return !(count <= 0);
}

int Stop(void *data)
{
	printf("stop\n");
	SchedulerStop((scheduler_ty *)data);
	
	return 0; 
}




