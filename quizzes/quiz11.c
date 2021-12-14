#include <stdio.h> /*printf*/
#include <stdlib.h>/*malloc*/

long *SumIntPairsToLongs(int ints[], size_t numOfElements);

int main ()
{
	size_t num = 6, i = 0;
	int arr_of_ints[] = {1, 6, 456, -3 ,8 ,12}; 
	long *new_arr = NULL;
	
	new_arr = (long*)malloc(num / 2);
	
	new_arr = SumIntPairsToLongs(arr_of_ints, num);
	
	for (i = 0; i < (num / 2); ++i)
	{
		printf("%lu\n",new_arr[i]);
	}
	
	return 0;
}

long *SumIntPairsToLongs(int ints[], size_t numOfElements)
{
	int i = 0;
	long int *arr_l = (long *)ints;
	
	for (i = 0; i < numOfElements; i += 2)
	{
		arr_l[i / 2] = (long)ints[i] + (long)ints[i + 1];
	}
	
	return arr_l;
}
