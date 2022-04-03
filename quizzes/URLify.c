#include <stdio.h> /*printf*/
#include <string.h>  /*strcmp strcpy*/
#include <stdlib.h> /*malloc free*/
 
void URLify(char *string, char *help_str);

int main(void) 
{ 
 	char string[50] = "aaa bbb ccc";
	char help_str[50] = {'\0'};

	printf("%s\n", help_str);
	URLify(string, help_str);

	if (strcmp(string, "aaa%20bbb%20ccc") == 0) 
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	return(0);			 
}



/*get a string from the user*/
void URLify(char *string, char *help_str) 
{
	
	char *start_string = string;
	char *start_help_str = help_str;

	while (*string != '\0')
	{
		if (*string == ' ')
		{
			*help_str = '%';
			++help_str;
			*help_str = '2';
			++help_str;
			*help_str = '0';
		}
		else
		{
			*help_str = *string;
		}

		++help_str; 
		++string;

	}
	
	strcpy(start_string, start_help_str);
}
