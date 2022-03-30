#include <stdio.h> 
 
 
int ClimbingStairs(int num_of_stairs) 
{
	if (num_of_stairs == 1 || num_of_stairs == 0)
	{
		return 1;
	}

	return ClimbingStairs(num_of_stairs - 1) + ClimbingStairs(num_of_stairs - 2);
	
}

int main(void) 
{ 
 	int s = 5;
	int ways = ClimbingStairs(s);

	if (ways == 8)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}

	return(0);			 
}

