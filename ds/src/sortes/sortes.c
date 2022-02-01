#include <stddef.h>
#include "sortes.h"
#include <stdio.h>



int GetMinimum(int first, int second);
int MinOfArr(int *arr, int size);
void Swap(int *first, int *second);


void BubbleSort(size_t *arr, size_t size)
{
/*We will define a variable is sorted*/

/*We will define I*/

/* LOOP As long as the array is not sorted*/

/*A loop that runs through the entire array from 1*/

/*If the current index is the minimum or idx -1 
 if our idx then we will switch between them */
}

void SelectionSort(size_t *arr, size_t size)
{
/*def idx 0*/

/*loop while idx < s	ize*/

/*The SWAP function sends what is obtained to MINOFARR and IDX*/

/*Increases IDX*/

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





