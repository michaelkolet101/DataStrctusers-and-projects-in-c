#include "ws5.h"

/**********************      TESTS      **************************************/

static int TestLogger();

/*****************************   MAIN   ***************************************/

int main (int argc, char *argv[])
{
	int status = 0;
	
	PrintFunction();
	status = TestLogger(*(argv+1));
	printf("the status of test logger is %d \n",status);
	
	return 0;
}

/*the function test the logger function*/
static int TestLogger(char *file)
{
	int status = 0;
	
	status = Logger(file);
	
	return status;
}






































