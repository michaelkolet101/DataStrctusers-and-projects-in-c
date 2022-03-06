#include <stdio.h> 
#include <stdlib.h>


void PrintArrIMP(size_t arr[], size_t len);
void bit_sort(size_t arr[], size_t len);
void SwapIMP(size_t *start, size_t *end);


















		






	

int main(void) 
{ 
	
	size_t arr[6] = {1,0,1,0,1,0};

	bit_sort(arr, 6);

	return(0);
				 
}

void PrintArrIMP(size_t arr[], size_t len)
{
	size_t i = 0;

	for ( i = 0; i <= len; ++i)
	{
		printf("%ld, ",arr[i]);
	}

	puts("\n");
}

void bit_sort(size_t arr[], size_t len) 
{
	size_t *start = arr;
	size_t *end = arr + len - 1;

	while (start < end)
	{
		while (*end == 1)
		{
			--end;
		}
		if (*start != 0)
		{
			SwapIMP(start, end);
			++start;
		}
	}	
}		

void SwapIMP(size_t *start, size_t *end)
{
	size_t tmp = *start;
	*start = *end;
	*end = tmp;
}