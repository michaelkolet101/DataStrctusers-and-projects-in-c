/*******************************************************************************
Data Structures queue

Written by: Michael Kolet
Reviewd by: Olga

Functions for WS
*******************************************************************************/
#include <string.h>/*memmove*/
#include <stddef.h>
#include <assert.h> /* assert */
#include <stdlib.h>	/* malloc free */

#include "c_buffer.h"
#include "utils.h"

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
	cbuffer_ty *new_cbuffer = (cbuffer_ty *)malloc(OFFSETOF(cbuffer_ty, buffer) + sizeof(char) * bufsiz);
	
	ALLOC_CHK(new_cbuffer , NULL, NULL);
	
	new_cbuffer->read_idx = 0;
	new_cbuffer->size = 0;
	new_cbuffer->bufsiz = bufsiz;
	new_cbuffer->buffer[0] = 0;
	
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
	
	size_t tmp_count = 0;
	
	assert(cbuffer);
	assert(dest);

	if (count > cbuffer->size)
	{
		count = cbuffer->size;
	}
	
	if (count < cbuffer->bufsiz - cbuffer->read_idx)
	{
		tmp_count = count;
	}
	else
	{
		tmp_count = cbuffer->bufsiz - cbuffer->read_idx;
	}
	memcpy(dest, cbuffer->buffer + cbuffer->read_idx, tmp_count);
	
	if (count - tmp_count > 0)
	{
		count = count - tmp_count;
	}
	  
	memcpy((char *)dest + tmp_count, cbuffer->buffer,  count);
	
	cbuffer->read_idx = (cbuffer->read_idx + count) % cbuffer->bufsiz;
	cbuffer->size -= count;
	
	return count;
}

ssize_t CBufferWrite(cbuffer_ty *cbuffer, const void *src, size_t count)
{
	size_t tmp_count = 0;

	assert(cbuffer);
	assert(src);

	if (count > CBufferFreeSpace(cbuffer))
	{
		count = CBufferFreeSpace(cbuffer);
	}
	
	if (count < cbuffer->bufsiz - cbuffer->read_idx)
	{
		tmp_count = count;
	}
	else
	{
		tmp_count = cbuffer->bufsiz - cbuffer->read_idx;
	}
	memcpy((cbuffer->read_idx + cbuffer->size) % cbuffer->bufsiz + cbuffer->buffer,
																			src, 
																			tmp_count);

	if (count - tmp_count > 0)
	{
		count = count - tmp_count;
	}		
	/* if read_idx + size + count is smaller than bufsiz, don't copy, 
	otherwise, copy the remain bytes */	   
	memcpy(cbuffer->buffer,  src, count);
		
	cbuffer->size += count;

	return count;
}

