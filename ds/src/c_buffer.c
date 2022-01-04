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













/*TODO it's dont work need to make it again!!!*/
ssize_t CBufferRead(cbuffer_ty *cbuffer, void *dest, size_t count)
{
	size_t num_of_read_bytes = 0;
	size_t size_of_buffer = 0;
	size_t index = 0;
	
	assert(cbuffer);
	assert(dest);
	
	size_of_buffer = CBufferBufsiz(cbuffer);
	
	/* circular the index */
	index = ((cbuffer->read_idx) + size_of_buffer - (cbuffer -> size) + 1) % size_of_buffer;
	
	/* checks if the buffer not empty */
	if ((CBufferIsEmpty(cbuffer) == 0) && (count <= size_of_buffer))
	{
		memmove(dest, (void *)&(cbuffer->buffer[index]), count);
		cbuffer -> size -= count;
		num_of_read_bytes += count;
	}
	cbuffer->read_idx = index;
	
	return num_of_read_bytes;
}

/*TODO it's dont work need to make it again!!!*/
ssize_t CBufferWrite(cbuffer_ty *cbuffer, const void *src, size_t count)
{
	ssize_t num_of_copy_bytes = 0;
	size_t index = cbuffer->read_idx;
	size_t size_of_buffer = 0;
	size_t space = 0;
	void *source = NULL;
	
	assert(cbuffer);
	assert(src);
	
	source = (void *)src;
	size_of_buffer = CBufferBufsiz(cbuffer);
	space = CBufferFreeSpace(cbuffer);
	
	if (space < count )
	{
		count = space;
	}
	
	while (count > 0 && (CBufferFreeSpace(cbuffer) > 0))
	{
		index = ((cbuffer->read_idx) + (cbuffer -> size)) % size_of_buffer;
		--count;
		memmove((void *)&(cbuffer->buffer[index]), src, 1);
		src;
		cbuffer -> size++;
		++num_of_copy_bytes;
	}
	
	cbuffer->read_idx = index;

	return num_of_copy_bytes;
}


