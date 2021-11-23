#include <stdio.h> /*printf*/
#include <stdlib.h>/**/
#include <assert.h>/**/
#include <string.h>/**/

#include "ws5.h"

 
/**********************      TESTS      **************************************/



void TestLogger();



/*******************************main()***************************************/




int main ()
{
	
	/*PrintFunction();*/
	TestLogger();
	return 0;
	
}



void TestLogger()
{
	char *file_name = "/home/michael/michael-kolet/c/ws5/file.txt";
	Logger(file_name);
}







































