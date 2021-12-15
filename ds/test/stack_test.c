#include <stdio.h>/*printf*/
#include <stdlib.h>/*sprintf*/

#include "stack.h"

/*****************************************************************************/



/****************************************************************************/


/*********************************************************************/

int main()
{
    stack_ty *my_stack = StackCreate(4,100);
     int num = 6;
	
    
    if (my_stack)
    {
		StackPush(my_stack, &num);
		StackPush(my_stack, &num);
		StackPush(my_stack, &num);
		puts("works");
    }
  	printf("%d\n",*(int* )StackPeek(my_stack));
  	
 	
    
 
    return 0;
}









