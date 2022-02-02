
#include <stdio.h> /* printf */

#include <stddef.h> /* size_t*/


#include <sys/types.h>


#include "sortes.h" 
#include "utils.h" 
#include <unistd.h>/* sleep */


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

void PrintArr(int *arr, int size);
static void Welcome();

/***************************service function definitions***********************/



/******************************************************************************/
int main(void)
{
	/*Welcome();*/
	printf("\nsortes  final test result: %s\n", Testsortes()?RED"FAIL\n":GREEN"PASS\n"WHITE);
	
	
	return 0;
}
/**********************************Definitions*********************************/

static test_stat_ty Testsortes(void)
{
	
	int arr[] = {5, 3, 1, 7, 2};
	int arr1[] = {40, 60, 80, 70, 20};
	int arr2[] = {400, 600, 900, 700, 200};
	
	int size = 5;
	
	puts(GREEN"BubbleSort"WHITE);
	puts(YELLOW"befor"WHITE);
	PrintArr(arr, size);
	
	BubbleSort(arr, size);
	
	puts(BLUE"after"WHITE);
	PrintArr(arr, size);

	puts(GREEN"SelectionSort"WHITE);
	puts(YELLOW"befor"WHITE);
	PrintArr(arr1, size);

	SelectionSort(arr1, size);
	
	puts(BLUE"after"WHITE);
	PrintArr(arr1, size);

	puts(GREEN"InsertionSort"WHITE);
	puts(YELLOW"befor"WHITE);
	PrintArr(arr2, size);
	InsertionSort(arr2, size);
	puts(BLUE"after"WHITE);
	PrintArr(arr2, size);					

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

void PrintArr(int *arr, int size)
{
	int i = 0;
	for ( i = 0; i < size; ++i)
	{
		printf("%d ,",arr[i]);
	}
	printf("\n\n");
}





























