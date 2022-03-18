
#include <stdio.h>
#include <assert.h>
#include <string.h> 
 
 


int LengthOfLastWord(char *string) 
{ 
	int count = 0;
	char *end = string + strlen(string) - 1;

	assert(string);
	while (*end == ' ')
	{
		--end;
	}
	
	while (end > string && *end != ' ')
	{
		++count;
		--end;
	}

	return count;
}



int main(void) 
{ 
 	char *str = "   fly me   to   the moon  ";
	int count = LengthOfLastWord(str);

	printf("%d\n", count);

	return(0);			 
}


