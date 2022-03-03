#include <stdio.h> /*printf*/
#include <string.h> /*strlen*/
#include <assert.h> /*assert*/

int Is_Subsequence(char *sub, char *src) 
{ 
	
	size_t count_of_char = strlen(sub);
	char *end = src + strlen(src);

	assert(sub);
	assert(src);

	while (count_of_char && src < end)
	{
		if (*src == *sub)
		{
			--count_of_char;
			++sub;
		}

		++src;
	}
		
	return count_of_char == 0;	

}

int main(void) 
{ 
	
	char big[] = "gsgghgggghgghgg "; 
	char sub[] ="hhh";

	int res = Is_Subsequence(sub, big);

	printf("%d\n", res);
	

	return(0);	 
}

