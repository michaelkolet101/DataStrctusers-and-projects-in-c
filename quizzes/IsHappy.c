#include <stdio.h> 
#include <math.h>

typedef enum  
{
	FALSE_ = 0,
	TRUE_ = 1
} bool_;
 
static int NumOfDigit(int n);
static int SumPow2Digits(int n);

bool_ IsHappy(int n) 
{
	while (NumOfDigit(n) > 1)
	{
		n = SumPow2Digits(n);
	}
	
	return n == TRUE_;
}

int main(void) 
{ 
	int num = 19;
	
	if (IsHappy(num) == TRUE_)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}

	return(0);			 
}

static int NumOfDigit(int n)
{
	int count = 0;
	
	while (n > 0)
	{
		count += 1;
		n /= 10;	
	}
	
	return count;
}

static int SumPow2Digits(int n)
{
	int sum = 0;

	while (n > 0)
	{
		sum += pow((n % 10), 2)/*(n % 10) * (n % 10)*/;
		n /= 10; 
	}
	
	return sum;
}