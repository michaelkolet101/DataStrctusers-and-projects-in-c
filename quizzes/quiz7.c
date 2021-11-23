#include <string.h>/* strlen */




/* function that check if str 2 is rotation of str1 */
int CheckRotation(char *str1, char *str2)
{
	char *start_str2; /*it's point to the start of str2*/
	int count = 0;
	
	while ('\0' != *str1)
	{
		while ((*str2 != *str1) && ('\0' != *str2))
		{
			++str2;
		
			if ('\0' == *str2)
			{
				str2 = start_str2;
			}
			
			++count;
		}
	}
	
	if (count != strlen(str1))
	{
		return 1;
	}	
	
	return 0;	
}
