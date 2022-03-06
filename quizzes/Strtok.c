
#include <stdio.h> /*puts*/ 
#include <string.h> /*strtok strlen*/


/*split stirng to tokens*/ 
char *Strtok(char *str, const char *delim);

void TestStrtok();

 int main(void) 
{ 
 	TestStrtok();
	 return(0);			 
}

char *Strtok(char *str, const char *delim)
{
	char *runner = str;

	while (*runner != '\0')
	{
		if (*runner == *delim)
		{
			*runner = '\0';
		}
		
		++runner;
	}

	return str;
}

void TestStrtok()
{
	char to_split[] = "my name is michael";
	char *space = " ";

	char *my_strtok = Strtok(to_split, space);
	char *lib_strtok = Strtok(to_split, space); 

	if (*my_strtok == *lib_strtok)
	{
		puts("SUCSSES");
	}
	else
	{
		puts("FAIL");
	}

	printf("%s\n", my_strtok);
	printf("%s\n", lib_strtok);
}