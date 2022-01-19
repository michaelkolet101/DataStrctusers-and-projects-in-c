
#include <unistd.h>/* sleep */
#include <stdio.h> /* printf */
#include <stdlib.h>
#include <stddef.h> /* size_t*/

#include <time.h> /*time_t*/
#include <sys/types.h>


#include "vs_pool.h" 
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

static test_stat_ty TestVS_Pool(void);


static void Welcome();

/***************************service function definitions***********************/



/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nVS_Pool alocator final test result: %s\n", TestVS_Pool()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty TestVS_Pool(void)
{
	
	void *ptr = NULL;
	
	void *memory = malloc(500);
	/* Test for create a FS_Pool */
	
	vs_pool_ty *new_pool = VSPoolInit(memory, 500);
	
	if(NULL == new_pool)
	{
		puts("Failed to create a VS_Pool");
		
		return TEST_FAIL;
	}
	else
	{
		puts("\n Your new_pool is ready to use !!!\n");
	}
	
	
/*************1***********************************************************/
	/* Test for VSPoolAlloc  */
	
	ptr = VSPoolAlloc(new_pool, 10);
	
	
	
	if (NULL != ptr)
	{
		puts("VSPoolAlloc" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("VSPoolAlloc " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for VSPoolCalcLargestChunk  */
	
	
	if (484 == VSPoolCalcLargestChunk(new_pool))
	{
		puts("VSPoolCalcLargestChunk" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("VSPoolCalcLargestChunk" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for VSPoolFree  */
/*	VSPoolFree(ptr);
	DefragmentIMP((ptrdiff_t *)new_pool);
	
	printf("%d\n", VSPoolCalcLargestChunk(new_pool));
	if (VSPoolCalcLargestChunk(new_pool) == VSPoolCalcLargestChunk(new_pool))
	{
		puts("VSPoolFree" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("VSPoolFree" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	/************************************************************************/
	
	free(new_pool);
	
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





































