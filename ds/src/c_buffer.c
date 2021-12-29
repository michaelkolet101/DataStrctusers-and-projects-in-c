/*******************************************************************************
Data Structures queue

Written by: Michael Kolet
Reviewd by: Tal

Functions for WS
*******************************************************************************/
#include <string.h>/*memmove*/

#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc free */

#include "../include/c_buffer.h"
#include "../include/utils.h"


#define SUCCESS 0
#define FAIL 1

struct cbuffer
{
	size_t read_idx;
	size_t size;
	size_t bufsiz; 
	char buffer[1];
};

/***************************Macros Functions *********************************/


cbuffer_ty *CBufferCreate(size_t bufsiz)
{
	cbuffer_ty *new_cbuffer = (cbuffer_ty *)malloc(sizeof(cbuffer_ty) + (sizeof(char) * bufsiz));
	
	ALLOC_CHK(new_cbuffer , NULL);
	
	new_cbuffer  -> read_idx = 0;
	new_cbuffer  -> size = 0;
	new_cbuffer  -> bufsiz = bufsiz;
	new_cbuffer  -> buffer[0] = 0;
	
	return new_cbuffer;
}

void CBufferDestroy(cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	free(cbuffer);
}

size_t CBufferFreeSpace(const cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	return (cbuffer -> bufsiz) - (cbuffer -> size);
}

size_t CBufferBufsiz(const cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	return cbuffer -> bufsiz;
}

int CBufferIsEmpty(const cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	return (cbuffer -> size == 0);
}

ssize_t CBufferRead(cbuffer_ty *cbuffer, void *dest, size_t count)
{
	ssize_t num_of_read_bytes = 0;
	size_t index = cbuffer->read_idx;
	
	assert(cbuffer);
	assert(dest);
	
	if ((count > cbuffer->bufsiz) && (0 != cbuffer -> size))
	{
		count = cbuffer->bufsiz;
	}
	else if(0 != cbuffer -> size)
	{
		memmove(dest, (void *)&(cbuffer->buffer[index]), count);
		cbuffer -> size -= count;
		num_of_read_bytes = count;
		index = (index + count) % (cbuffer -> bufsiz);
	}
	
	/* the version with loop */
	
/*	while ((0 != count) & (0 != cbuffer -> size))
	{
		memmove(dest, (void *)&(cbuffer->buffer[index]), (size_t)1);
		index = (index + 1) % (cbuffer -> bufsiz);
		++num_of_read_bytes;
		cbuffer -> size--;
		--count;
		
	}
*/
	
	return num_of_read_bytes;
}

ssize_t CBufferWrite(cbuffer_ty *cbuffer, const void *src, size_t count)
{
	ssize_t num_of_copy_bytes = 0;
	size_t index = cbuffer->read_idx;
	
	assert(cbuffer);
	assert(src);
	
	if ((CBufferFreeSpace(cbuffer)) > 0 && (count > cbuffer->bufsiz))
	{
		count = cbuffer->bufsiz;
		
	}
	else if(CBufferFreeSpace(cbuffer) > 0)
	{
		memmove((void *)&(cbuffer->buffer[index]), src, count);
		cbuffer -> size += count;
		num_of_copy_bytes = count;
		index = (index + count) % (cbuffer -> bufsiz);
	}
	
	/* the version with loop */
	
/*	while ((0 < count) && (CBufferFreeSpace(cbuffer) > 0))
	{
		memmove((void *)&(cbuffer->buffer[index]), src, (size_t)1);
		index = (index + 1) % (cbuffer -> bufsiz);
		cbuffer -> size++;
		++num_of_copy_bytes;
		--count;
	}
*/	
	return num_of_copy_bytes;
}


