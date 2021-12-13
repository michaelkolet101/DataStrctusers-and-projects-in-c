#include <stdio.h> 
#include <assert.h> /* assert */

#include "bit_arry.h"

#define INT_BITS ( sizeof(int) * CHAR_BITS)
#define CHAR_BITS 8/*size of character*/


/* Function for printing a binary number */
static void PrintInBinary(unsigned char n);
/***************************************************************************/

bit_array_ty SetAll(bit_array_ty data)
{
	return ~data;
}

bit_array_ty ResetAll(bit_array_ty data)
{
	  size_t flag = 0;
	  
	  return  flag & data;
}

char *ToString(bit_array_ty data, char *dest)
{
	sprintf(dest,"%ld", data);
	
	return dest;
}

bit_array_ty SetOn(bit_array_ty data, const unsigned int idx)
{
	unsigned char flag = 1;
	
	flag = (flag << (idx - 1));
	
	return (data | flag);
}

bit_array_ty SetOff(bit_array_ty data, const unsigned int idx)
{
	unsigned char flag = 1;
	
	flag = (flag << (idx - 1));
	flag = ~flag;

	return (data & flag);
}

bit_array_ty SetBit(bit_array_ty data, const unsigned int idx, const unsigned int val)
{
	if (val)
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
	int num = 1;
	
	num = num << (idx - 1);
	num = num & data;
	
	return (num >> (idx - 1));
}

bit_array_ty Flip(bit_array_ty data, const unsigned int idx)
{
	size_t num = 0;
	
	num = GetVal(data, idx);
	
	if (num)
	{
		num = SetOff(data, idx);
	}
	else
	{
		num = SetOn(data, idx);
	}
	
	return num;
}

unsigned int CountOn(bit_array_ty data)
{
	unsigned int count = 0;
	
	while (data) 
	{
        count += data & 1;
        data = data >> 1;
    }
    return count;
}

unsigned int CountOff(bit_array_ty data)
{
	unsigned int count = 8;
	
	while (data) 
	{
        count -= data & 1;
        data = data >> 1;
    }
    return count;
}

bit_array_ty Mirror(bit_array_ty data)
{
	long unsigned int count = sizeof(data) * 8 - 1;
    long unsigned int reverse_num = data;
      
    data >>= 1; 
    
    while(data)
    {
       reverse_num <<= 1;       
       reverse_num |= data & 1;
       data >>= 1;
       count--;
    }
    reverse_num <<= count;
    return reverse_num;
}

bit_array_ty RotR(bit_array_ty data, const unsigned int num_rot)
{
	int num = -1;
	unsigned int count = num_rot;
	
	while (count)
	{
		num = GetVal(data, 0);
		data = data >> 1;
		--count;
		
		if (num)
		{
			data = SetOn(data, 63);	
		}
	}
	
	return data;
}

bit_array_ty RotL(bit_array_ty data, const unsigned int num_rot)
{
	int num = -1;
	unsigned int count = num_rot;
	
	while (count)
	{
		num = GetVal(data, 63);
		data = data << 1;
		--count;
		
		if (num)
		{
			data = SetOn(data, 0);	
		}
	}
	
	return data;
}
 /* Function for printing a binary number */
static void PrintInBinary(unsigned char n)
{
	int index;
	
	for (index = (INT_BITS - 1) ; index >= 0 ; --index)
	{
		(n & (1 << index))? printf("1"): printf("0");	
	}
	puts("\n");
}













