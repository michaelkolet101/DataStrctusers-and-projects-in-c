#include <stdio.h>
#include <string.h> 

char *LongestPalindrome(char *string, char *str2);
int IsPolindrom(char *start, char *end); 


int main(void) 
{ 
	char *s = "aabbccbbaa";
	char *str = "babad";
	char ret_str[100] = {'\0'};
	int ans = IsPolindrom(s, s + 10);

	char *ret = LongestPalindrome(str, ret_str);

	if (0 == strcmp(ret, "bab"))
	{
		puts("LongestPalindrome SUCCSES");
	}
	else
	{
		puts("FAIL");
	}

	if (ans == 1)
	{
		puts("IsPolindrom SUCCSES");
	}
	else
	{
		puts("FAIL");
	}


	return(0);
				 
}

int IsPolindrom(char *start, char *end)
{
	char *left = start;
	

	char *right = start + (end - start) - 1;

	while (left <= right)
	{
		if (*left != *right)
		{
			return 0;
		}

		++left;
		--right;
	}
	

	return 1;
}

char *LongestPalindrome(char *string, char *str2)
{
	char *left = string;
	char *right_abs = string + strlen(left) - 1;
	char *curr = right_abs;

	while (left < right_abs)
	{
		while (left != curr)
		{
			if (IsPolindrom(left, curr) == 1 )
			{
				return strncpy(str2, left, curr - left);
			}
			--curr;	
		}
		curr = right_abs;
		++left;
	}
		return NULL;
}