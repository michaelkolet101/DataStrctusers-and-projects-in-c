
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/

#include <time.h> /*time_t*/
#include <sys/types.h>


#include "fs_pool.h" 
#include "utils.h" 



#define INT_ARRAY_SIZE 9


#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/**********************************Declarations********************************/

static test_stat_ty TestFS_Pool(void);


static void Welcome();

/***************************service function definitions***********************/





/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nSchduler final test result: %s\n", TestFS_Pool()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty TestFS_Pool(void)
{
	
	void *memory = malloc(500);
	/* Test for create a FS_Pool */
	
	fsp_ty *new_pool = FSPoolInit(memory, 500, 10);
	
	if(NULL == new_pool)
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
/*	
	id1 = SchedulerAdd(new_pool, Printhello ,NULL ,2);
	id1 = SchedulerAdd(new_pool, PrintMichael ,NULL ,2);
	id3 = SchedulerAdd(new_pool, PrintMichael ,NULL ,2);
	
	if (0 == SchedulerIsEmpty(new_pool))
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
/*	
	if (3 == SchedulerSize(new_pool))
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
/*	SchedulerRemove(new_pool, id3);
	
	if (2 == SchedulerSize(new_pool))
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
	
/*	status = SchedulerRun(new_pool);
	
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
	
/*	SchedulerClear(new_pool);
	
	if (1 == SchedulerIsEmpty(new_pool))
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
	
/*	id1 = SchedulerAdd(new_pool, Printhello ,NULL ,2);
	id1 = SchedulerAdd(new_pool, PrintMichael ,NULL ,2);
	id1 = SchedulerAdd(new_pool, Stop, new_pool, 3);
	id3 = SchedulerAdd(new_pool, PrintMichael ,NULL ,2);
	
	status = SchedulerRun(new_pool);
	
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
/*	SchedulerClear(new_pool);
	SchedulerDestroy(new_pool);
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





































