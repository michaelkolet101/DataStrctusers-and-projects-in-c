#include <stdio.h>
#include <stdlib.h>
#include <string.h>/**/
#include <assert.h>
#include <ctype.h> /*isspace */
#include <stddef.h> /*size_t*/

#include "ws3.h"

/*****************************StrCmp**************************************/


#define ROWS 2
#define COLS 2

/*int CalcoletRow(iint array[ROWS][COLS])
{
	int i, j;
	int rsum;
	
	for(int i = 0; i < number_of_arrays; i++)   
	    	{
		   rsum = 0;
		   
		   for(int j = 0; j < number_of_element_in_array; j++)
		   {
		       rsum = rsum + arr[i][j];
		   }
        
	}
*/	

/*int* FindTheNextLivingMan(int *arr)
{
	int *ptr_ar = arr;
	
	
	while ((ptr_ar < arr + len) && (*ptr_ar == -1))
	{
		++ptr_ar;
	}
	return arr;
}

void *kill(int *arr, i)
{
	
	
	for (i ; ((i % 100) <= 100); ++i)
		{
			if (arr[i % 100] > 0)
			{
				arr[i % 100] == -1;
			}
		}
}
*/

/*Array printing function*/


/*Function for displaying Joseph's problem python*/
void JosephusProblem()
{
	int arr[10];
	int i;
	int count = 0;
	int len = 10;
	int remain = len;
	
	
	/*Initialize the array*/
	
	
	
	for (i = 0; i < len; ++i)
	{
		arr[i] = 1;
		
	}
	
	while (1 != remain)
	{
	
		if (0 < arr[i] && (count == 1))
		{
			arr[i] = -1;
			count = 0;
			--remain;
		}
		
		else if ((0 < arr[i]) && (0 ==count))
		{
			count = 1;
		}	
		i = (i + 1) % len;
		
	
	}
	
	
	for (i = 0; i < len; ++i)
	{
		if (arr[i] == 1)
		{
			printf("%d\n",i + 1);
		}
		
	}
	
}




static void printarry(int arr[], int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		printf("%d,",arr[i]);
	}
	printf("\n");
}






