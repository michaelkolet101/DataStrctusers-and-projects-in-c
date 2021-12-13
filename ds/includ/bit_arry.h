#include <stdio.h> /*sizt_t*/

#ifndef __BIT_ARRAY_H__
#define __BIT_ARRAY_H__

/*

Version 0.1 - post - mentor review.
Version 1.0 - post - mentor review. 
    * Changed the functions to work by value, wihout storing the result of the opertaion.
    * Changed the type definition of the bit array type to wrap size_t instead of unsigned long
    * 
*/
/* bit array is a word-size array, MSB being the left bit. */
/* On 64-bit system, the indexes will be 0 - 63 */

typedef size_t bit_array_ty;

/******************************************************************************
* Function Description: sets the values of all bits of the array to 1	       
* Arguments: data - bit_array_ty.
* Return value: bit array
* Notes: 

* Time Complexity: NA
*******************************************************************************/
bit_array_ty SetAll(bit_array_ty data);


/******************************************************************************
* Function Description: sets the values of all bits of the array to 0	       
* Arguments: - data bit_array_ty.
* Return value: - bit_array_ty
* Notes: 

* Time Complexity: NA
*******************************************************************************/
bit_array_ty ResetAll(bit_array_ty data);


/******************************************************************************
* Function Description: returns the pointer to the bit-array bits converted 
  to 0/1 string.      
* Arguments: data - bit_array_ty, dest - pointer to the dest string.
* Return value: pointer to the converted string.
* Notes: dest needs to be able to hold word-long string.

* Time Complexity: NA
*******************************************************************************/
char *ToString(bit_array_ty data, char *dest);


/******************************************************************************
* Function Description: sets the value of a bit on the index @idx to 1      
* Arguments: data - bit_array_ty, idx - index of the bit to be set to 1.
* Return value: bit_array_ty
* Notes: undefined if the argument is out of range.

* Time Complexity: NA
*******************************************************************************/
bit_array_ty SetOn(bit_array_ty data, const unsigned int idx);

/******************************************************************************
* Function Description: sets the value of a bit on the index @idx to 0	       
* Arguments: data - bit_array_ty, idx - the index of the bit to be set to 0
* Return value: bit_array_ty.
* Notes: undefined if the argument is out of range.

* Time Complexity: NA
*******************************************************************************/
bit_array_ty SetOff(bit_array_ty data, const unsigned int idx);


/******************************************************************************
* Function Description: sets the value of a bit on the index @idx to @val	    
* Arguments: data - bit_array_ty, idx - index of the bit to be set, 
  val - value to set the bit to.
* Return value: bit_array_ty.
* Notes: undefined if the argument is out of range.


* Time Complexity: NA
*******************************************************************************/
bit_array_ty SetBit(bit_array_ty data, const unsigned int idx, const unsigned int val);


/******************************************************************************
* Function Description: returns the value of the bit on the index @idx       
* Arguments: data - bit_array_ty, idx - the index of the bit who's value is to be returned
* Return value: value of the chosen bit.
* Notes: undefined if idx is out of range.

* Time Complexity: NA
*******************************************************************************/
int GetVal(bit_array_ty data, const unsigned int idx);


/******************************************************************************
* Function Description: flips the value of the bit on the index @idx       
* Arguments: data - bit_array_ty, idx - the index of the bit ot be flipped.
* Return value: bit_array_ty.
* Notes: undefined if idx is out of range.

* Time Complexity: NA
*******************************************************************************/
bit_array_ty Flip(bit_array_ty data, const unsigned int idx);


/******************************************************************************
* Function Description: returns the mirror of the current bit-array state       
* Arguments: data - data by value.
* Return value: bit_array_ty  holding the mirrord bits
* Notes: 

* Time Complexity: NA
*******************************************************************************/
bit_array_ty Mirror(bit_array_ty data);


/******************************************************************************
* Function Description: rotates the contents of the bit-array right 
  @num_rot times       
* Arguments: data - bit_array_ty, num_rot - number of times to do the rotation.
* Return value: bit_array_ty
* Notes: 

* Time Complexity: NA
*******************************************************************************/
bit_array_ty RotR(bit_array_ty data, const unsigned int num_rot);


/******************************************************************************
* Function Description: rotates the contents of the bit-array left 
  @num_rot times.       
* Arguments: data - bit_array_ty, num_rot - number of times to do the rotation.
* Return value: bit_array_ty
* Notes: 

* Time Complexity: NA
*******************************************************************************/
bit_array_ty RotL(bit_array_ty data, const unsigned int num_rot);


/******************************************************************************
* Function Description: returns number of set bits in the array
* Arguments: - data - bit_array_ty.
* Return value: number of set bits in the array
* Notes: 

* Time Complexity: NA
*******************************************************************************/
unsigned int CountOn(bit_array_ty data);


/******************************************************************************
* Function Description: returns number of unset bits in the array       
* Arguments: - data - bit_array_ty.
* Return value: number of unset bits in the array
* Notes: 

* Time Complexity: NA
*******************************************************************************/
unsigned int CountOff(bit_array_ty data);



#endif /* __BIT_ARRAY_H__ */
