#include <stdio.h>
/* scanf printf puts */
#include <string.h>/* strcat */
#include <assert.h>/* assert */
#include <stdlib.h>




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

static void PrintFloat(const void *data); 
static int AddFloat(void *data,int num_to_add);

static void PrintInt(const void *data); 
static int AddInt(void *data,int num_to_add);

static void PrintString(const void *data);
static int AddString(void *data,int num_to_add);

static char*ConvertIntToString(int num_to_convert);

static void FreeFloat(void *data);
static void FreeInt(void *data);
static void FreeString(void *data);
static void FreeAll(element_ty types_arry[]);

/**************************************************************************/

int main ()
{
	element_ty types_arry[ARRY_SIZE];
	float f_num = 3.14;
	int add_num = 10;
	void *ptr_to_f = NULL;
	void *ptr_to_int = NULL;
	void *ptr_to_str = (char*)malloc(100);
	int number = 8;
	char str[] = "it's work?";
	int i = 0;
	
	 *((float*)&ptr_to_f) = f_num;
	*((int*)&ptr_to_int) = number;
	 ptr_to_str = str;
/******************************INIT******************************************/	
	types_arry[0].data = ptr_to_f;
	types_arry[0].PrintFunc = PrintFloat;
	types_arry[0].AddFunc = AddFloat;
	types_arry[0].FreeFunc = FreeFloat;
	
	types_arry[1].data = ptr_to_int;
	types_arry[1].PrintFunc = PrintInt;
	types_arry[1].AddFunc = AddInt;
	types_arry[1].FreeFunc = FreeInt;
	
	types_arry[2].data = ptr_to_str;
	types_arry[2].PrintFunc = PrintString;
	types_arry[2].AddFunc = AddString;
	types_arry[2].FreeFunc = FreeString;
	
	
/**********************************TEST************************************/	
	types_arry[0].PrintFunc(&types_arry[0].data);
	types_arry[0].AddFunc(&types_arry[0].data, add_num);
	types_arry[0].PrintFunc(&types_arry[0].data);
	
	types_arry[1].PrintFunc(&types_arry[1].data);
	types_arry[1].AddFunc(&types_arry[1].data, add_num);
	types_arry[1].PrintFunc(&types_arry[1].data);
			
	types_arry[2].PrintFunc(&types_arry[2].data);
	types_arry[2].AddFunc(&types_arry[2].data, add_num);
	types_arry[2].PrintFunc(&types_arry[2].data);
	
	FreeAll(types_arry);	
	return 0;
}

/*****************************************************************************/

static void PrintFloat(const void *data)
{
	printf("THE DATA IS: %f\n", *((float*)data));
}

static int AddFloat(void *data,int num_to_add)
{
		*((float*)data) += num_to_add;
		return 0;
}

static void PrintInt(const void *data)
{
	printf("THE DATA IS: %d\n", *((int*)data));
}

static int AddInt(void *data,int num_to_add)
{
	*((int*)data) += num_to_add;
	return 0;
}

static void PrintString(const void *data)
{
	printf("%s\n", *(char**)data);
}

static int AddString(void *data,int num_to_add)
{
	char *string_src = (char*)malloc(sizeof(char) * 100);
	char *string_add = NULL;
	
	/*string that is the sorce*/
	string_src = *(char**)data;
	/*string that is the num to add*/
	string_add = ConvertIntToString(num_to_add);
	
	/*if the malloc fail*/
	if (NULL == string_add)
	{
		return 1;
	}		
	/*use strcat to connect bitwwin the strings*/
	string_add = strcat(string_src, string_add);
	
	data = &string_add;  
	free(string_add);
	free(string_src);
	return 0;
}

static char* ConvertIntToString(int num_to_convert)
{
	char *result = NULL;
	char *strat = NULL;
	
    result = (char*)malloc(50);
    strat = result;
    sprintf(result, "%d", num_to_convert);
  	
	return strat;
}
/******************************************************************************/
static void FreeInt(void *data)
{
	;
}

static void FreeFloat(void *data)
{
	;
}

static void FreeString(void *data)
{
	free(data);
}

static void FreeAll(element_ty types_arry[])
{
	 int i = 0;
	 for (i = 0; i < ARRY_SIZE; ++i)
	 {
	 	types_arry[i].FreeFunc(types_arry[i].data);
	 }
}













