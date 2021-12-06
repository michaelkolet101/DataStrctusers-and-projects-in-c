#ifndef __WS8_H__
#define __WS8_H__

/*programmer name: Michael Kolet
reviewer's name: Daniel Zafrir */

/******************************    macros function   ***********************/

/*return the max from 2 args*/
#define MAX2(a,b) (((a)>(b))?(a):(b))

/*return the max from 3 args*/
#define MAX3(a,b,c) (((a)>(b))&&((a)>(c)))?a:(((b)>(c))&&((b)>(a)))?b:c    

/*The idea is to use pointer arithmetic ((&(var)+1)) to determine the offset of 
the variable, and then subtract the original address of the variable, 
yielding its size.*/
#define SIZEOF_VAR( var ) ((size_t)(&(var)+1)-(size_t)(&(var))) 



/***************************   functions   ********************************/

/*Creates an array of structures that contain different types
Prints the types and adds values ​​to them
Returns status 0 to success and status 1 to failure*/
int Creat();

#endif /*__WS8_H__*/






