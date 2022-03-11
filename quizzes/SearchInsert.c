#include <stdio.h> 
 
 
int SearchInsert(int *arr, int size, int data) 
{
	int start = 0;
	int end = size - 1;
	int mid = -1;
	
	while (start <= end)
	{
		mid = (start + end) / 2;
		
		if (arr[mid] == data)
		{
			return mid;
		}

		else if (arr[mid] > data)
		{
			end = mid;
		}
		else
		{
			start = mid + 1;
		}
	}
	return mid;										
}

int main(void) 
{ 
	
	int arr[10] = {1,2,3,4,5,6,7,8,9,10}; 
	int len = 10;
	int elem_to_find = 8;

	if (7 == SearchInsert(arr, len, elem_to_find))
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}

	return(0);				 
}

