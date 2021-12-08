#include <stdio.h> /* scanf printf puts */
#include <string.h> /* strcat */
#include <assert.h> /* assert */
#include <stdlib.h> /*malloc, realloc, free */

#include "ws9.h"





/****************************************************************************/
/*USEFULL FUNCTIONS THAT I USE IN THE PROGRAM*/


void *MemSet(void *source, int ch, size_t n)
{
	int i = 0;
	char *runer = source;

	/*buffer that contain the ch will contain the
	 character as many times as required*/
	char *buffer = (char*)malloc(sizeof(char) * sizeof(size_t));
	
	if (NULL == buffer)
	{
		return NULL;
	}
	
	assert(source);
	
	/*initialization of the buffer in ch */
	for(i = 0; (size_t)i < sizeof(size_t); ++i)
	{
		buffer[i] = ch;
	}
	
	/*Inserting the buffer to the sours with memcpy */
	while (0 < (n / sizeof(size_t))) 
	{
		MemCpy(runer, buffer, sizeof(size_t));	
		runer += sizeof(size_t);
		n -= sizeof(size_t);
	}

	/*	The second loop is for the remainder if the given number is not
	 divided by 8 and it should insert them one by one */
	while (0 < n)
	{
		*runer = ch;
		++runer;
		--n;
	}
	
	free(buffer);	
	
	return source;
}


void *MemCpy(void* dest, const void* src, size_t n)
{
	/*	Defines pointers char and then assign them with dest and src */
    char *ptr_dest = (char *) dest;
    char *ptr_src = (char *) src;
	int i = 0;
	
	/*	The first loop will run up to the number divided by 8 */
    int loops = (n / sizeof(size_t));

	assert(src);
	assert(dest);

    for (i = 0; i < loops; ++i)
    {
		/*	Make a casting for the 8 bytes jumps */
        *((size_t *)ptr_dest) = *((size_t *)ptr_src);
        ptr_dest += sizeof(size_t);
        ptr_src += sizeof(size_t);
    }

	/*	The second loop is for the remainder if the given number is not
	 divided by 8 and it should insert them one by one */
    loops = (n % sizeof(size_t));

    for (i = 0; i < loops; ++i)
    {
        *(char *)ptr_dest = *(char *)ptr_src;
        ++ptr_dest;
        ++ptr_src;
    }

    return dest;
}

void *MemMove(void *dest, const void *src, size_t n)
{
    char *ptr_dest = (char *)dest;
    const char *ptr_src =(const char *)src;
    
	assert(src);
	assert(dest);

	/*Checks which value of pointer is greater: source or 		  	destination*/
	if (ptr_src < ptr_dest)
	{
	/*advance the two pointers to their end*/
		ptr_src += n - 1;
		ptr_dest += n - 1;
		
	/*A loop that ran on the pointer from the end to the beginning*/
		while (n)
		{
			*ptr_dest = *ptr_src;
			--ptr_dest; 
			--ptr_src;
			--n;
		}
	}
	/*A loop that ran from the beginning to the end of the pointers*/
	else
	{
		while (n)
		{
			*ptr_dest = *ptr_src;
			++ptr_dest; 
			++ptr_src;
			--n;
		}
	}

    return dest;
}





















































