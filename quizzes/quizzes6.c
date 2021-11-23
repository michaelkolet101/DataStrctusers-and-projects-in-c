#include <stddef.h>
#include <stdio.h>
/*Function maximization test function in stocks*/
int* BiggestProfit(int* prices, int len, int *ret);



int main ()
{
	int i;
	int arr[] ={6, 12, 3, 5, 1, 4, 9, 2};
	int ret[] = {0, 0, 0};
	size_t len = (sizeof(arr) * sizeof(int));
	puts("14");
	BiggestProfit(arr, len, ret);
	puts("16");
	for (i = 0; i < 3; ++i)
	{
		printf("%d\n",ret[i]);
	} 
	
	return 0;
}


/*Function maximization test function in stocks*/
int* BiggestProfit(int* prices, int len, int *ret)
{
	int max;
	int buy, sell;
	int *first = prices, *last = prices + len;	
	puts("32");
	while (first != last)
	{
		if ((*last - *first) > max)
		{
			puts("37");
			max = *last - *first;
			buy = *first;
			sell = *last;		
		}
		else if ((*last - *first) < 0)
		{
			--last;
		}
		
		else if ((*last - *first) > 0 || (*last - *first) == max)
		{
			++first;
		}
	}
	ret[0] = buy;
	ret[1] = sell;
	ret[2] = max;
	return ret;	
}

