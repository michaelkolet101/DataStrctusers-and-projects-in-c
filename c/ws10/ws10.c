#include <stdio.h> /* scanf printf puts */
#include <string.h> /* strcat */
#include <assert.h> /* assert */
#include <stdlib.h> /*malloc, realloc, free */

#include "ws10.h"

#define FALSE 0
#define TRUE 1



/****************************************************************************/
/*USEFULL FUNCTIONS THAT I USE IN THE PROGRAM*/



/*reverse string*/
/*TODO change the name to convention name!!! and batter name*/
static void reverse(char *str1);

/*convert string to base 10*/
static int ToDeci(char *str, int base);
/*TODO change the name to convention name!!! and batter name*/
static int val(char c);

/*initializtion the ascii aray with 0*/
static void InitAsciiArr(int *ascii);

/*set the index fo the ascii arr relative  		to arr1*/
static void ChackArr1(int *ascii, char *arr1, int len1);

/*set the index fo the ascii arr relative  		to arr2 if the index is alrady set*/
static void ChackArr2(int* ascii, char* arr2, int len2);

/*set the index fo the ascii arr relative 		the arr1 and arr2*/
static void ChackArr3(int* ascii, char* arr3, int len3);

/*print the correct value*/
static void PrintCorrectVal(int* ascii);
/*************************************************************************/

char* Itoa(int num, char* str, int base)
{
    int i = 0;
    /*TODO change the varibel name to "is negativ"*/
    int is_negative = FALSE;
    /*TODO better name*/
 	int rem = 0;
 	
    /* Handle 0 explicitly, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        *str = '0';
		++str;
        *str = '\0';
        
        return str;
    }
 	
 	/*TODO check the if*/
    if ((num < 0) && (base == 10))
    {
        is_negative = TRUE;
        num = -num;
    }
 
    /* Process individual digits*/
    while (num != 0)
    {
        rem = num % base;
         /*TODO work with pointers*/
        if (rem > 9)
        {
        	str[i] = (rem - 10) + 'a';
        }
        else
        {
        	str[i] = rem + '0';
        }
        
        ++i;
        
        num = num/base;
    }
 
    /* If number is is_negative, append '-'*/
    /*TODO work with pointers*/
    if (is_negative)
    {
        str[i] = '-';
		++i;        
    }
 
    /* Append null terminator*/
    str[i] = '\0'; 
 
    /* Reverse the string*/
    
    reverse(str);
 
    return str;
}
 
int Atoi(char *string, int base)
{
	int i = 0;
	/*TODO better name*/
    int res = 0;
    int nagativ = 0;
    
    
    if (*string == '-')
    {
    	nagativ = 1;
    	++string;
    }
    
    if (10 == base)
    {
    	/*TODO work with pointers*/
    	for (i = 0; string[i] != '\0'; ++i)
		{
			res = res * base + string[i] - '0';
		}	
    }
    else
    {
    	res = ToDeci(string, base);
 	}
 	
 	if (1 == nagativ)
 	{
 		res = -res;
 	}
    return res;
}

void PrintTwoEqualChar(char* arr1, char* arr2, char* arr3, int len1, int len2, int len3)
{
	int ascii[256] = {0};
	
	/*initializtion the ascii aray with 0*/
	InitAsciiArr(ascii);
	
	/*set the index fo the ascii arr relative  		to arr1*/
	ChackArr1(ascii, arr1, len1);
	
	/*set the index fo the ascii arr relative  		to arr2 if the index is alrady set*/
	ChackArr2(ascii, arr2, len2);
	
	/*set the index fo the ascii arr relative 		the arr1 and arr2*/
	ChackArr3(ascii, arr3, len3);
	
	/*print the correct value*/
	PrintCorrectVal(ascii);	
}

/***********************************************/

static void PrintCorrectVal(int* ascii)
	{
		int i = 0;
		
		for (i = 0; i < 265; ++i)
		{
			if ((ascii[i]) == 2)
			{
				printf("%c\n",i);
			}
		}
	}
	
static void ChackArr3(int *ascii, char* arr3, int len3)
	{
		int i = 0;
		int index = 0;
		
		for (i = 0; i < len3; ++i)
		{
			index = (int)arr3[i];
			ascii[index] -= 1;
		}
	}
	
static void ChackArr2(int* ascii, char* arr2, int len2)
	{
		int i = 0;
		int index = 0;
		
		/*TODO what if they are the same char?*/
		for (i = 0; i < len2; ++i)
		{
			index = (int)arr2[i];
			ascii[index] += 1;
		}
	}
	
static void InitAsciiArr(int *ascii)
	{
		int i = 0;
		for (i = 0; i < 256; ++i)
		{
			ascii[i] = 0;
		}
	}
	
static void ChackArr1(int *ascii, char *arr1, int len1)
	
	{
		int i = 0;
		int index = 0; 
		
		for (i = 0; i < len1; ++i)
		{
			index = (int)arr1[i];
			ascii[index] += 1;
		}
	}
	
static void reverse(char *str1)  
{  
    int i = 0, len = 0, temp = 0;  
    len = strlen(str1);  
      
    for (i = 0; i < len/2; ++i)  
    {     
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
    }  
}  

/*TODO try and work with to upper or to lower*/
static int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

static int ToDeci(char *str, int base)
{
    int len = strlen(str);
    /* Initialize power of base*/
    int power = 1; 
    int num = 0;  
    int i = 0;
 
    /* Decimal equivalent is str[len-1]*1 +*/
    /* str[len-2]*base + str[len-3]*(base^2)+*/
    /*TODO work with pointers*/
    for (i = len - 1; i >= 0; --i)
    {
        /* A digit in input number must be*/
        /* less than number's base*/
        /*TODO what if val < base and btween 9-A on ascci*/
        /*TODO return status*/
        if (val(str[i]) >= base)
        {
           printf("Invalid Number");
           return -1;
        }
 
        num += val(str[i]) * power;
        power = power * base;
    }
 
    return num;
}


































