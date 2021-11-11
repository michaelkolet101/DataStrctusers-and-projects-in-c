#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ws2_string.h"

/*****************************StrCmp**************************************/


/*A function that checks if strings are equal to each other, if returns 0 
then they are equal*/
int StrCmp(const char *first_string, const char *second_string)
{

    while(*first_string && *first_string != *second_string) 
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
    return number_of_characters;
}


/*******************************StrCpy()*************************************/

/*The function copies a string that points to a pointer to one destination and 
returns a pointer that points to it*/

char* StrCpy(char* destination, const char* source)
{
	/*Indicates a destination to which the string will be copied*/
	char *ptr = destination;
	

	while ('\0' != *source)/*A loop that passes over the original string*/
	    {
		   *destination = *source;
		   ++destination;/*Upload by one to two pointres*/
		   ++source;
	    }
	    
	    *destination = '\0';/*Add the NULL character*/
	    
	    return ptr;
}
    
/**********************************StrnCpy()**********************************/

/*A function that receives two pointers, one for an original string and one for
 copying, receives a number so that it copies a number of characters from the
  original string to a new one.*/
char* StrnCpy(char* destination, const char* source, size_t num)
{
char* ptr = destination;



/*Indicates a destination to which the string will be copied*/
while (('\0' != *source) && (0 < num) )
    {
	    --num;
	    *destination = *source;/*Upload by one to two pointres*/
		destination++;
		source++;
    }
    *destination = '\0';/*Add the NULL character*/
    return ptr;

}

/**********************************StrCaseCmp()*******************************/
int StrCaseCmp(const char *s1, const char *s2)
{
    int i,ch;
    unsigned char a,b;

    i = 0;
    ch = 0;
    /*A loop that ran as long as there was a string to run on it*/
    
    while(( *(s1+i) != '\0') && ( *(s2+i)!='\0'))
    {
		a = (unsigned)*(s1+i);
		b = (unsigned)*(s2+i);
		/*Increases the two characters to a large and minus sign between 
		them, if they are equal should be 0*/
		ch = toupper(a) - toupper(b);

		if( (ch < 0) || (ch > 0) )
		  return(ch);
		i++;
    }

    return(ch);
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
	
	
    return (char *)some_string;

}































