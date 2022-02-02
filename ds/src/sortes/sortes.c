#include <stddef.h>
#include <stdio.h>
#include <assert.h>
#include "sortes.h"

/*************************************************************/

/*1 if first is minimum*/
int IsMinimum(int first, int second);

/*return pointer to the minimum of arr*/
int *MinOfArr(int *arr, int size, int *ret_val);

void Swap(int *first, int *second);

/************************************************************/

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
	int *minimum = arr;
	int *start = arr;
	int *end = start + size - 1;
	int count = 0;

	assert(arr);
	
	/*loop while start not end*/
	while (start != end - 1)
	{
		/*find minimum, use the function for it*/
		minimum = MinOfArr(start, size - count, minimum);
	
		/*swap minimum and start*/
		Swap(minimum, start);
			
		/*Increases start*/
		++start;
		++count;		
	}
}

void InsertionSort(int *arr, int size)
{
	/*Defines variables tmp ,current end  prev as pointers*/
	int tmp = 0;
	int *current = arr + 1;
	int *prev = current - 1;
	int *end = current + size - 1;
	int *runner = arr;

	assert(arr);

	/* loop while runner not end*/
	while (runner + 1 != end)
	{
		current = runner + 1;
		prev = current - 1;

		/*Checks if current is smaller than prev*/
		if (*current < *prev)
		{
			/*Copies current to tmp*/
			tmp = *current;

			/*loop As long as the value in prev is greater than tmp*/
			while ((*prev > tmp) && (prev >= arr))
			{
				/*Passes the value in prev to current*/
				*current = *prev;

				/*current minus one*/
				--current;

				/*prev minus one*/
				--prev;
			}
			/*Exits the loop and copies the tmp into the current*/
			*current = tmp;
		}
		++runner;
	}																								
}

/****************************************************************/

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
	
	/* loop arr to end */
	while (arr != end)
	{
		/*Check if the current is smaller than the previous one*/
		if ((*arr) < min)
		{
			/*If yes we will update Min*/
			min = *arr;
			ret_val = arr;
		}
		
		++arr;
	}
	/*return ret val*/
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





