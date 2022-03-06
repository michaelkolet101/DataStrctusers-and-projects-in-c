#include <stdio.h> /*scanf*/
#include <stdlib.h> 
#include<sys/wait.h> /*system wait*/
#include <unistd.h> /*execv*/ 
#include <string.h>

#define MAX_LEN 50


typedef int (*op_func_ty)(void);

enum{FALSE = 0, TRUE = 1};


int SimpleForkShellIMP(void);
int SimpleSysShellIMP(void);
int ExecuteIMP(char *tokens);
int TokenToInternalIMP(char *command);
void TokenizerIMP(char *input);
int ExecuteIMP(char *tokens);
void LogFileIMP(char *massge);



op_func_ty internal_funcs[] = {exit};



int main(int argc, char const *argv[])
{
	 /* result = strcmp(*(argv + 1), "fork"); */

	int result = strcmp(*(argv + 1), "fork");
	int status = 0;

	char input_command[50] = {'\0'};
	
	 /* if 0 == result */
	 if (0 == result)
	 {
	 	/* SimpleForkShell() */
		status = SimpleForkShellIMP();
	 }

	 /* else */
	 else
	 {
	 	/* SimpleSysShell() */
		status = SimpleSysShellIMP();
	 }

	printf("%d\n", status);
	 /*return 0; */
	 return 0;
}

void LogFile(char *message)
{
	FILE *fp; 

	fp = fopen ("error.log", "w"); 
	/*check it*/

	fprintf(fp, message);

	fclose(fp);
}





int SimpleSysShell(void)
{
	/* status = 0 */
    int status = 0;

    /*char *str*/
    char *input_command[50] = {'\0'};

	/* while (status != 1)*/
    while (status != 1)
    {
		/* str = fgets input from the user */
        fgets(input_command, MAX_LEN, stdin);
		/* status = system(str) */
        status = system(input_command);        
    }

	/* return status */
    return status;
}

int SimpleForkShell(void)
{
	/*char *str = NULL*/
	char command[MAX_LEN] = {'\0'};  
	pid_t pid = 0;
	int status_pid = 0;
	int internal = 0;
	int status = 0; 

    /* while (1)*/
	while (TRUE)
	{
		status_pid = fork();
		
		/*hendel error*/
		if (0 > status_pid)
		{
			LogFileIMP("fork fail");
		}
		 
		else 
		{
			
			/*str = fgets() input from the user */
			fgets(command ,MAX_LEN ,stdin);

			/* Tokenizer(str, char *tokens) */
			TokenizerIMP(command);

			if (IsInternal(command))
			{
				/* internal = TokenToInternal(*token)*/
				internal = TokenToInternalIMP(command);
				/* InternalFuncs[internal]*/
				status = internal_funcs[internal]();
			}
			else
			{
				/* status = Execute(tokens) */
				status = ExecuteIMP(command);

			}

			
			
			

			
			
			wait(&status);


			/* return status */
			return status;
		}
	}
}

int TokenToInternalIMP(char *command)
{
	/*return a idx of a dunc from the lut*/
	/*in idx 0 thre is "exit"*/
	return 0;
}

void TokenizerIMP(char *input)
{	
	/* *tokens = strtok */
	input = strtok(input, " ");
}

int ExecuteIMP(char *tokens)
{
	/* fork */
	int status = fork();
	char const *argv = tokens;

	if (0 > status)
	{
		LogFileIMP("fork fail");
	}

	/* execv(tokens) */

	execvp(tokens, argv);

	/* return status */
	exit(0);
}


