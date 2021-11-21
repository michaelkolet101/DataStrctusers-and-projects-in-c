#ifndef WS3_H
#define WS3_H


#include <stdlib.h>/*size_t*/

/*progmer name: michael kolet
  reviewer's name: tal cohen*/

#define COLS 3  
#define ROWS 3   

 
/***************************  My functions   ********************************/

/*Function for calculating and printing a row sum in a two-dimensional array */
int* CalcoletRow (int array[ROWS][COLS], int sum[ROWS]);
/*TO DO cheang the array without the ROWS and COLS in the defin*/ 


/*Function for displaying Joseph's problem*/
int JosephusProblem(int len);

/*print data types*/
void DataTypes();


void  VariableEnvironment(char** envp);






#endif






