#include <stdio.h>
#include <stdlib.h>

#define SUCSSES 0
#define FAIL 1
/******************************************************************************/

/*Statements of functions*/

/*Receives two pointers on int values ​​in memory and switches between them*/
void SwapVal(int *xp, int *yp);


/*Test functions for the replacement function Swapvall*/
int TestSwapVal(void);

/* An array copy function receives two pointers for a full array and an empty 
array and copies the full array inside the void */
void ArrayCopy(int len1, int *ptr_old, int *ptr_new);

/* Testing an array copy function */
int TestArrayCopy(void);


/*Checking addresses in memory of various variables*/
void CheckingAddresses();

/*A function that accepts two values ​​and switches between them.
To return value*/
void SwapToSizeT(size_t *a, size_t *b);


/*Test functions for the replacement function Swapval*/
int TestwapToSizeT();

/*Test functions for the replacement function Swapval*/
int TestSwapToSizeTPointers();

/*A function that receives a pointer to a string and returns the character 
association in the string*/
unsigned int StrLen(const char *s);

/*Test function on the strlen library function*/
void TestToStrLen();


/*A function that checks if strings are equal to each other, if returns 0 
then they are equal*/
int StrCmp(const char *first_string, const char *second_string);

void TestToStrCmp();
	

/******************************************************************************/




int main ()
{
	
	
	printf("test for SwapVal() 0 is sucsses 1 is fail--->%d\n",TestSwapVal());
	
	printf("test for TestArrayCopy() 0 is sucsses 1 is fail--->%d\n",
	                                                       TestArrayCopy());
	
	CheckingAddresses();
	
	printf("test for TestwapToSizeT() 0 is sucsses 1 is fail--->%d\n",
	                                                       TestwapToSizeT());
	printf("test for TestSwapToSizeTPointers() 0 is sucsses 1 is fail--->%d\n",
	                                             TestSwapToSizeTPointers());
	TestToStrLen();                                         
 	
    	TestToStrCmp();
		
	                                             
	return (0);	
}



/*****************************question 1************************************/



/*Receives two pointers on values ​​in memory and switches between them*/	
void SwapVal(int *x_ptr, int *y_ptr)

{
	int temp = *x_ptr;
	
	*x_ptr = *y_ptr;
	
	*y_ptr = temp;
}


/*Test functions for the replacement function Swapvall*/
int TestSwapVal()
{
	int x = 5, y = 7;
	int flag = 1;/*fail*/
	
	SwapVal(&x,&y);
	
	
	
	if ((7 == x) && (5 == y))
	flag = 0;/*success*/

return flag;
}
/*****************************question 2*************************************/



/* An array copy function receives two pointers for a full array and an empty 
array and copies the full array inside the void */
void ArrayCopy(int len1, int *ptr_old, int *ptr_new)

{	
	
	int i;
	
/*Going through a loop on the arrays and comparing them*/
	for(i = 0; i < len1; i++) 
	{
	
		*(ptr_new + i) = *(ptr_old + i);
		
	}
	       
}




/* Testing an array copy function */
int TestArrayCopy(void)

{
	int flag = 0;
	
	int i;
	
	int len1 = 10;
	
	int original[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	
	int new_arr[10] ={0};
	
	
	
	ArrayCopy(len1, original, new_arr);
	
	/*Go through the array in a loop and check that if one of the values ​​is 
	not equal then it will return an error*/
	for (i = 0; i < len1; i++)
	{
		if (new_arr[i] != original[i])
		{
			flag = 1;
			break;
		}
	}
	
	return flag;
}


/******************************question 3************************************/

/*Checking addresses in memory of various variables*/
void CheckingAddresses()
{
	static int s_i = 7;
	int  i = 7;
	int *ptr = &i;
	int *ptr2 = (int *)malloc(sizeof(int));

	printf("&s_i%20p\n",&s_i);
	printf("&ptr%25p\n",&ptr);
	printf("ptr%25p\n",ptr);
	printf("*ptr%25d\n",*ptr);
	printf("*ptr2%25p\n",ptr);
	free(ptr2);

}




/******************************question 4************************************/



/*A function that accepts two values of size_t type ​​and switches between them.*/
void SwapToSizeT(size_t *a, size_t *b)
{
	size_t tmp = *a;
	*a = *b;
	*b = tmp;

}

/*Test functions for the replacement function Swapval*/
int TestwapToSizeT()
{
	size_t x = 5, y = 7;
	int flag = 1;/*fail*/
	
	SwapToSizeT(&x,&y);
	
	
	
	if ((7 == x) && (5 == y))
	{
		flag = 0;/*success*/
	}
	return flag;	

}


/******************************question 4.2************************************/


/*A function that accepts two pointers ​​and switches between them.*/
void SwapToSizeTPointers(size_t **a, size_t **b)
{
	
	SwapToSizeT((size_t*) a, (size_t*) b);

}

/*Test functions for the replacement function Swapvall*/
int TestSwapToSizeTPointers()
{
	size_t num1 = 5, num2 = 7;
	size_t *p1 = &num1, *p2 = &num2; 
	size_t **g1 = &p1;
	size_t **g2 = &p2;
	int flag = 0;
	
	SwapToSizeTPointers(g1, g2);
	
	if ((num1 == **g1) || (num2 == **g2))
	{
		flag = 1;
	}
	return flag;

}



/******************************my strlen (: **********************************/

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

/*Test function on the strlen library function*/
void TestToStrLen()
{
	char str[]="hello daniel"; /*להשתמש בפונקציה המקורית של הספריה ולהשוות בין התשובות*/
	printf("Length of string a = %u \n",StrLen(str));  
}


/******************************my strcmp (: **********************************/

                                                                                  
/*A function that checks if strings are equal to each other, if returns 0 
then they are equal*/
int StrCmp(const char *first_string, const char *second_string)
{

    while (*first_string && *first_string != *second_string) 
    {
        ++first_string;
        ++second_string;
    }
 
 /*Calculation to return the difference of the husky value of the two strings*/
	return *first_string - *second_string;
}



void TestToStrCmp()
{
	char *str1 = "michael";
	char *str2 = "kolet";

	int ret = StrCmp(str1, str2);
	int ret_lib = strcmp(str1, str2);
	
	if (ret == ret_lib)
	{
		return SUCSSES;
	}
	else
	{
		return FAIL
	}
	                                                                                                                                          
                                                                           
	if (ret > 0)
	{
	   printf("%s", "str1 is greater than str2\n");
	}
	else if (ret < 0) 
	{
	   printf("%s", "str1 is less than str2\n");
	}
	else 
	{
	   printf("%s", "str1 is equal to str2\n");
	}
}



	
