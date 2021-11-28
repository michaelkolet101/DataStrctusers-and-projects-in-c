#ifndef __WS6_H__
#define __WS6_H__

/*progmer name: michael kolet
reviewer's name: shiran reichenberg */

/***************************  My functions   ********************************/

/*gets two positive and integer numbers
Returns the product of X by 2 to the power of Y*/
long Pow2( unsigned int x,  unsigned int y);

/*check if the number is power of two*/
int CheckPowerTwo(unsigned int n);

/*check if the number is power of two*/
/*get number in type unsigned int
and return 1 for secsses or 0 to fail*/
int CheckPowerTwoWithLoop(unsigned int n);

/*Add to number 1 without using the + operator in C.
Receives an integer pointer and doing it plus 1*/
void AddOneToNum(int *number);

/*receives an array of positive and integer numbers, And the size of the array.
prints only the numbers whose binary representation has three bits on*/
void OnlyWithTreeBytes(unsigned int *array_of_numbers, unsigned int len_of_array);

/*reverse bits of an integer
Gets a positive and integer number
Changes its value in bytes in reverse order*/
unsigned int ByteMirrorLoop(unsigned int num);

/*reverse bits of an integer
Gets a positive and integer number
Changes its value in bytes in reverse order*/
unsigned int ByteMirrorNoLoop(unsigned int num);

/*Gets a number and returns one if the bits in second and sixth place are 
lit otherwise returns 0*/
int checkOnBytesAnd(unsigned char ch);
int checkOnBytesOr(unsigned char ch);

/*Gets a positive and complete number
Switches between the third and fifth bits
Returns the new number*/
unsigned char SwapBytes(unsigned char ch);

/*Receives a positive integer and returns the lower number divided by 16 with 
no remainder*/
unsigned int LowerNumberDividedBy16(unsigned int num);

/*Gets an integer positive number Returns the number of times
 the digit 1 appears in the binary representation*/
unsigned int CountBitsOne(unsigned int number);
unsigned int CountBitsOneOnLoop(unsigned int number);

/*Function Replace two variables with XOR*/
void SwapValNumbers(int *num_1, int *num_2);

#endif /*__WS6_H__*/






