#include<stdio.h>


int Find(char *str, size_t len, char ch);

int main()
{
	char str[] = "my name is michael";
	size_t len = sizeof(str);
	int ret;
	
	ret = Find(str, len, 'z');
	 
	printf("%d\n", ret);
	
     return 0;
}

int Find(char *str, size_t len, char ch)
{	
	size_t index = 0;
	
	while ((index < len) && (*(str + index)) != ch)
	{
		++index;
	}
			
	return ((*(str + index)) == ch);
}

	
	
	
	
	
	
	
	
	
	
	
	
 
