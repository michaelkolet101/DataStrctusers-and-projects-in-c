#include <stdio.h> /*scanf*/
#include <stdlib.h> 
#include<sys/wait.h> /*system wait*/
#include <string.h>

#define MAX_LEN 50

enum{FALSE = 0, TRUE = 1};


int SimpleForkShell(void);
int SimpleSysShell(void);
int Execute(char *tokens);
int TokenToInternal(char *command);
void Tokenizer(char *input);
int Execute(char *tokens);
void LogFileIMP(char *massge);




/*func_ty internal_funcs[1] = {exit} ;*/




int main(int argc, char const *argv[])
{
	 /* result = strcmp(*(argv + 1), "fork"); */
	int result = strcmp(*(argv + 1), "fork");
	int status = 0;

	 /* if 0 == result */
	 if (0 == result)
	 {
	 	/* SimpleForkShell() */
		status = SimpleForkShell();
	 }

	 /* else */
	 else
	 {
	 	/* SimpleSysShell() */
		status = SimpleSysShell();
	 }

	printf("%d\n", status);
	 /*return 0; */
	 return 0;
}

void LogFile(char *massge)
{
	FILE *fp; 

	fp = fopen ("error.log", "w"); 

	fprintf(fp, massge);
}

int SimpleSysShell(void)
{
	/* status = 0 */
    int status = 0;

    /*char *str*/
    char *input_commend[50] = {'\0'};

	/* while (status != 1)*/
    while (status != 1)
    {
		/* str = fgets input from the user */
        fgets(input_commend, MAX_LEN, stdin);
		/* status = system(str) */
        status = system(input_commend);        
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
			LogFileIMP();
		}
		else
		{

			/*str = fgets() input from the user */
			fgets(command ,MAX_LEN ,stdin);

			/* Tokenizer(str, char *tokens) */
			Tokenizer(command);

			/* internal = TokenToInternal(*token)*/
			internal = TokenToInternal(command);

			/* if internal != 0 */
			if ( 0 != internal )
			{
				/* InternalFuncs[internal] */
				/*status = internal_funcs[internal];*/

				/* continue */
				continue;
			}

			/* status = Execute(tokens) */
			status = Execute(command);

			/* return status */
			return status;
		}
	}
}


int TokenToInternal(char *command)
{
	if (*command == internal_funcs[0])
	{
		return 0;
	}

	return -1;
	
}



void Tokenizer(char *input)
{	
	/* *tokens = strtok */
	input = strtok(input, " ");
}


int Execute(char *tokens)
{
	/* fork */
	/* execv(tokens) */
	/* return status */
}


