
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

int Printhellow();
int PrintMichael();

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
	id2 = SchedulerAdd(new_Schduler, PrintMichael ,NULL ,1);
	id1 = SchedulerAdd(new_Schduler, Printhellow ,NULL ,4);
	
	
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
	
	if (2 == SchedulerSize(new_Schduler))
	{
		puts("SchedulerSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SchedulerSize" RED " FAIL"WHITE);
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
	/* Test for SchedulerRemove  */
	
	SchedulerRemove(new_Schduler, id1);
	
	if (1 == SchedulerIsEmpty(new_Schduler))
	{
		puts("SchedulerRemove" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("SchedulerRemove " RED " FAIL");
		return TEST_FAIL;
	}
	/************************************************************************/
	/* Test for SchedulerStop */
/*
	
	if (new_Schduler->should_run == 0)
	{
		puts("SchedulerStop" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("SchedulerStop" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for PQPeek */
	
/*	g = *((int *)PQPeek(new_pq));
	
	/*printf("%d\n", g);*/

/*	if (4 == g)
	{
		puts("PQPeek" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("PQPeek " RED " FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for PQClear */
	
/*	PQClear(new_pq);
	
	if (1 == PQIsEmpty(new_pq))
	{
		puts("PQClear" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQClear" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	PQEnqueue(new_pq, elem2);
	PQEnqueue(new_pq, elem1);
	PQEnqueue(new_pq, elem4);
	PQEnqueue(new_pq, elem3);
	PQEnqueue(new_pq, elem3);
	
	if (5 == PQSize(new_pq))
	{
		puts("PQSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	
	/************************************************************************/
	/* Test for PQErase */
/*	PQErase(new_pq, Match, elem3);
	
	if (4 == PQSize(new_pq))
	{
		puts("PQSize" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("PQSize" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	PQDestroy(new_pq);
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

int Printhellow()
{
	static int count = 3;
	
	puts("hellow");
	
	--count;
	
	return !count == 0;
}

int PrintMichael()
{
	static int count = 2;
	
	puts("michael");
	
	--count;
	
	return !count == 0;
}



