#include <stdio.h> /*printf*/
#include <stdlib.h> /*malloc free*/ 
#include <string.h> /*strlen*/


static void TestItoA();
static int GetDigit(int num);
static int IsNagativ(int num);

static void ItoA(int num, char *buffer);
static void Swap(char *left, char *right);
static void ReversString(char *str);

 int main(void) 
{ 
	TestItoA();
	return(0); 
}

static void TestItoA()
{
	int num = 112233;
	char string[100] = {'\0'};

	printf("%d\n",num);
	ItoA(num, string);

	printf("%s\n",string);
}

static void ItoA(int num, char *buffer) 
{ 
	int negativ = IsNagativ(num);
	int digit = 0;
	char *curr = buffer;

	if (negativ == 1)
	{
		num = -num;
	}
	
	while (num > 0)
	{
		digit = GetDigit(num);

		*curr = '0' + digit;
		num /= 10;
		++curr;
	}

	if (negativ == 1)
	{
		*curr = '-';
	}

	ReversString(buffer);
}


static int IsNagativ(int num)
{
	return num < 0;
}

static int GetDigit(int num)
{
	return num % 10;
}

static void ReversString(char *str)
{
	char *left = str;
	char *right = str + strlen(str) - 1;

	while (left <= right)
	{
		Swap(left, right);
		++left;
		--right;
	}
}

static void Swap(char *left, char *right)
{
	char tmp = *left;
	*left = *right;
	*right = tmp;
}
