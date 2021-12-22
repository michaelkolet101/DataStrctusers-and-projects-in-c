#include <stdio.h>/*printf*/
#include <stdlib.h>/*sprintf*/

#include "bit_arry.h"

/*****************************************************************************/
static void TestCountOnLut();
static void TestMirrorLut();
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
	TestRotR();
	TestRotL();
	TestMirrorLut();
	TestCountOnLut();
	return 0;
}

/*********************************************************************/

static void TestSetAll()
{
	bit_array_ty num = 0;
	char *string = NULL;
	
	puts("                        SetAll ");
	string = (char*)malloc(sizeof(char) * 64);
	num = SetAll(num);
	string = ToString(num, string);
	printf("%s\n",string);
}

static void TestResetAll()
{
	bit_array_ty num = 149;
	char *string = NULL;
	
	puts("                       ResetAll ");
	string = (char*)malloc(sizeof(char) * 64);
	num = ResetAll(num);
	string = ToString(num, string);
	
	printf("%s\n",string);
}

static void TestToString()
{
	bit_array_ty  num = 149;
	char *string = NULL;
	
	string = (char*)malloc(sizeof(char) * 64);
	
	puts("                       ToString ");
	string = ToString(num, string);
	
	printf("%s\n",string);
}

static void TestSetOn()
{
	
	bit_array_ty bit_arr = (bit_array_ty)0;
	bit_array_ty expected_val = 0x8000000000000000;
	
	puts("                    TestSetOn");
	if (expected_val != SetOn(bit_arr, 63))
	{	
		puts("SUCCSES");	
	}
	else
	{
		puts("FAIL");
	}

}

static void TestSetOff()
{
	bit_array_ty binary = 157, binary1 = 0;
	int number = 4;
	
	binary1 = SetOff(binary, number);
	
	puts("                  TestSetOff");
	
	if (binary1 == 149)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
}

static void TestSetBit()
{
	bit_array_ty binary = 149, binary1 = 0;
	bit_array_ty number = 4;
	bit_array_ty set_to = 1;
	
	puts("                    TestSetBit");
	
	binary1 = SetBit(binary, number, set_to);
	
	if (binary1 == 157)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
}

static void TestGetVal()
{
	bit_array_ty binary = 149, binary1 = 0;
	bit_array_ty number = 4;
	
	binary1 = GetVal(binary, number);
	
	puts("                     TestGetVal");
	
	if (binary1 == 0)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
}

static void TestFlip()
{
	bit_array_ty binary = 157, binary1 = 0;
	int number = 4;
	
	binary1 = Flip(binary, number);
	
	puts("                    TestFlip");
	
	if (binary1 == 149)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
}

static void TestCountOn()
{
	bit_array_ty binary = 159, binary1 = 0;
	
	binary1 = CountOn(binary);
	
	puts("                     TestCountOn");
	
	if (binary1 == 6)
	{
		puts("SUCCSES");
	}
	else
	{
	puts("FAIL");
	}
}

static void TestCountOff()
{
	bit_array_ty binary = 159, binary1 = 0;
	
	binary1 = CountOff(binary);
	
	puts("                      TestCountOff");
	
	if (binary1 == 58)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
}

static void TestMirror()
{
	bit_array_ty binary = 33;
	char *string = NULL;
	char *string1 = NULL;
	
	string = (char*)malloc(sizeof(char) * 64);
	string1 = (char*)malloc(sizeof(char) * 64);
	
	binary = Mirror(binary);
	
	string = ToString(33, string);
	string1 = ToString(binary, string1);
	
	puts("                        Test Mirror ");
	printf("%s\n",string);
	printf("%s\n",string1);
}

static void TestRotR()
{
	bit_array_ty binary = 32 , binary1 = 0;
	
	binary1 = RotR(binary, 3);
	
	puts("                      TestRotR");
	
	if (binary1 == 4)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
}

static void TestRotL()
{
	bit_array_ty binary = 32 , binary1 = 0;
	
	binary1 = RotL(binary, 3);
	
	puts("                        TestRotL");
	
	if (binary1 == 256)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
}

static void TestMirrorLut()
{
    bit_array_ty x = 12456; 
    printf("%lu", MirrorLut(x));     
}

static void TestMirrorLut()
{
    bit_array_ty x = 12456; 
    printf("%lu", MirrorLut(x));     
}

static void TestCountOnLut()
{
	bit_array_ty binary = 159, binary1 = 0;
	
	binary1 = CountOnLut(binary);
	
	puts("                     TestCountOnLut");
	
	if (binary1 == 6)
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
}




