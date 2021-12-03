#include <stdio.h>/* scanf printf puts */
#include <assert.h>/* assert */



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
/**************************************************************************/

int main ()
{
	
	element_ty types_arry[ARRY_SIZE];
	float f_num = 3.14;
	int add_num = 10;
	void *ptr_to_f = NULL;
	void *ptr_to_int = NULL;
	void *ptr_to_str = NULL;
	int number = 8;
	char str[] = "it's work?";
	
	
	 *((float*)&ptr_to_f) = f_num;
	*((int*)&ptr_to_int) = number;
	/**((char*)&ptr_to_str) = &str;*/


/******************************INIT******************************************/	
	types_arry[0].data = ptr_to_f;
	types_arry[0].PrintFunc = PrintFloat;
	types_arry[0].AddFunc = AddFloat;
	
	
	
	types_arry[1].data = ptr_to_int;
	types_arry[1].PrintFunc = PrintInt;
	types_arry[1].AddFunc = AddInt;
	
	
	types_arry[2].data = &str;
	types_arry[2].PrintFunc = PrintString;
	/*types_arry[2].AddFunc = AddString;*/

/**********************************TEST************************************/	
	types_arry[0].PrintFunc(&types_arry[0].data);
	types_arry[0].AddFunc(&types_arry[0].data, add_num);
	types_arry[0].PrintFunc(&types_arry[0].data);
	
	
	types_arry[1].PrintFunc(&types_arry[1].data);/*it's not working with
										 int num, need to ask some one*/
	types_arry[1].AddFunc(&types_arry[1].data, add_num);
	types_arry[1].PrintFunc(&types_arry[1].data);
			
	
	types_arry[2].PrintFunc(types_arry[2].data);
	/*types_arry[2].AddFunc(&types_arry[2].data, add_num);
	types_arry[2].PrintFunc(&types_arry[2].data);
		*/	
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
}

static void PrintInt(const void *data)
{
	/*void *ptr = data;*/
	printf("THE DATA IS: %d\n", *((int*)data));
}

static int AddInt(void *data,int num_to_add)
{
	*((int*)data) += num_to_add;
	return 0;
}

static void PrintString(const void *data)
{
	printf("%s\n", (char*)data);
}















