#include <stdio.h>


int* IsSumFound(int *array , int len_of_arry ,int sum ,int ret[])
{
	int *start = array;
	int *end = array + len_of_arry;
		
	while (start != end)
	{	
		if ((*start + *end) < sum)
		{	
			++start;
		}
		if ((*start + *end) > sum)
		{
			--end;
		}
		if ((*start + *end) == sum)
		{
			ret[0] = 1;
			ret[1] = *start;
			ret[2] = *end;
			return (int*)ret;		
		
		}
	}
	return 0;		
}	

int main ()
{
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int arr1[3] = {0,0,0};
	int num = 12;
	int len = 9;
	int *result = IsSumFound(arr, len, num, arr1);
	
	printf("%d, %d, %d\n",*result,*(result + 1),*(result + 2)); 
	
	return 0;
}
