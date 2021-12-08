#include <stdio.h> /*printf*/
#include <string.h>
#include "ws10.h"


int TestItoa();
/*******************************main()***************************************/


int main () 
{
	
	TestItoa();
	
	return 0;
}

int TestItoa()
{
	int num = 200;
	char str1[50];
	char *str = Itoa(num, str1, 36);
	
	
	
	
	printf("%s\n", str);
	
	return 0;
}
