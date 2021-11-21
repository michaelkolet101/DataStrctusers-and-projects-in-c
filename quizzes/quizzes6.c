/*Function maximization test function in stocks*/
int* BiggestProfit(int* prices, int len, int *ret)
{
	int max;
	int buy, sell;
	int *first = prices, *last = prices + len;	
	
	while (first != last)
	{
		if ((*last - *first) > max)
		{
			max = *last - *first;
			buy = *first;
			sell = *last;		
		}
		else if ((*last - *first) < 0)
		{
			*last--;
		}
		
		else if ((*last - *first) > 0 || (*last - *first) == max)
		{
			*first++;
		}
	}
	ret[0] = buy;
	ret[1] = sell;
	ret[2] = max;
	return ret;	
}
