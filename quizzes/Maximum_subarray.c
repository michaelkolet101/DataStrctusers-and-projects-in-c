#include <stdio.h>  /*printf*/
#include <assert.h> /*assert*/ 


int MaxSubArray(int *nums, int numsSize);

int main(void) 
{ 
 	int nums[9] = {5,4,-1,7,8};
	int len = 9; 
	int res =  MaxSubArray(nums, len);

	printf("the bigest sum is: %d\n", res);
	return(0);
				 
}

int MaxSubArray(int *nums, int numsSize)
{
	int curr_sum = 0;
	int bigest_sum = 0;
	int i = 0;

	assert(nums);

	for (i = 0; i < numsSize; ++i)
	{
		curr_sum += nums[i];

		if (curr_sum < 0)
		{
			curr_sum = 0;
		}

		if (bigest_sum < curr_sum)
		{
			bigest_sum = curr_sum;
		}
	}
	return bigest_sum;
}