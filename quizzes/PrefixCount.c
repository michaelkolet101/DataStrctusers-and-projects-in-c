#include <stdio.h>
#include <string.h> 
 
 
int PrefixCount(char **words, int word_size, char *pref);
int IsSubString(char *string, char* sub_string); 

 int main(void) 
{ 
 	
	char *words[3] = {"ggffgg", "fffff" , "kffkk"};
	char *p = "ff";
	char *str1 = "michael";
	char *str2 = "ae";

	int ans = IsSubString(str1, str2);
	int ans2 = PrefixCount(words, 3, p);
	if (ans == 1)
	{
		puts("IsSubString SUCCSES");
	}
	else
	{
		puts("IsSubString FAIL");
	}
	
	if (ans2 == 3)
	{
		puts("PrefixCount SUCCSES");
	}
	else
	{
		puts("PrefixCount FAIL");
	}
	
	 
	return(0);
				 
}

int  PrefixCount(char **words, int word_size, char *pref) 
{
	int count = 0;
	int i= 0;

	for (i= 0; i < word_size; ++i)
	{
		count += IsSubString(words[i], pref);
	}

	return count;
}

int IsSubString(char *string, char* sub_string)
{
	size_t len_sub = strlen(sub_string); 
	while (*string != '\0')
	{
		/*while ch in string != ch in cub srting++ */
		while (*string != *sub_string )
		{
			++string;
		}
	
		if (0 == strncmp(sub_string,string, len_sub))
		{
			return 1;
		}
	}
	return 0;
	
}