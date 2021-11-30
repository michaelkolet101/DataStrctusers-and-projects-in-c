#include <stdio.h> /*printf*/
#include <math.h> /*pow*/
#include <stdlib.h>
#include "ws6.h"

#define CHAR_BITS 8/*size of character*/
#define INT_BITS ( sizeof(int) * CHAR_BITS)

static int TestToPow2();
static int TestCheckPowerTwo();
static void TestAddOneToNum();
static void TestOnlyWithThreeBytes();
static void PrintInBinary(unsigned char n);
static void TestByteMirrorLoop();
static void TestByteMirrorNoLoop();
/*static void TestcheckOnBytes();*/
static void TestcheckOnBytesOr();
static void TestcheckOnBytesAnd();
static void TestLowerNumberDividedBy16();
static void TestCountBitsOne();
static void TestCountBitsOneOnLoop();
static void TestSwapValNumbers();
static void TestSwapBytes();
static int Input();
/*******************************main()***************************************/


int main ()
{
	/*TestAddOneToNum();*/
	/*TestToPow2();*/
	/*TestCheckPowerTwo();
	TestOnlyWithThreeBytes();
	TestByteMirrorLoop();
	TestByteMirrorNoLoop();
	TestcheckOnBytesAnd();
	TestcheckOnBytesOr();
	TestLowerNumberDividedBy16();
	TestCountBitsOne();
	TestCountBitsOneOnLoop();
	TestSwapValNumbers();
	TestSwapBytes();*/
	
	return 0;
	
}

static int TestToPow2()
{
	unsigned int x = 2, y = 64;
	long int num = 0;
	
	puts("TestToPow2\n");
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
	
	puts("TestCheckPowerTwo\n");
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
	puts("TestAddOneToNum\n");
	ptx = &number;
	AddOneToNum(ptx);
	printf("%d\n",number);
}

static void TestOnlyWithThreeBytes()
{
	unsigned int num_arry[] = {1,12,13,15,43,23,65,23,2,7,15,27,31,23,32};
	unsigned int len = 15;
	puts("TestOnlyWithTreeBytes\n");
	OnlyWithThreeBytes(num_arry, len);
}

static void TestByteMirrorLoop()
{
	unsigned int n = 0;
	
	n = Input();
	puts("TestByteMirrorLoop\n");
	
	PrintInBinary(n);
		
	n = ByteMirrorLoop(n);
	
	PrintInBinary(n);
	
	printf("%d\n", n);
}

static void TestByteMirrorNoLoop()
{
	unsigned int n = 0;
	
	n = Input();
	
	puts("TestByteMirrorNOLoop\n");
	
	PrintInBinary(n);
		
	n = ByteMirrorNoLoop(n);
	
	PrintInBinary(n);
	
	printf("%d\n", n);
}


static void PrintInBinary(unsigned char n)
{
	int index;
	
	for (index = (INT_BITS - 1) ; index >= 0 ; --index)
	{
		(n & (1 << index))? printf("1"): printf("0");	
	}
	puts("\n");
}

static void TestcheckOnBytesAnd()
{
	unsigned int n = 0;
	
	n = Input();
	
	puts("TestcheckOnBytesAnd\n");
	
	PrintInBinary(n);
		
	n = checkOnBytesAnd(n);
	
	printf("%d\n", n);
}

static void TestcheckOnBytesOr()
{
	unsigned int n = 0;
	
	n = Input();
	
	puts("TestcheckOnBytesOr\n");
	
	PrintInBinary(n);
		
	n = checkOnBytesOr(n);
	
	printf("%d\n", n);
}

static void TestLowerNumberDividedBy16()
{
	unsigned int n = 0;
	
	n = Input();
	
	puts("TestLowerNumberDividedBy16\n");
	
	n = LowerNumberDividedBy16(n);
	
	printf("%d\n", n);
}

static void TestCountBitsOne()
{
	unsigned int n = 0;
	
	n = Input();
	
	puts("TestCountBitsOne\n");
	
	n = CountBitsOne(n);
	
	printf("%d\n", n);
}

static void TestCountBitsOneNoLoop()
{
	unsigned int n = 0;
	
	n = Input();
	
	puts("TestCountBitsOneOnLoop()\n");
	
	n = CountBitsOneNoLoop(n);
	
	printf("%d\n", n);
}

static void TestSwapValNumbers()
{
	int x = 5, y = 7;
	
	puts("TestSwapValNumbers\n");
	printf("first %d , second %d\n", x, y);
	SwapValNumbers(&x ,&y);
	printf("first %d , second %d\n", x, y);
}

static void TestSwapBytes()
{
	unsigned char n = '\0';
	
	n = Input();
	
	puts("TestSwapBytes\n");
	
	PrintInBinary(n);	
	
	n = SwapBytes(n);
	
	PrintInBinary(n);
	
	printf("%d\n", n);
}











