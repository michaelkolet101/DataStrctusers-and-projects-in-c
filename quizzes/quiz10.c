#include<stdio.h>


int IsPrime(int number);

int main()
{
	int ret = -1;
	int num_to_check = 1;
	
	ret = IsPrime(num_to_check);
	printf("%d\n", ret);
	
     return 0;
}

int IsPrime(int number)
{
	int i = 0;
	
	if (0 == number)
	{
		return 0;
	}
	
	for (i = 2; i < (number / 2); ++ i)
	{
		if (( 0== (number % i)) && (i != number))
		{
			return 0; /*not prime*/
		}
	}
	
    return 1; /*is prime*/
}
