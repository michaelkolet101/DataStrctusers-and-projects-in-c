#include <stddef.h>
#include "sortes.h"
#include <stdio.h>


/*1 if first is minimum*/
int IsMinimum(int first, int second);

/*return pointer to the minimum of arr*/
int *MinOfArr(int *arr, int size, int *ret_val);

void Swap(int *first, int *second);


void BubbleSort(int *arr, int size)
{
	
	/*We will define a variable is sorted - flag*/
	int is_sorted = 0;

	/*We will define end, current and next as pointers*/
	int *current = NULL;
	int *next = NULL;
	int *end = arr + size;

	/* LOOP As long as the array is not sorted -> flag = 0*/
	while (0 == is_sorted)
	{
		is_sorted = 1;
		current = arr;
		next = current + 1;

		/*while loop until next = end*/
		while (current != (end - 1))
		{
			/*If next < current, will switch between them and flag = 0 */
			if (1 == IsMinimum(*next, *current))
			{
				Swap(next, current);
				is_sorted = 0;
			}
		
			++next;
			++current;	
		}
	}
	



}

void SelectionSort(int *arr, int size)
{
/*def minimum ,start and end  as pointers */

/*loop while start not end*/

/*find minimum, use the function for it*/

/*swap minimum and start*/

/*Increases start*/
;
}

void InsertionSort(int *arr, int size)
{
	/*Defines variables tmp ,current end  prev as pointers*/
	
	/*A loop while current not end*/
	
		/*Checks if current is smaller than prev*/
		
			/*Copies current to tmp*/
		
			/*loop As long as the value in prev is greater than tmp*/
			
				/*Passes the value in prev to current*/
			
				/*current minus one*/
			
				/*prev minus one*/
;			
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





