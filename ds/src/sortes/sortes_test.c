
#include <stdio.h> /* printf */

#include <stddef.h> /* size_t*/


#include <sys/types.h>


#include "sortes.h" 
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

static test_stat_ty Testsortes(void);


static void Welcome();

/***************************service function definitions***********************/



/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nsortes alocator final test result: %s\n", Testsortes()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty Testsortes(void)
{
	
	int arr[] = {4, 6, 8, 7, 2};
	
	
	printf("%d\n",GetMinimum(5,3));	
	
	printf("%d\n",MinOfArr(arr, 5));
	/*if(NULL == new_pool)
	{
		puts("Failed to create a sortes");
		
		return TEST_FAIL;
	}
	else
	{
		puts("\n Your new_pool is ready to use !!!\n");
	}
	
	
/*************1***********************************************************/
	/* Test for VSPoolAlloc  */
	/*
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
	
	*/
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






































