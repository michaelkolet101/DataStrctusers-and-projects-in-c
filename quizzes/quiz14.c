#include<stdio.h>


int IsBalansed(char * string);

int main()
{
	char str[] = "[()]{[()]}";
	int ret = -1;
	
	ret = IsBalansed(str);
	 
	printf("%d\n", ret);
	
     return 0;
}

int IsBalansed(char * string)
{
	int count1 = 0, count2 = 0, count3 = 0;
	
	if ((*string == '}') || (*string == ']') || (*string == ')')) 
	{
		return 0; /* not balansed */
	}
	
	while (*string != '\0')
	{
		if (*string == '[')
		{
			++count1;
		}
		if (*string == '{')
		{
			++count2;
		}
		if (*string == '(')
		{
			++count3;
		}
		
		if (*string == ']')
		{
			--count1;
		}
		if (*string == '}')
		{
			--count2;
		}
		if (*string == ')')
		{
			--count3;
		}
		
		if (count1 < 0 || count2 < 0 || count3 < 0)
		{
			return 0;
		}
		
		++string;	
	}
	
	if (count1 == 0 && count2 == 0 && count3 == 0)
	{
		return 1;
	}	
					
		return 0;
	}

	
	
	
	
	
	
	
	
	
	
	
	
 
