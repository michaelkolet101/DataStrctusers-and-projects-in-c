#include <stdio.h>
#include <stdlib.h>/*size_t*/
#include <string.h>
#include <assert.h>



#include "ws3.h"


/**/
static void printarry(int arr[], int len);

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






/*Function for  Joseph's problem */
int JosephusProblem(int len)
{
	/*TO DO creat pointer with malloc and len*/
	int *arr = malloc(len * sizeof(int));
	int *start = arr;
	int i;
	
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
			arr[i] = -1;
			count = 0;
			--remain;
		}
		
		else if ((1 == arr[i]) && (0 == count))
		{
			count = 1;
		}	
		/*kidum magali*/
		i = (i + 1) % len;
		
	
	}
	
	/*to do out it to extern function*/
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



