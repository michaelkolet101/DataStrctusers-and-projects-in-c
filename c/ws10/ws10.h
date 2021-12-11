#ifndef __WS10_H__
#define __WS10_H__

/*programmer name: Michael Kolet
reviewer's name: Daniel Zafrir */

/******************************    macros function   ***********************/

/*get int and base, and return  it to as an string for any base*/
char* Itoa(int num, char* str, int base);


/*get a string and base, and return as a int num */
int Atoi(char *string, int base);

/*print the char if the char exist in two first array and not in third */
void PrintTwoEqualChar(char* arr1, char* arr2, char* arr3, int len1, int len2, int len3);
/***************************   functions   ********************************/




#endif /*__WS8_H__*/






