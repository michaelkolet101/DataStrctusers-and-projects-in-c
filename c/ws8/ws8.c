#include <stdio.h>/* scanf printf puts */
#include <assert.h>/* assert */

#include "ws8.h"

#define ARRY_SIZE 5

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

static void PrintInt(const void *data); 
static void PrintFloat(const void *data); 
static void PrintString(const void *data); 

static int AddInt(void *data,int num_to_add);
static int AddFloat(void *data,int num_to_add);
static int AddString(void *data,int num_to_add);

static void FreeAll(void *data);

int Init();
/**************************************************************************/





int Init()
{
	
	float f_num = 3.14;
	
	void *ptr_to_f = NULL;
	
	element_ty types_arry[ARRY_SIZE];
	
	 *(float*)&ptr_to_f = f_num;
	types_arry[0].data = ptr_to_f;
	/*types_arry[0].PrintFunc = Compare;
	types_arry[0].AddFunc = AddFloat;
	types_arry[0].FreeFunc = FreeAll;*/
	
	types_arry[1].data = (void*)5;
	types_arry[1].PrintFunc = PrintInt;
	types_arry[1].AddFunc = AddInt;
	/*types_arry[1].FreeFunc = FreeAll;
	
	/*types_arry[2].(char)data = "hellow";
	types_arry[2].PrintFunc = PrintInt;
	types_arry[2].AddFunc = AddFloat;
	types_arry[2].FreeFunc = FreeAll;*/
	
}

static void PrintInt(const void *data)
{
	printf("THE DATA IS: %\n", data);
}

/*static void PrintFloat(const void *data)
{
	printf("THE DATA IS: %f\n", (float)*data);
}*/
/*static void PrintString(const void *data)
{
	printf("THE DATA IS: %s\n", (char)*data);
}*/

static int AddInt(void *data,int num_to_add)
{
	int number = 0;
	
	number = (int)data;
	number += num_to_add; 
	
	return number;
}

/*static int AddFloat(void *data,int num_to_add)
{
	float number = 0;
	
	number = (float)data;
	number += num_to_add; 
	
	return number;
}*/


int main ()
{
	element_ty types_arry[ARRY_SIZE];
	PrintInt(types_arry[1].data);
	AddInt(types_arry[1].data, 15);
	PrintInt(types_arry[1].data);
	return 0;
}















