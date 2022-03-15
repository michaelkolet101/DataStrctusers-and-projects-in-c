#include <sys/ipc.h>
#include <sys/sem.h> 
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

 

int main(void) 
{ 

	char buffer[50] = "\0";

	fgets(buffer, 50, stdin);

	if ( buffer == "exit" )
	{
		exit(0);
	}
    
    /*create a semaphore*/



	return(0);			 
}