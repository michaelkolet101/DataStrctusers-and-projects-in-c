#include <stdio.h> /*printf*/
 
void PrintArr(int arr[], int len);
int RemoveDuplicates(int nums[], int len) ;


 int main(void) 
{ 
	
	int arr[14] = {1,1,1,2,2,2,3,3,3,4,4,5,5,5};
	int len = 14;
	len = RemoveDuplicates(arr, len);

	PrintArr(arr, len);

	return(0);
}

void PrintArr(int arr[], int len)
{
	while (len != 0)
	{
		printf("%d, ", *arr);
		++arr;
		--len;
	}
	puts(" ");
}

int RemoveDuplicates(int nums[], int len) 
{ 
	int tmp = *nums;
	int indexs = 0;
	int i = 0;

	
	for (i = 0; i < len; ++i)
	{
		if (tmp != nums[i])
		{
			tmp = nums[i];
			++indexs;
			nums[indexs] = tmp;
		}
	}
	return indexs + 1;
}