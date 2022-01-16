#include <stdio.h>
#include <stdlib.h>/*size_t*/
#include <string.h>
#include <assert.h>
#include <ctype.h>

#include "ws3.h"

/*usefull functions*/
static void printarry(int arr[], int len);
static int Length(char** envp);
static char* LwoStr(char *str);
static size_t StrLen(const char *pointer_to_string);
static char* StrCpy(char *destination, const char *source);
static char *StrDup(const char *str);

/*******************************************************************/

/*Function for calculating a row sum in a two-dimensional array*/
int* CalcoletRow(int array[ROWS][COLS], int sum[ROWS])
{
	int i, j;
	
	/*to do out it to extern function*/
	for (i = 0; i < ROWS; ++i)
	{
		for (j = 0; j < COLS; ++j)
		{	
			sum[i] += array[i][j];
		}
		
	}
	return sum;	
}	

/*Function for  Joseph's problem 
Receives the number of soldiers and prints the index that you want 
to have in order to stay alive*/
int JosephusProblem(int len)
{
	/*TO DO creat pointer with malloc and len*/
	int *arr = malloc(len * sizeof(int));
	int *start = arr;
	int i = 0;
	
	/*TO DO name more suitable*/
	int count = 0;
	
	int remain = len;
	
	
	/*Initialize the array*/
	for (i = 0; i < len; ++i)
	{
		arr[i] = 1;
		
	}
	/*TO DO comment!!!!!*/
	while (1 != remain)
	{
	
		if (1 == arr[i] && (count == 1))
		{
			arr[i] = 0;
			count = 0;
			--remain;
		}
		
		else if ((1 == arr[i]) && (0 == count))
		{
			count = 1;
		}	
		/*Circular promotion*/
		i = (i + 1) % len;
	}
	
	/*TODO out it to extern function*/
	for (i = 0; i < len; ++i)
	{
		if (arr[i] == 1)
		{
			return (i);
			/*printf("The place where you stay alive: %d\n",i + 1);*/
		}
		
	}
	
	free(start);	
}

static void printarry(int arr[], int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		printf("%d,",arr[i]);
	}
	printf("\n");
}

/*print data types*/
void DataTypes()
{
	fprintf( stdout, "size of char %10lu\n",sizeof(char));
	fprintf( stdout, "size of int  %10lu\n",sizeof(int));
	fprintf( stdout, "size of float  %5lu\n",sizeof(float));
	fprintf( stdout, "size of double  %5lu\n",sizeof(double));
	fprintf( stdout, "size of short int  %5lu\n",sizeof(short int));
	fprintf( stdout, "size of unsigned short int  %5lu\n",sizeof(unsigned short int));
	fprintf( stdout, "size of unsigned int  %5lu\n",sizeof(unsigned int));
	fprintf( stdout, "size of long int  %5lu\n",sizeof(long int));
	fprintf( stdout, "size of unsigned long int  %5lu\n",sizeof(unsigned long int));
	fprintf( stdout, "size of signed char  %5lu\n",sizeof(signed char));
	fprintf( stdout, "size of unsigned char  %5lu\n",sizeof(unsigned char));
	fprintf( stdout, "size of unsigned char  %5lu\n",sizeof(long double));
	fprintf( stdout, "size of unsigned char  %5lu\n",sizeof(int*));
	
}

/*Gets an array of environment variables
Keeps it in an array and prints them in small print*/
void  StoringAndPrinting(char** envp)
{
	char **buffer = NULL;
	char **start_envp = NULL;
	char **start_buffer = NULL;
	char **start_to_free = NULL;
	
	int width;
	int count = Length(envp);			/*The length of the string rows
	 		of the environment variables, in fact it is the outer array that 
	 									contains all the strings*/
	start_envp = envp; /*Maintains the beginning of the environment variable*/
	
	buffer = (char **)malloc(sizeof(char) * count  - 1);/*Define a place to
												 hold the copy*/ 
	if (NULL == buffer)
	{
	 	puts("malloc fail");
	 	
	}
	
	while (envp)
	{
		*buffer = LwoStr(StrDup(*envp));
		
		printf("%s",*buffer);
		++envp;
	}	
	
	start_buffer = buffer;
	free(buffer);
}

static int Length(char** envp)
{
	int count = 0;
	while (*envp) 
		{			
			++count;
			*envp++;
		}
		
	return (count);
}

static char* LwoStr(char *str)
{
	char *start = str;
	while('\0' != *start)
	{
		*start = tolower(*start);
		++start;
	}
	return str;
}

static char *StrDup(const char *str)

{
	char *dest = malloc(StrLen(str) + 1);  
	if (dest == NULL)
	{
	 	return NULL;
	}          
	StrCpy(dest, str);                     
	return dest; 
}

static size_t StrLen(const char *pointer_to_string)
{
	
    unsigned int number_of_characters = 0;
    while('\0' != *pointer_to_string)
    {
        ++number_of_characters;
        ++pointer_to_string;
    }
    return (size_t)number_of_characters;
}

static char* StrCpy(char *destination, const char *source)
{

	/*Indicates a destination to which the string will be copied*/
	char *start_dest = destination;/*לתת משמעות למשתנה*/
	
	while ('\0' != *source)/*A loop that passes over the original string*/
	{
		*destination = tolower(*source);
		++destination;/*Upload by one to two pointres*/
		++source;
	}
	    
    *destination = '\0';/*Add the NULL character*/
    
    return start_dest;
}



















