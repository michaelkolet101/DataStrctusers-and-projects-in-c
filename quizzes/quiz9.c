#include<stdio.h>


int MaxSubSum(int *arry_of_nums, int size);

int main()
{
    int a[] = {-2, 1, -3, 4, -1, 3, -5, 4};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = MaxSubSum(a, n);
    
    printf("the big sub sum is %d\n",max_sum);
    return 0;
}

int MaxSubSum(int *arry_of_nums, int size)
{
	int max_total = 0, max = 0;
	int i = 0;
	
	/*loop all over the arry*/
	for (i = 0; i < size; ++i)
	{
		/*Begins to sum the array */
		max = max + arry_of_nums[i];
		
		/*If the largest maximum is smaller than the current maximum*/
		if (max_total < max)
		{
			max_total = max;
		}
		
		if (max < 0)
		{
			max = 0;
		}
	}
	
    return max_total;
}
