#include <stdio.h> /* scanf printf puts */
#include <string.h> /* strcat */
#include <assert.h> /* assert */
#include <stdlib.h> /*malloc, realloc, free */

#include "ws9.h"

#define SUCCESS 0
#define FAIL 1



/****************************************************************************/
/*USEFULL FUNCTIONS THAT I USE IN THE PROGREM*/


void *MemSet(void *s, int c, size_t n)
{
	int i = 0;
	char *runer = s;
	char *buffer = (char*)malloc(sizeof(char) * c);
	
	assert(buffer);
	
	for(i = 0; i < sizeof(size_t); ++i)
	{
		buffer[i] = c;
	}
	
	while (0 < n)
	{
		memcpy(s, buffer, n);	
		++runer;
		--n;
	}
	
	free(buffer);	
}


void* MemCpy(void* dst, const void* src, size_t n)
{
    size_t *ptr_dest = (size_t*) dest;
    size_t *ptr_src = (size_t*) src;
	int index = 0;
    int loops = (n / sizeof(size_t));
    
    for(index = 0; index < loops; ++index)
    {
        *((size_t*)ptr_dest) = *((size_t*)ptr_src);
        ptr_dest += sizeof(size_t);
        ptr_src += sizeof(size_t);
    }

    loops = (n % sizeof(size_t));
    for (int index = 0; index < loops; ++index)
    {
        *ptr_dest = *ptr_src;
        ++ptr_dest;
        ++ptr_src;
    }
    
    return dst;
}

void* MemMove(void *dest, const void *src, size_t n);
{
    char *ptr_dest = (char *)dest;
    const char *ptr_src =( const char*)src;
    size_t i = 0;
    
    /*allocate memory for tmp array*/
    char *tmp  = (char *)malloc(sizeof(char ) * n);
    
    if(NULL == tmp)
    {
        return NULL;
    }
    else
    { 
        /* copy src to tmp array */
        for(i =0; i < n ; ++i)
        {
            *(tmp + i) = *(ptr_src + i);
        }
        
        /*copy tmp to dest*/
        for(i =0 ; i < n ; ++i)
        {
            *(ptr_dest + i) = *(tmp + i);
        
        }
        free(tmp); /*free allocated memory*/
    }
    return dest;
}





















































