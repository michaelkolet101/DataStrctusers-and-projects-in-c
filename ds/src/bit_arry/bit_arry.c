/*******************************************************************************
Data Structures WorkSheet 1: bit arry.

Written by: Michael Kolet
Reviewd by: meirav

Functions for WS
*******************************************************************************/
#include <stdio.h> 
#include <assert.h> /* assert */

#include "bit_arry.h"

#define INT_BITS ( sizeof(int) * CHAR_BITS)
#define CHAR_BITS 8/*size of character*/



/* Definitions */
#define BIT_ARRAY_MSB_MASK (bit_array_ty)0x8000000000000000
#define BIT_ARRAY_LSB_MASK (bit_array_ty)0x0000000000000001
#define BITS_IN_BYTE 8
#define BITS_IN_WORD 64

/*macro for but mirror lut*/
#define R2(n)     n,     n + 2*64,     n + 1*64,     n + 3*64
#define R4(n) R2(n), R2(n + 2*16), R2(n + 1*16), R2(n + 3*16)
#define R6(n) R4(n), R4(n + 2*4 ), R4(n + 1*4 ), R4(n + 3*4 )

#define UNUSED(x)	{(void)x;}

/* Function for printing a binary maskber */
static void PrintInBinary(unsigned char n);
bit_array_ty MirrorLut(bit_array_ty data);
/***************************************************************************/

bit_array_ty SetAll(bit_array_ty data)
{
	UNUSED(data)
	return (bit_array_ty)~0;
}

bit_array_ty ResetAll(bit_array_ty data)
{
	UNUSED(data)
		  
	return  (bit_array_ty)0;
}

char *ToString(bit_array_ty data, char *dest)
{	
	char *start = dest;
	size_t i = 0;
	
	assert(dest);
	
	for (i = 0; i < BITS_IN_WORD; ++i)
	{
		if ((data & (BIT_ARRAY_MSB_MASK >> i)))
		{
			*dest = '1';
		}
		else
		{
			*dest = '0';
		}
		
		++dest;
	}
	
	*dest = '\0';
	
	return start;
}


bit_array_ty SetOn(bit_array_ty data, const unsigned int idx)
{
	unsigned char mask = 1;
	
	mask = mask << (idx) ;
	
	return (data | mask);
}

bit_array_ty SetOff(bit_array_ty data, const unsigned int idx)
{
	unsigned char mask = 1;
	
	mask = mask << (idx);
	mask = ~mask;

	return (data & mask);
}

bit_array_ty SetBit(bit_array_ty data, const unsigned int idx, const unsigned int val)
{
	assert(val < 2);
	
	if (1 == val)
	{
		data = SetOn(data, idx);
	}
	else
	{
		data = SetOff(data, idx);
	}
	
	return data;
}

int GetVal(bit_array_ty data, const unsigned int idx)
{
	bit_array_ty mask = 1;
	
	mask = mask << (idx);
	mask = mask & data;
	
	return (int)(mask >> (idx));
}

bit_array_ty Flip(bit_array_ty data, const unsigned int idx)
{
	bit_array_ty mask = 0;
	
	mask = GetVal(data, idx);
	
	if (mask)
	{
		mask = SetOff(data, idx);
	}
	else
	{
		mask = SetOn(data, idx);
	}
	
	return mask;
}

unsigned int CountOn(bit_array_ty data)
{
	unsigned int count = 0;
	
	while (0 != data)
	{
        count += data & 1;
        data = data >> 1;
    }
    
    return count;
}

unsigned int CountOff(bit_array_ty data)
{
	unsigned int count = BITS_IN_WORD;
	
	while (0 != data) 
	{
        count -= data & 1;
        data = data >> 1;
    }
    
    return count;
}

bit_array_ty Mirror(bit_array_ty data)
{
	bit_array_ty count = BITS_IN_WORD - 1;
	bit_array_ty reverse_mask = data;
      
    data = data >> 1; 
    
    while (0 != data)
    {
       reverse_mask = reverse_mask << 1;       
       reverse_mask = reverse_mask |(data & 1);
       data = data >> 1;
       --count;
    }
    
    reverse_mask = reverse_mask << count;
    
    return reverse_mask;
}

bit_array_ty RotR(bit_array_ty data, const unsigned int num)
{
	int mask = -1;
	unsigned int count = num;
	
	while (count)
	{
		mask = GetVal(data, 0);
		data = data >> 1;
		--count;
		
		if (mask)
		{
			data = SetOn(data, BITS_IN_WORD - 1);	
		}
	}
	
	return data;
}

bit_array_ty RotL(bit_array_ty data, const unsigned int num)
{
	int mask = -1;
	unsigned int count = num;
	
	while (count)
	{
		mask = GetVal(data, BITS_IN_WORD - 1);
		data = data << 1;
		--count;
		
		if (mask)
		{
			data = SetOn(data, 0);	
		}
	}
	
	return data;
}

bit_array_ty MirrorLut(bit_array_ty data)
{
	unsigned int lookuptable[256] = { R6(0), R6(2), R6(1), R6(3) };
	int reverse_num = 0;
	reverse_num = lookuptable[data & 0xff]<<24 |  
                   lookuptable[(data >> 8) & 0xff]<<16 | 
                   lookuptable[(data >> 16 ) & 0xff]<< 8 |
                   lookuptable[(data >>24 ) & 0xff] ;
	
	return reverse_num;
}

unsigned int CountOn(bit_array_ty data)
{
	unsigned int lookuptable[256] = { B6(0), B6(1), B6(1), B6(2) };
	
	unsigned int count = lookuptable[data & 0xff] +
                         lookuptable[(data >> 8) & 0xff] + 
                         lookuptable[(data >> 16) & 0xff] + 
                         lookuptable[(data >> 24) & 0xff];
    
    return count;
}








