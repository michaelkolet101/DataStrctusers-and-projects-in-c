#include <stddef.h>
#include "sortes.h"
#include <stdio.h>


/*1 if first is minimum*/
int IsMinimum(int first, int second);

/*return pointer to the minimum of arr*/
int *MinOfArr(int *arr, int size, int *ret_val)

void Swap(int *first, int *second);


void BubbleSort(size_t *arr, size_t size)
{
/*We will define a variable is sorted - flag*/

/*We will define end, current and next as pointers*/

/* LOOP As long as the array is not sorted -> flag = 0*/

/*while loop until next = end*/

/*If next < current, will switch between them and flag = 1 */
}

void SelectionSort(size_t *arr, size_t size)
{
/*def minimum ,start and end  as pointers */

/*loop while start not end*/

/*find minimum, use the function for it*/

/*swap minimum and start*/

/*Increases start*/

}

void InsertionSort(size_t *arr, size_t size)
{
	/*Defines variables tmp ,current end  prev as pointers*/
	
	/*A loop while current not end*/
	
	/*Checks if current is smaller than prev*/
	
	/*Copies current to tmp*/
	
	/*As long as the value in prev is greater than tmp*/
	
	/*Passes the value in prev to current*/
	/*current minus one*/
	/*prev minus one*/
	
	/*Exits the loop and copies the tmp into the current*/
}


int IsMinimum(int first, int second)
{
	/*chack if the first is minimum and return*/
	return first < second ? 1 : 0;
}


int *MinOfArr(int *arr, int size, int *ret_val)
{
	/*def Min -> arr first place*/
	int min = *arr;
	int *end = arr + size;
	
	/*def idx = 0*/
	
	int *ret_val = NULL;
	
	/* loop from 1 to size*/
	while (arr != end)
	{
		/*Check if the current is smaller than the previous one*/
		
		if ((*arr) < min)
		{
			/*If yes we will update Min and idx*/
			min = *arr;
			ret_val = arr;
		}
		
		++arr;
	}
	
	/*return idx*/
	return ret_val;
}

void Swap(int *first, int *second)
{
	/*def tmp var*/
	int tmp = 0;
	
	/*use tmp to do the swap*/
	tmp = *first;
	*first = *second;
	*second = tmp; 
}





