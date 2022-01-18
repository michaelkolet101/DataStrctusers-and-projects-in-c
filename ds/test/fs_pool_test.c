
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
	Welcome();
	printf("\nfix size alocator final test result: %s\n", TestFS_Pool()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty TestFS_Pool(void)
{
	
	void *ptr = NULL;
	
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
		puts("\n Your new_pool is ready to use !!!\n");
	}

/************************************************************************/
	/* Test for FSPoolCalcSize  */
	
	/*printf("%d",FSPoolCalcSize(50, 10));*/
	
	if (508 == FSPoolCalcSize(50, 10))
	{
		puts("FSPoolCalcSize" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("FSPoolCalcSize " RED " FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for FSPoolCountFreeChunks  */
	
	
	if (49 == FSPoolCountFreeChunks(new_pool))
	{
		puts("FSPoolCountFreeChunks" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("FSPoolCountFreeChunks" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for FSPoolAlloc  */
	ptr = FSPoolAlloc(new_pool);
	
	if (48 == FSPoolCountFreeChunks(new_pool))
	{
		puts("FSPoolAlloc" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("FSPoolAlloc" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	/************************************************************************/
	/* Test for FSPoolFree  */
	
	FSPoolFree(new_pool, ptr);
	
	if (49 == FSPoolCountFreeChunks(new_pool))
	{
		puts("FSPoolFree" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("FSPoolFree" RED " FAIL"WHITE);
		return TEST_FAIL;
	}
	
		
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





































