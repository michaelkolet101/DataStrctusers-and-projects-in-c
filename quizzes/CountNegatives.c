#include <stdio.h> 
 

int CountNegativInArr(int arr[], int len);

int CountNegatives(int grid[4][4], int gridSize, int gridColSize); 



int main(void) 
{ 
	int grid[4][4] = {
				{4,3,2,-1},
				{3,2,1,-1},
				{1,1,-1,-2},
				{-1,-1,-2,-3}
				};

	

	int ans = CountNegatives(grid, 4, 4);

	if (ans == 8)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	

	return(0);				 
}

int CountNegativInArr(int arr[], int len)
{
	int *curr = arr + len - 1;
	int count = 0;

	while (*curr < 0 && curr >= arr)
	{
		++count;
		--curr;	
	}
	
	return count;
}

int CountNegatives(int grid[4][4], int gridSize, int gridColSize)
{
	int count = 0;
	int i = 0;

	for (i = 0; i < gridSize; ++i)
	{
		count += CountNegativInArr(grid[i] ,gridColSize);
	}

	return count;
}
