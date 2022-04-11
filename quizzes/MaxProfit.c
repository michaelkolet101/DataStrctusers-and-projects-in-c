#include <stdio.h>
#include <assert.h> 
 
 
int MaxProfit(int *prices, int prices_size) 
{
	int max_prof = 0;
	int buy = *prices;
	int sell = 0;

	int *runner = prices;

	assert(prices);

	while (runner < (prices + prices_size))
	{
		if (*runner <= buy)
		{
			buy = *runner;
		}
		else
		{
			sell = *runner;
		}

		if ((sell - buy) > max_prof)
		{
			max_prof = sell - buy;
		}

		++runner;
	}
	
	return max_prof;
}

int main(void) 
{ 
	int prices[6] = {7,1,5,3,6,4};
	int ans = MaxProfit(prices, 6);

	if (ans == 5)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
 	return(0);
				 
}

