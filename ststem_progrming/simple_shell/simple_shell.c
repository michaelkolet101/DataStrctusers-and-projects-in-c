#include <stdio.h> /*scanf*/
#include <stdlib.h> /*system*/

#define MAX_LEN 50

/*LutOfFuncs{ pointers to functions };*/


int SimpleSysShell(void)
{
	/* status = 0 */
    int status = 0;

    /*char *str*/
    char *input_commend[50] = "\0";

	/* while (status != 1)*/
    while (status != 1)
    {
		/* str = fgets input from the user */
        fgets(input_commend, MAX_LEN, stdin);
		/* status = system(str) */
        status = system
        
    }
    
	/* return status */


	
}




int SimpleForkShell(void)
{
	/*char *str = NULL*/

    /* while (1)*/

		/*str = fgets() input from the user */

		/* Tokenizer(str, char **tokens) */

		/* internal = TokenToInternal(*token)*/

		/* if internal != 0 */

			/* InternalFuncs[internal] */

			/* continue */

		/* status = Execute(tokens) */

		/* return status */
}


void Tokenizer(char *input, char **tokens)
{
	/* while input != '\0' */
		/* *tokens = strtok */
		/* ++tokens */
}


int Execute(char **tokens)
{
	/* fork */
	/* execv(tokens) */
	/* return status */
}



int main(int argc, char const *argv[])
{
	 /* result = strcmp(*(argv + 1), "fork"); */
	 /* if 0 == result */
	 	/* SimpleForkShell() */
	 /* else */
	 	/* SimpleSysShell() */
	 /*return 0; */
}


