#include <stdio.h> /*printf*/ 
#include <string.h> /*strncmp*/
#include <stdlib.h> /*size_t*/


int Strncmp(const char *s1, const char *s2, size_t n);
void StrncmpTest();


 int main(void) 
{ 
 	StrncmpTest();
	 return(0);
				 
}


void StrncmpTest()
{
	size_t n = 4;
	char *str1 = "michael";
	char *str2 = "michael";
	
	char *str3 = "michael";
	char *str4 = "mibcael";
	
	
	if (Strncmp(str1, str2, n) == strncmp(str1, str2, n))
	{
		puts("SUCSSES");
	}
	else
	{
		puts("FAIL");
	}
	
	if (Strncmp(str3, str4, n) == strncmp(str3, str4, n))
	{
		puts("SUCSSES");
	}
	else
	{
		puts("FAIL");
	}
}

int Strncmp(const char *s1, const char *s2, size_t n) 
{ 
	while ( (*s1 == *s2) && (0 < n) )
	{
		--n;
		++s1;
		++s2;
	}
	return *s1 - *s2;
}