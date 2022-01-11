#define OFFSETOF(type, member) (size_t)&(((type *)0)->member)
#define RETURN_AND_FREE_IF_BAD(x, y, z) {if (NULL == x){free(z); return y;}}

#define MAX2(x, y) (x > y ? x : y) 
#define MIN2(x ,y) (x < y ? x : y)

#include <string.h> /* memcpy */
#include <stdio.h>	/* size_t */
#include <assert.h> /* assert */
#include <stdlib.h> /* malloc, free */
#include <sys/types.h> /* ssize_t */


#include "c_buffer.h"

/******************************************************************************/
struct cbuffer
{
	size_t read_idx;
	size_t size;
	size_t bufsiz; 
	char buffer[1];
};
/******************************************************************************/
cbuffer_ty *CBufferCreate(size_t bufsiz)
{
	cbuffer_ty *cbuffer = NULL;
	
	cbuffer = (cbuffer_ty *)malloc(OFFSETOF(cbuffer_ty, buffer) + sizeof(char) * bufsiz);
	RETURN_AND_FREE_IF_BAD(cbuffer, NULL, NULL);/**/
	
	cbuffer->read_idx = 0;
	cbuffer->size = 0;
	cbuffer->bufsiz = bufsiz;
	
	return cbuffer;
}

void CBufferDestroy(cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	free(cbuffer);
	cbuffer = NULL;
}

size_t CBufferFreeSpace(const cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	return cbuffer->bufsiz - cbuffer->size;
}

size_t CBufferBufsiz(const cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	return  cbuffer->bufsiz;
}

ssize_t CBufferRead(cbuffer_ty *cbuffer, void *dest, size_t count)
{
	assert(cbuffer);
	assert(dest);

	if (count > cbuffer->size)
	{
		count = cbuffer->size;
	}
	/* copy count bytes from buffer to dest */
	
	/* if read_idx + count is smaller than bufsiz, copy count bytes from buffer
	 to dest, otherwise, copy only up to bufsiz */
	memcpy(dest,
		   cbuffer->buffer + cbuffer->read_idx,
		   MIN2(cbuffer->bufsiz - cbuffer->read_idx, count));
	
	/* if read_idx + count is smaller than bufsiz, don't copy, 
	otherwise, copy the remain bytes */	   
	memcpy((char *)dest + cbuffer->bufsiz - cbuffer->read_idx,
	 	   cbuffer->buffer, 
		   (size_t)MAX2((int)(count - (cbuffer->bufsiz - cbuffer->read_idx)), 0));
	
	cbuffer->read_idx = (cbuffer->read_idx + count) % cbuffer->bufsiz;
	cbuffer->size -= count;
	
	return count;
}

ssize_t CBufferWrite(cbuffer_ty *cbuffer, const void *src, size_t count)
{
	assert(cbuffer);
	assert(src);

	if (count > CBufferFreeSpace(cbuffer))
	{
		count = CBufferFreeSpace(cbuffer);
	}
	
	/* if read_idx + size + count is smaller than bufsiz, copy count bytes from 
	src to cbuffer, otherwise, copy only up to bufsiz */
	memcpy((cbuffer->read_idx + cbuffer->size) % cbuffer->bufsiz + cbuffer->buffer,
			src, 
			MIN2(cbuffer->bufsiz - cbuffer->read_idx, count));
			
	/* if read_idx + size + count is smaller than bufsiz, don't copy, 
	otherwise, copy the remain bytes */	   
	memcpy(cbuffer->buffer, 
		   src, 
		   (size_t)MAX2((int)(count - (cbuffer->bufsiz - cbuffer->read_idx)), 0));
		
	cbuffer->size += count;

	return count;
}

int CBufferIsEmpty(const cbuffer_ty *cbuffer)
{
	assert(cbuffer);
	
	return !(cbuffer->size);
}
