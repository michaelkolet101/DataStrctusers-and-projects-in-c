#include <stdio.h> /*printf*/ 
#include <string.h> /*strstr*/
#include <assert.h> /*assert*/

 
char *Strstr(const char *haystack, const char *needle);


int main(void) 
{ 
 	char *str1 = "michaelkolet";
	char *str2 ="aelko";
	 
	if (Strstr(str1, str2) == strstr(str1, str2))
	{
		puts("succses");
	}
	else
	{
		puts("fail");
	}
	 
	 
	 return(0);
				 
}

char *Strstr(const char *haystack, const char *needle)
{ 
	char *ret = NULL;

	assert(haystack);
	assert(needle);
	
	/*while ch in big str not = to the small*/
	while (*haystack != *needle )
	{
		/*go next in str 1*/
		++haystack;
	}

	ret = (char *)haystack;

	while ('\0' == *needle && *needle == *haystack)
	{
		++needle;
		++haystack;
	}
		
	return ret;
}