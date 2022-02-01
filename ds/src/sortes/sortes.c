#include <stddef.h>
#include "sortes.h"
#include <stdio.h>



int GetMinimum(int first, int second);
int MinOfArr(int *arr, int size);
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
	/*Defines variables i tmp current prev*/
	/*A loop that ran from first place in the array to size*/
	/*Checks if current is smaller than prev*/
	/*Copies current to tmp*/
	/*As long as the value in prev is greater than tmp*/
	/*Passes the value in prev to current*/
	/*current minus one*/
	/*Exits the loop and copies the tmp into the current*/
}


int GetMinimum(int first, int second)
{
	/*ruturn thr nim number*/
	return first > second ? second : first;
}


int MinOfArr(int *arr, int size)
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
		}
		
		++arr;
	}
	
	/*return idx*/
	return min;
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





