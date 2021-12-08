#include <stdio.h> /* scanf printf puts */
#include <string.h> /* strcat */
#include <assert.h> /* assert */
#include <stdlib.h> /*malloc, realloc, free */

#include "ws10.h"

#define FALSE 0
#define TRUE 1



/****************************************************************************/
/*USEFULL FUNCTIONS THAT I USE IN THE PROGRAM*/

/*int countDigit(int n);*/
static void reverse(char str[], int length);
static void swap(char *x, char *y);
void revstr(char *str1)  ;

/*************************************************************************/

char* Itoa(int num, char* str, int base)
{
    int i = 0;
    int negative = FALSE;
 	int rem = 0;
 	
    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    if (num < 0 && base == 10)
    {
        negative = TRUE;
        num = -num;
    }
 
    /* Process individual digits*/
    while (num != 0)
    {
        rem = num % base;
        str[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        ++i;
        num = num/base;
    }
 
    /* If number is negative, append '-'*/
    if (negative)
    {
        str[i] = '-';
		++i;        
    }
 
    str[i] = '\0'; /* Append string terminator*/
 
    /* Reverse the string*/
    
    revstr(str);
 
    return str;
}
 
/*
char* Itoa(int number)
{
	int count = countDigit(number);
	char *new_string = NULL;
	char *save_my_place = NULL;
	int *buffer = NULL;
	int num = number;
	
	printf("%d\n", count);
	
	if (0 > number)
	{
		++count;
	}
	
	new_string = (char *)malloc(sizeof(char) * count + 1);
	
	if (NULL == new_string)
	{
		return NULL;
	}
	
	save_my_place = new_string;
	
	buffer = (int *)malloc(sizeof(char) * count);
	
	if (NULL == buffer)
	{
		return NULL;
	}
	
	/*chack if the number is nagativ than put the "-" and "0" in the place*/
/*	if (0 > number)
	{
		
		*new_string = '-';
		++new_string;
		
		num = -num;
	}
	
	while (0 != num)
	{
		*buffer = num % 10;
		++buffer;
		num = num / 10; 
	}
	
	while (count)
	{
		*new_string = *buffer + 48;
		++new_string ;
		--buffer;
		--count;
	}
	
	*(new_string + count + 1) = '\0';
	
	new_string = save_my_place;
	
	return new_string;
}




int countDigit(int n)
{
    int count = 0;
    while (n != 0)
    {
        n = n / 10;
        ++count;
    }
    return count;
}*/
/*
static void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    char a, b;
    while (start < end)
    {
		a = *(str+start);
		b = *(str+end);
		      
        swap(a , b);
        ++start;
        --end;
    }
}
*/
void revstr(char *str1)  
{  
   
    int i, len, temp;  
    len = strlen(str1);  
      
    for (i = 0; i < len/2; i++)  
    {     
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  
/*
static void swap(char x, char y)
	{
	    char t = x;
	     x = y;
	     y = t;
	}

*/





































