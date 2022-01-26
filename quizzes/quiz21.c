#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

size_t SumOfArry(size_t *arr, size_t size);
size_t SumMissingElements(size_t *arr, size_t size, size_t num_of_missing);
size_t GetAvg(size_t sum, size_t count);
size_t FindMissingElements(size_t *arr, size_t size);
size_t IsInArr(size_t *arr, size_t size, size_t num_to_find);

int main ()
{
	size_t arr[] = {1,3,4,5,7};
	size_t size = 5;
	
	FindMissingElements(arr, size);
	printf("%ld\n", IsInArr(arr, size, 8 ));
	return 0;
}


size_t SumOfArry(size_t *arr, size_t size)
{
	size_t sum = 0, i = 0;
	
	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}
	
	return sum;
}

size_t SumMissingElements(size_t *arr, size_t size, size_t num_of_missing)
{
	size_t *new_arr = (size_t *)malloc(sizeof(size_t) * (size + num_of_missing));
	size_t i = 0;
	size_t *runner = new_arr;
	
	for (i = 0; i < size + num_of_missing;  ++i)
	{
		runner[i] = i + 1;
	}	
	
	return SumOfArry(new_arr, (size + num_of_missing)) - SumOfArry(arr, size);
}

size_t GetAvg(size_t sum, size_t count)
{
	return sum/count;
}

size_t FindMissingElements(size_t *arr, size_t size)
{
	size_t sum = 0;
	size_t avg = 0;
	size_t first = 0;
	size_t second = 0;
	
	sum = SumMissingElements(arr, size, 2);
	
	avg = GetAvg(sum, 2);
	
	first = SumMissingElements(arr, avg, 1);
	
	second = sum - first;
	
	printf("%ld  %ld\n", first, second);
	
	return 1;
}

size_t IsInArr(size_t *arr, size_t size, size_t num_to_find)
{
	size_t i = 0;
	size_t ret_val = 0;
	for (i = 0; i < size; ++i)
	{
		ret_val += !(arr[i]^num_to_find);
	}
	
	return ret_val;
}