#include <stdio.h> /*printf*/
#include <string.h>
#include "ws10.h"
#include <stdlib.h>

#define SUCCSES 0
#define FAIL 1

/*********************************************************************/

static int TestItoa();
static void TestAtoi();
void TestPrintTwoEqualCharacters();
/*******************************main()***************************************/


int main () 
{
	system("clear");
	TestItoa();
	TestAtoi();
	TestPrintTwoEqualCharacters();
	return 0;
}

static int TestItoa()
{
	int num = 288;
	char str1[50];
	int base = 16;
	char *str = Itoa(num, str1, base);
	
	printf("Itoa prints: %s of %d base\n", str, base);
	
	return 0;
}

static void TestAtoi()
{
	char str[] = "-11F";
	int base = 16;
	int status = 0;
	char str2[] = "13";
	
	if (atoi(str2) == Atoi(str, base))
	{
		status = SUCCSES;
	}
	if (status == SUCCSES)
	{
		puts("Atoi SUCCSES");
	}
	else
	{
		puts("Atoi FAIL");
	}
	
	printf("MY FUNC PRINT : %d for base %d\n",Atoi(str, base), base);
	printf("THE LIBRARY FUNC PRINT: %d of base 10\n",atoi(str2));
}

void TestPrintTwoEqualCharacters()
{
	char a[] = {'a','b','c','d','e','u',};
	char b[] = {'e','d','c','b','f','u',};
	char c[] = {'c','b','t','d','f','h',};
	
	PrintTwoEqualChar(a, b, c, 6, 6, 6);
}













