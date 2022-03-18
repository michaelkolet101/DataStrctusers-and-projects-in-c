#include <stdio.h> 
 
int IsPalindrome(int num); 
int ReverseInt(int num) ;

int main(void) 
{ 
	int res = IsPalindrome(12345);

	if (res == 0)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	res = IsPalindrome(123321);

	if (res == 1)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}	

	return(0);			 
}

int ReverseInt(int num) 
{ 
	int ret = 0;

	while (0 < num )
	{
		ret = (ret * 10) + (num % 10);
		num = num / 10;
	}
	
	return ret;
}

int IsPalindrome(int num)
{
	return num == ReverseInt(num);
}