#include <stdio.h> /*printf*/
#include <math.h> /*pow*/
#include <stdlib.h>
#include "ws6.h"

#define CHAR_BITS 8/*size of character*/
#define INT_BITS ( sizeof(int) * CHAR_BITS)

static int TestToPow2();
static int TestCheckPowerTwo();
static void TestAddOneToNum();
static void TestOnlyWithTreeBytes();
static void PrintInBinary(unsigned n);
static void TestByteMirrorLoop();
static void TestByteMirrorNoLoop();
static void TestcheckOnBytes();
static void TestcheckOnBytesOr();
static void TestLowerNumberDividedBy16();
static void TestCountBitsOne();
static int Input();
/*******************************main()***************************************/


int main ()
{
	/*TestAddOneToNum();*/
	/*TestToPow2();*/
	/*TestCheckPowerTwo();*/
	/*TestOnlyWithTreeBytes();*/
	/*TestByteMirrorLoop();*/
	/*TestByteMirrorNoLoop();*/
	/*TestcheckOnBytes();*/
	/*TestcheckOnBytesOr();*/
	/*TestLowerNumberDividedBy16();*/
	TestCountBitsOne();
	return 0;
	
}

static int TestToPow2()
{
	unsigned int x = 2, y = 64;
	long int num = 0;
	num = Pow2(x, y);
	printf("%lu\n",num);
	return 0;
}

static int Input()
{
	int num = 0;
	system("clear");
	puts("Enter a number: ");
	scanf("%d",&num);
	
	return num;
}

static int TestCheckPowerTwo()
{
	int n = 0;
	
	n = Input();
	
	n = CheckPowerTwoWithLoop(n);
	/*n = CheckPowerTwo(n);*/
	
	if (n == 1)
	{
		puts("POW OF TWO");
	}
	else
	{
		puts("NOT!!! POW OF TWO");
	}
	return 0;
}

static void TestAddOneToNum()
{
	int number = 0;
	int *ptx = NULL;

	number = Input();
	ptx = &number;
	AddOneToNum(ptx);
	printf("%d\n",number);
}

static void TestOnlyWithTreeBytes()
{
	unsigned int num_arry[] = {1,12,13,15,43,23,65,23,2,7,15,27,31,23,32};
	unsigned int len = 15;
	OnlyWithTreeBytes(num_arry, len);
}

static void TestByteMirrorLoop()
{
	unsigned int n = 0;
	
	n = Input();
	
	PrintInBinary(n);
		
	n = ByteMirrorLoop(n);
	
	PrintInBinary(n);
	
	printf("%d\n", n);
}

static void TestByteMirrorNoLoop()
{
	unsigned int n = 0;
	
	n = Input();
	
	PrintInBinary(n);
		
	n = ByteMirrorNoLoop(n);
	
	PrintInBinary(n);
	
	printf("%d\n", n);
}


static void PrintInBinary(unsigned n)
{
	short int iPos;
	
	for (iPos = (INT_BITS - 1) ; iPos >= 0 ; --iPos)
	{
		(n & (1 << iPos))? printf("1"): printf("0");	
	}
	puts("\n");
}

static void TestcheckOnBytesAnd()
{
	unsigned int n = 0;
	
	n = Input();
	
	PrintInBinary(n);
		
	n = checkOnBytesAnd(n);
	
	printf("%d\n", n);
}

static void TestcheckOnBytesOr()
{
	unsigned int n = 0;
	
	n = Input();
	
	PrintInBinary(n);
		
	n = checkOnBytesOr(n);
	
	printf("%d\n", n);
}

static void TestLowerNumberDividedBy16()
{
	unsigned int n = 0;
	
	n = Input();
	
	n = LowerNumberDividedBy16(n);
	
	printf("%d\n", n);
}

static void TestCountBitsOne()
{
	unsigned int n = 0;
	
	n = Input();
	
	n = CountBitsOne(n);
	
	printf("%d\n", n);
}












