#include <stdio.h> /*printf*/
#include <math.h> /*pow*/
#include <stdlib.h>
#include "ws8.h"



/*******************************main()***************************************/


int main ()
{
	int a = 4;
	int b = 8;	
	int c = 6;
	
	printf("THE MAX OF 4 AND 8 IS: %d\n",MAX2(a,b));
	
	printf("THE MAX OF 4,8 AND 6 IS: %d\n",MAX3(a,b,c));
	
	printf("the size of b is: %ld\n", SIZEOF_VAR(b));
	
	printf("THE STATUS IS: %d\n" ,Creat());
	
	return 0;
}















