#include <stdio.h> 
 
int RemoveElement(int* nums, int numsSize, int val); 
void PrintArr(int *arr, int len); 
void Swap(int *num1, int* num2);

int main(void) 
{ 
 	int arr[8] = {1,2,1,2,1,2,1,2};
	int len = 8;

	PrintArr(arr, len);
	len = RemoveElement(arr, len, 1);

	PrintArr(arr, len);

	 
	return(0);			 
}

int RemoveElement(int* nums, int numsSize, int val)
{
	int ret = 0; 
	int *start = nums;
	int *end = nums + numsSize - 1;
	
	while (start <= end)
	{
		if(*start != val)
		{
			++start;
			++ret;
		}
		else
		{
			Swap(start, end);
			--end;
		}
	}

	return ret;
}


void Swap(int *num1, int* num2)
{
	int tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}


void PrintArr(int *arr, int len)
{
	while (len != 0)
	{
		printf("%d, ", *arr);
		++arr;
		--len;
	}

	puts(" ");
}


