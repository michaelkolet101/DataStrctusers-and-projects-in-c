#include <stdio.h> /*printf*/
#include <math.h> /*pow*/
#include <stdlib.h>
#include <string.h>
#include "ws9.h"


static int TestMemSet();


/*******************************main()***************************************/


int main ()
{
	TestMemSet();
	
	return 0;
}



static int TestMemSet()
{
	char str[] = "    you are... ";
	int number = 4;
	char ch = '-';
	 
	MemSet(str, ch, 4);
	
	printf("%s\n",str);
		
	
	return 0;
}











