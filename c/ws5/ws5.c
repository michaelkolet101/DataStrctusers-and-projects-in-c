#include <stdio.h>/* scanf printf*/
#include <assert.h>/*assert*/
#include <ctype.h>/*size_t*/

#include "ws5.h"

typedef int(*cmp_ft)(const char* user_input, const char *cmd);
typedef int(*op_ft)(const char* file_path, const char* user_input );

typedef void(*func_ptr)(int number);
/*usefull functions*/



/*******************************************************************/

struct print_me
{
	int number;
	func_ptr func;
};


int main ()
{
	int i = 0;
	struct print_me = malloc( 10 * (sizeof int));
	
	for (i = 0; i < 10; ++i)
	{
		print_me[i].number = i;
		printf("%d\n",print_me[i].number);
	}
	return 0;
}

















