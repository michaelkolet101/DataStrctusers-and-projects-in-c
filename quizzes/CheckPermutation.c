#include <stdio.h> 
 
static int CheckPermutation(char *src, char *str); 
static int InStr(char *str, char ch);



int main(void) 
{ 
	char *src = "michael";
	char *str = "icelam";

	if (1 == CheckPermutation(src, str))
	{
		puts("SUCCSES");
	}
	else
	{
		puts("FAIL");
	}
	
	return(0);				 
}

static int CheckPermutation(char *src, char *str) 
{
	while (*str != '\0')
	{
		if ( 0 == InStr(src, *str))
		{
			return 0;
		}
				
		++str;
	}
	return 1;
}

static int InStr(char *str, char ch)
{
	while (*str != '\0')
	{
		if (*str == ch)
		{
			return 1;
		}
		++str;
	}
	return 0;
}