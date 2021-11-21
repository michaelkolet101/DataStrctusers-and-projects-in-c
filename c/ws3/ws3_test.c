#include <stdio.h> /*printf*/
#include <stdlib.h>/**/
#include <assert.h>/**/
#include <string.h>/**/

#include "ws3.h"

#define COLS 3  
#define ROWS 3   
/**********************      TESTS      **************************************/
void TestCalcoletRow();






/*******************************main()***************************************/




int main (int argc, char **argv, char** envp)
{
	
	StoringAndPrinting (envp);
	printf("%d\n",JosephusProblem(100));
	TestCalcoletRow();
	DataTypes();
	
	return 0;
	
}















void TestCalcoletRow()
{
int i;
	int g[ROWS][COLS] = {{2,3,4},{5,6,7},{8,9,0}};
	
	
	int sum[ROWS];
	for (i = 0; i < ROWS; ++i)
	{
		sum[i] = 0;
	}
	/*TO DO test function*/
	CalcoletRow(g, sum);
	
	for (i = 0; i < ROWS; ++i)
	{
		printf("%d,  ",sum[i]);
	}
	puts("\n");
}




















