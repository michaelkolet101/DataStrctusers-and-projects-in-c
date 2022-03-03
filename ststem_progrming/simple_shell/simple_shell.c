#include <stdio.h> /*scanf*/


/*LutOfFuncs{ pointers to functions };*/


int SimpleSysShell(void)
{
	/* status = 0 */

    /*char *str*/

	/* while (status != 1)*/

		/* str = fgets input from the user */

		/* status = system(str) */
	
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


