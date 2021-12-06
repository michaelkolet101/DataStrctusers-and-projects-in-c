#include <stdio.h> /* scanf printf puts */
#include <string.h> /* strcat */
#include <assert.h> /* assert */
#include <stdlib.h> /*malloc, realloc, free */

#include "ws8.h"

#define ARRY_SIZE 3
#define MAX_INT_LENGTH 11

#define SUCCESS 0
#define FAIL 1

typedef void(*Print_ty)(const void *data);
typedef int(*Add_ty)(void *data,int num_to_add);
typedef void(*Free_ty)(void *data);

typedef struct element
{
	void *data;
	Print_ty PrintFunc;
	Add_ty AddFunc;
	Free_ty FreeFunc;
} element_ty;

/****************************************************************************/
/*USEFULL FUNCTIONS THAT I USE IN THE PROGREM*/

/*print float number*/
static void PrintFloat(const void *data);

/*add anumbe to a float number*/ 
static int AddFloat(void *data,int num_to_add);

/*print int number*/
static void PrintInt(const void *data);

/*add int to an int number*/ 
static int AddInt(void *data,int num_to_add);

/*print string to the screen*/
static void PrintString(const void *data);

/*add a number to the string */
static int AddString(void *data,int num_to_add);

/*convert a number from in to string*/
static char* ConvertIntToString(int num_to_convert);

/*dont do anything*/
static void DoNothing(void *data);

/*free the pointer*/
static void FreeString(void *data);

/*function that initialization the array */
static int Init(element_ty types_arry[]);



/**************************************************************************/
int Creat()
{
	int add_num = 10;
	element_ty types_arry[ARRY_SIZE];
	int i = 0;
	int status = SUCCESS;
	
	/*initialization the array*/
	status = Init(types_arry);
	
/********************************  calling  **********************************/	
	
	for (i = 0; i < ARRY_SIZE; ++i)
	{
		types_arry[i].PrintFunc(&types_arry[i].data);
		types_arry[i].AddFunc(&types_arry[i].data, add_num);
		types_arry[i].PrintFunc(&types_arry[i].data);
	}
	
	for (i = 0; i < ARRY_SIZE; ++i)
	{
		types_arry[i].FreeFunc(types_arry[i].data);
	}
	return status;
}

/************************     initialization   ******************************/	

static int Init(element_ty types_arry[])
{
	float f_num = 3.14;
	char *ptr_to_str = (char*)malloc(sizeof(char) * sizeof("it's work?"));
	
	if (NULL == ptr_to_str)
	{
		return FAIL;
	}
	
	ptr_to_str = strcpy(ptr_to_str, "it's work");	
	*((float*)&types_arry[0].data) = f_num;
	
	types_arry[0].PrintFunc = PrintFloat;
	types_arry[0].AddFunc = AddFloat;
	types_arry[0].FreeFunc = DoNothing;
	
	types_arry[1].data = (void *)8;
	types_arry[1].PrintFunc = PrintInt;
	types_arry[1].AddFunc = AddInt;
	types_arry[1].FreeFunc = DoNothing;
	
	types_arry[2].data = ptr_to_str;
	types_arry[2].PrintFunc = PrintString;
	types_arry[2].AddFunc = AddString;
	types_arry[2].FreeFunc = FreeString;	
	
	return SUCCESS;
}

/***************************************************************************/

static void PrintFloat(const void *data)
{
	assert(data);
	printf("THE DATA IS: %f\n", *((float*)data));
}

static int AddFloat(void *data,int num_to_add)
{
		*((float*)data) += num_to_add;
		return SUCCESS;
}

/***************************************************************************/

static void PrintInt(const void *data)
{
	assert(data);
	printf("THE DATA IS: %d\n", *((int*)data));
}

static int AddInt(void *data,int num_to_add)
{
	assert(data);
	*((int*)data) += num_to_add;
	return SUCCESS;
}

/***************************************************************************/

static void PrintString(const void *data)
{	
	assert(data);
	printf("THE DATA IS: %s\n", *(char**)data);
}

static int AddString(void *data,int num_to_add)
{
	char *string_src = *(char**)data;

	/*string that is the num to add*/
	char *string_add = ConvertIntToString(num_to_add);
	
	assert(data);
	/* re-allocate memory for string concatenation */	
	string_src = realloc(string_src, strlen(string_src) + strlen(string_add) + 1);
	
	/*if the realloc fail*/
	if ((NULL == string_src) || (NULL == string_add))
	{
		return FAIL;
	}
		
	/*use strcat to connect bitwwin the strings*/
	string_src = strcat(string_src, string_add);
	
	/*data = &string_add;  */
	*(char**)data = string_src;
	
	free(string_add);
	return SUCCESS;
}

/****************************************************************************/

static char *ConvertIntToString(int num_to_convert)
{
	char *result = NULL;
	
    result = (char*)malloc(MAX_INT_LENGTH + 1);
	
	if (NULL == result)
	{
		return NULL;
	}
    sprintf(result, "%d", num_to_convert);
  	
	return result;
}

/***************************************************************************/

static void DoNothing(void *data)
{
	(char*)data;
}

static void FreeString(void *data)
{
	free(data);
}






































