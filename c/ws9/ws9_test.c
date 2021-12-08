#include <stdio.h> /*printf*/
#include <string.h>
#include "ws9.h"


static int TestMemSet();
static int TestMemCpy();
static int TestMemMove();
/*******************************main()***************************************/


int main () 
{
	TestMemSet(); 
	/*	TestMemCpy(); */
	/*	TestMemMove(); */
	return 0;
}

static int TestMemSet()
{
	char str[] = "    you are a big large string with a lot of words inside... ";
	char str2[] = "    you are a big large string with a lot of words inside... ";
	char ch = '-';
	 
	MemSet(str, ch, 15);
	memset(str2, ch, 15);
	
	printf("%s\n",str);
	printf("%s\n",str2);
		
	
	return 0;
}

static int TestMemCpy()
{
	char str[] = " you are..hguggguguguyguy. ";
	char str2[50] = "\0";
	char org[] = " you are..hguggguguguyguy. ";
	char org2[50] = "\0";
	 
	MemCpy(str2, str, 15);
	MemCpy(org2, org, 15);
	printf("%s\n",str2);
	printf("%s\n",org2);
	
	return 0;
}

static int TestMemMove()
{
	char str[] = "    you are a big large string with a lot of words inside... ";
	char str2[] = "    you are a big large string with a lot of words inside... ";
	memmove(str, str + 3, 25);
	MemMove(str2, str2 + 3, 25);
	printf("%s\n",str);
	printf("%s\n",str2);
	
	return 0;
}

