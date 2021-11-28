#include <stdio.h>/* scanf printf puts */
#include <assert.h>/* assert */

#include "ws6.h"

#define CHAR_BITS 8/*size of character*/
#define INT_BITS ( sizeof(int) * CHAR_BITS)

/****************************************************************************/
/*USEFULL FUNCTIONS THAT I USE IN THE PROGREM*/

/*Gets an integer and subtracts it by 1*/
static unsigned int subtractOne(unsigned int x);

/*Gets a number and checks if it is divisible by 16*/
static unsigned int DivBy16(int n);
/****************************************************************************/

long Pow2( unsigned int num,  unsigned int y)
{	
	return (num << y);
}

int CheckPowerTwoWithLoop(unsigned int n)
{  
    unsigned int count = 0;
    unsigned int check = 1;
    
    unsigned int temp;
    int i = 0;
    
    for(i = 1; i < sizeof(int)*8; i++ )
    {
        temp = n & (check << i);
        if(0 != temp)
        {
            ++count;
        }
    }
    if (1 == count)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int CheckPowerTwo(unsigned int n)
{
	/*check if the binary val equal to something like 11111 */
	if ((n & (n - 1)) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void AddOneToNum(int *number)
{	
	/*Using Tilda brings me the following number along with a sign - */
	*number = -~(*number);	
}

void OnlyWithTreeBytes(unsigned int *array_of_numbers, unsigned int len_of_array)
{
	unsigned int *start_of_arry = NULL;
	unsigned int count = 0;
	
	start_of_arry = array_of_numbers;
	
	while (start_of_arry < (array_of_numbers + len_of_array - 1))
	{
		count = CountBitsOne( *start_of_arry );
		
		if (count == 3)
		{
			printf("%d\n", *start_of_arry);
		}
		
		++start_of_arry;
	}
	
	start_of_arry = NULL;
}

unsigned int CountBitsOne(unsigned int number)
{
    unsigned int count = 0;
    while (number) 
    {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

unsigned int ByteMirrorLoop(unsigned int num)
{
    unsigned int count = (INT_BITS -1); 
    unsigned int tmp = num;         /* Assign num to the tmp*/ 
	     
    num >>= 1; /* shift num because LSB already assigned to tmp */
    
    while(num)
    {
       tmp <<= 1;  /* shift the tmp because alread have the LSB of num */  
	      
       tmp |= num & 1; /* putting the set bits of num */
       
       num >>= 1; 
       
       --count;
    }
    
    tmp <<= count; /* when num become zero shift tmp from the remaining counts */
    
    return tmp;
}


unsigned int ByteMirrorNoLoop(unsigned int num)
{
	num = (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));
	num = (((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2));
	num = (((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4));
	num = (((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8));

	return((num >> 16) | (num << 16));
}


int checkOnBytesAnd(unsigned char ch)
{
	return ((ch & (1<<1) && (ch &(1 << 5))));
}

int checkOnBytesOr(unsigned char ch)
{
	return ((ch & (1<<1) || (ch &(1 << 5))));
}

unsigned char SwapBytes(unsigned char ch)
{
	;
}

static unsigned int subtractOne(unsigned int x)
{
    int m = 1;
 
    /* Flip all the set bits
    until we find a 1*/
    while (!(x & m)) 
    {
        x = x ^ m;
        m <<= 1;
    }
 
    /* flip the rightmost 1 bit*/
    x = x ^ m;
    return x;
}

static unsigned int DivBy16(int n)
{
    return (((n >> 4) << 4) == n);
}

unsigned int LowerNumberDividedBy16(unsigned int num)
{
	while ((num > 15) && (DivBy16(num) == 0))
	{
		num = subtractOne(num);	
	}
	return num;
}














