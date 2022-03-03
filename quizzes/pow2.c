#include <stdio.h> /*printf*/
#include <math.h> /*pow*/


int IsPowOf2Bitwise(unsigned int number);
int IsPowOf2Loop(unsigned int number); 
long Pow2(unsigned int x, unsigned int y);

void TestOfIsPowOf2Bitwise();
void TestOfPow2();
void TestOfIsPowOf2();

int main(void) 
{ 	
	
	
	


	TestOfPow2();
	TestOfIsPowOf2();
	TestOfIsPowOf2Bitwise();

	return(0);			 
}


void TestOfPow2()
{
	int y = 3;
	int x = 5;

	int res = x * pow(2,y);
	int ret = Pow2(x, y);
	
	if (ret == res)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
}

void TestOfIsPowOf2()
{
	unsigned int num = 8;

	/*check if pow of two*/
	if (IsPowOf2Loop(num))
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	num = 0;

	/*check not pow of two*/
	if (!IsPowOf2Loop(num))
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
}

void TestOfIsPowOf2Bitwise()
{
	unsigned int num = 8;

	/*check if pow of two*/
	if (IsPowOf2Bitwise(num))
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	num = 0;

	/*check not pow of two*/
	if (!IsPowOf2Bitwise(num))
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
}

/*return 1 if the num is pow of 2 using loop*/
int IsPowOf2Loop(unsigned int number)
{
	while ( (number % 2) == 0 && number)
	{
		number /= 2;
	}
	
	return number == 1;
}


int IsPowOf2Bitwise(unsigned int number)
{
	if (!number)
	{
		return 0;
	}
	return (number & (number - 1)) == 0;
}

/*return X * (2^y) useing bitwise*/
long Pow2(unsigned int x, unsigned int y) 
{
	long ret = 0;

	ret = x * (2 << (y - 1));

	return ret;
}

