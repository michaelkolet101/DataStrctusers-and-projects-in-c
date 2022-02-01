
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
	int size = 5, i = 0;

	BubbleSort(arr, size);

	for ( i = 0; i < size; ++i)
	{
		printf("%d ,",arr[i]);
	}
	


/*************1***********************************************************/

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






































