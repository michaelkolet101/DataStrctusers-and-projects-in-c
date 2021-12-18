#include <stdio.h>
#include <stdlib.h>
#include <string.h>/**/
#include <assert.h>
#include <ctype.h> /*isspace */
#include <stddef.h> /*size_t*/

#include "ws2_string.h"

/*****************************StrCmp**************************************/
static int DivBy7(int num);
static int IsIt7(int num);


/*A function that checks if strings are equal to each other, if returns 0 
then they are equal*/
int StrCmp(const char *first_string, const char *second_string)
{
    while('\0' != *first_string && *first_string == *second_string) 
    {
        ++first_string;
        ++second_string;
    }
 
 /*Calculation to return the difference of the husky value of the two strings*/
	return *first_string - *second_string;
}

/*****************************StrLen**************************************/

/*A function that receives a pointer to a string and returns the character 
association in the string*/

size_t StrLen(const char *pointer_to_string)
{
    unsigned int number_of_characters = 0;
    while('\0' != *pointer_to_string)
    {
        ++number_of_characters;
        ++pointer_to_string;
    }
    return (size_t)number_of_characters;
}


/*******************************StrCpy()*************************************/

/*The function copies a string that points to a pointer to one destination and 
returns a pointer that points to it*/

char* StrCpy(char *destination, const char *source)
{
	/*Indicates a destination to which the string will be copied*/
	char *start_dest = destination;
	while ('\0' != *source)/*A loop that passes over the original string*/
	    {
		   *destination = *source;
		   ++destination;/*Upload by one to two pointres*/
		   ++source;
	    }
	    
	    *destination = '\0';/*Add the NULL character*/
	    
	    return start_dest;
}
    
/**********************************StrnCpy()**********************************/

/*A function that receives two pointers, one for an original string and one for
 copying, receives a number so that it copies a number of characters from the
  original string to a new one.*/
char* StrnCpy(char *destination, const char *source, size_t num)
{
	char *start_dest = destination;
	/*Indicates a destination to which the string will be copied*/
	while (('\0' != *source) && (0 < num) )
	    {
		    --num;
		    *destination = *source;/*Upload by one to two pointres*/
			++destination;
			++source;
	    }
	    ++destination;
	    *destination = '\0';/*Add the NULL character*/
		                                                                        
	    return start_dest;
}

/**********************************StrCaseCmp()*******************************/
int StrCaseCmp(const char *s1, const char *s2)
{
	
    while('\0' != *s1 && toupper(*s1) == toupper(*s2))
    {
        ++s1;
        ++s2;
    }
 /*Calculation to return the difference of the husky value of the two strings*/
	return toupper(*s1) - toupper(*s2);
 } 
   
/**********************************StrChr()******************************/

/*function returns a pointer to the first occurrence of the character
 c in the string s*/

char *StrChr(const char *some_string, int ch)
{
	
	while (('\0' != *some_string ) && (*some_string != ch)) 
 	{
		++some_string;
	}
	
	if('\0' == *some_string)
	{
		return NULL;
	}
	
    return (char *)some_string;

}
/*********************************StrDup()******************************/

char *StrDup(const char *str)

{
	char *dest = malloc(StrLen(str) + 1);  
	
	if (dest == NULL)
	{
	 	return NULL;
	}         
	 
	StrCpy(dest, str);                     
	return dest; 
}

/*********************************StrCat()******************************/

/*Receives two strings and returns a pointer to the string connected from both*/
char *StrCat(char *destination, const char *source)
{
/*Set a pointer that will point to the end of the target string*/
	char *ptr = destination + StrLen(destination);
/*Go through the loop on the copied string as long as it does not end and copy 
it to the destination*/
	while (*source != '\0')
	{
		*ptr = *source;
		++ptr;
		++source;
	}
	*ptr = '\0';/*Enter the NULL value at the end of the string*/
	return destination;

}

/*The function gets two string strings and a number of characters per thread 
from the second string for the first time*/
char *StrnCat(char *destination, const char *source, size_t number_of_char)
{
/*Set a pointer that will point to the end of the target string*/
	char *ptr = destination + strlen(destination);
	
/*Go through the loop on the copied string as long as it does not end and copy 
it to the destination*/
	while (*source != '\0' && number_of_char != 0)
	 {
        *ptr++ = *source++;
        --number_of_char;
      }
	 *ptr = '\0';/*Enter the NULL value at the end of the string*/
	return destination;
}

/*Auxiliary function to check if the strings are the same*/
int compare(const char *first_string, const char *second_string)
{
    while (*first_string && *second_string)
    {
        if (*first_string != *second_string)
         {
            return 0;
        }
 
        first_string++;
        second_string++;
    }
  return (*second_string == '\0');
 
 }
  
/*Receives two strings and returns the first position of the small string 
inside the large one*/
char* StrStr(const char *large_string, const char *the_little_string)
{

    while (*large_string != '\0')
    {
        if ((*large_string == *the_little_string) && compare(large_string, the_little_string)) 
        {
            return (char*)large_string;
        }
        ++large_string;
    }
 
    return NULL;
}

size_t StrSpn(const char *s1, const char *s2)
{
	size_t len = 0;
	
	if((s1 == NULL) || (s2 == NULL))
	{
        return len+1;
	}
	
	while(*s1)
	 {
		 if(strchr(s2,*s1))
		 {
		      len++;
		      s1++;
		 }
		 else
		 {
			 break;
			 
		 }
     }

	return len;
}

/*A function to check if a string str is palindrome*/
void IsPalindrome(char *str)
{
	/*Start from leftmost and rightmost corners of str*/
	int start = 0;
    int end = strlen(str) - 1;
    
    while (end > start)
    {
        if (str[start] != str[end])
        {
            printf("%s is not a palindrome\n", str);
            break;
        }
		++start;
		--end;
	}
	
	if (end == start)
	{
		printf("%s is a palindrome\n", str);
	}
}

/*Function for deleting unnecessary spaces from a string*/
char* SpaceX(char *some_string)
{
	char *temp = some_string;
	char *end = some_string + strlen(some_string) - 1;
	char *ptr_new = NULL;
	int count;

	/*Skip the spaces from the beginning*/
	while (*some_string && isspace(*some_string))
	{
	 	++some_string;
	}
	/*Skip the spaces from the end*/
	while (isspace(*end))
	{
		*end = '\0';
		 --end;
	}
	ptr_new = temp;
	/*main loop as long as we have not reached the end of the string*/
	while(*some_string )
	{
		/*A loop that makes sure the character is not spaced*/
		while ((!(isspace(*some_string))) && (*some_string))
		{
			*temp = *some_string;
			
			++temp;
			++some_string;
			count = 0;
		}	
	
		count = 1;
		/*++some_string;*/
		*temp = *some_string;
		++temp;
		
		/*A loop that skips unnecessary spaces between words*/ 
		while (count == 1 && isspace(*some_string))
		{ 
			 ++some_string; 
		}	
	}
	*temp = '\0';	
	return ptr_new ;
}

void SeveneBoom(int start, int end)
{
	int i = 0;
	
	for (i = start; i < end; ++i)
	{
		if ((0 == DivBy7(i)) || (0 != IsIt7(i)))
		{
			puts("BOOM");
		}
		else
		{
			printf("%d\n", i);
		}
	}
}

static int DivBy7(int num)
{
	return (num % 7);
}

static int IsIt7(int num)
{
	while (num)
	{
		if (num % 10 == 7)
		{
			return 1;
		}
		num = num / 7;
	}	
	return 0;
}
















