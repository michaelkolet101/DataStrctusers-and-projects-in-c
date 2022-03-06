#include <stdio.h> /*scanf*/
#include <stdlib.h> /*exit */
#include<sys/wait.h> /*system wait*/
#include <unistd.h> /*execv*/ 
#include <string.h>



int CommandHandlerIMP(char *command);

int main()
{
	char input_command[50] = {'\0'};
	char *res = NULL;
	int status = 0;

	while(1)
	{
		memset (input_command, '\0', 50);

		res = fgets(input_command, 50 , stdin);
		
		status = CommandHandlerIMP(input_command);
		

	}

	return 0;
}

int CommandHandlerIMP(char *command)
{
	int status = 0;
	
	if(strcmp(command ,"exit") == 0)
	{
		status = system(command);
	}

	return 1;
}









