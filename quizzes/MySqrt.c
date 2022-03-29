#include <assert.h>
#include <stdio.h> 
 
int MySqrt(int num);
int UseFuncSqrt(int num);


int main(void) 
{ 
 	
	int number = 36;

	number = MySqrt(number);

	

	if (number == 6)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	return(0);
				 
}

int MySqrt(int num) 
{ 
	int ret = 0;
	
	while (ret == 0)
	{
		ret = UseFuncSqrt(num);
		--num; 	
	}

	return ret;
}

int UseFuncSqrt(int num)
{
	int i = 1;

	if (num < 4)
	{
		return 1;
	}
	

	for (i = 1; i < num; ++i)
	{
		if ((num / i) == i)
		{
			return i;
		}
	}
	return 0;
}