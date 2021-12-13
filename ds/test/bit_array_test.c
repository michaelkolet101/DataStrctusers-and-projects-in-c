#include <stdio.h>/*printf*/
#include <stdlib.h>/*sprintf*/

#include "bit_arry.h"

/*****************************************************************************/


static void TestSetAll();
static void TestResetAll();
static void TestToString();
static void TestSetOn();
static void TestSetOff();
static void TestSetBit();
static void TestGetVal();
static void TestFlip();
static void TestCountOn();
static void TestCountOff();
static void TestMirror();
static void TestRotR();
static void TestRotL();
/****************************************************************************/
int main (void)
{
	/*
	TestSetAll();
	TestResetAll();
	TestToString();
	TestSetOn();
	TestSetOff();
	TestSetBit();
	TestGetVal();
	TestFlip();
	TestCountOn();
	TestCountOff();
	TestMirror();
	TestRotR();*/
	TestRotL();
	return 0;
}

/*********************************************************************/

static void TestSetAll()
{
	size_t num = 149;
	
	num = SetAll(num);
	
	printf("%lu\n",num);
}

static void TestResetAll()
{
	size_t num = 149;
	
	num = ResetAll(num);
	
	printf("%lu\n",num);
}

static void TestToString()
{
	size_t  num = 149;
	char *string = NULL;
	
	string = (char*)malloc(sizeof(char) * 64);
	
	string = ToString(num, string);
	
	printf("%s\n",string);
}

static void TestSetOn()
{
	size_t binary = 149, binary1 = 0;
	int number = 4;
	
	binary1 = SetOn(binary, number);
	
	printf("%ld\n",binary1);
}

static void TestSetOff()
{
	size_t binary = 149, binary1 = 0;
	int number = 4;
	
	binary1 = SetOff(binary, number);
	
	printf("%ld\n",binary1);
}

static void TestSetBit()
{
	size_t binary = 149, binary1 = 0;
	int number = 4;
	int set_to = 1;
	
	binary1 = SetBit(binary, number, set_to);
	
	printf("%ld\n",binary1);
}

static void TestGetVal()
{
	size_t binary = 149, binary1 = 0;
	int number = 4;
	
	binary1 = GetVal(binary, number);
	
	printf("%ld\n",binary1);
}

static void TestFlip()
{
	size_t binary = 157, binary1 = 0;
	int number = 4;
	
	binary1 = Flip(binary, number);
	
	printf("%ld\n",binary1);
}

static void TestCountOn()
{
	size_t binary = 159, binary1 = 0;
	
	binary1 = CountOn(binary);
	printf("%ld\n",binary1);
}

static void TestCountOff()
{
	size_t binary = 155, binary1 = 0;
	
	binary1 = CountOff(binary);
	printf("%ld\n",binary1);
}

static void TestMirror()
{
	size_t binary = 1, binary1 = 0;
	
	binary1 = Mirror(binary);
	
	printf("%lu\n",binary1);
}

static void TestRotR()
{
	size_t binary = 32 , binary1 = 0;
	
	binary1 = RotR(binary, 3);
	
	printf("%lu\n",binary1);
}

static void TestRotL()
{
	size_t binary = 32 , binary1 = 0;
	
	binary1 = RotL(binary, 3);
	
	printf("%lu\n",binary1);
}









