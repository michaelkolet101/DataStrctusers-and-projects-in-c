#include <stddef.h> /*size_t*/
#include <assert.h> /*assert*/

#include "vs_pool.h"
#include "utils.h"
#include<limits.h>
#include <stddef.h>

struct vs_pool;


static ptrdiff_t GetMetaDataIMP(void *data);
static void DefragmentIMP(vs_pool_ty *vs_pool);
static vs_pool_ty * MemoryIntegrationIMP(vs_pool_ty *first, vs_pool_ty *seconde);
static ptrdiff_t GetChunkSizeIMP(vs_pool_ty *vs_pool);
static size_t AbsoluteIMP(vs_pool_ty *val);
static size_t AlignmentIMP(size_t size);
void InitEndIMP(void *mem, size_t size);
static vs_pool_ty *OverSupplyIMP(vs_pool_ty *ptr_to_cunk, size_t size);
void *MemoryExactlyIMP(void *ptr_to_cunk);
static vs_pool_ty *NextChunkIMP(vs_pool_ty *curr);
/****************************************************************/

vs_pool_ty *VSPoolInit(void *memory ,size_t memory_size)
{
	void *new_pool = NULL;
	
	assert(memory);
	
	/*. Defines a pointer for a pool of our structure type and compares it to memory*/
	new_pool = memory;
	
	/*. The first place after the structure - 
	its value will be equal to the entire size of the memory*/
	*(ptrdiff_t *)new_pool = memory_size;
	
	InitEndIMP(new_pool, memory_size);
	
	/* We will return the pointer we defined*/
	return new_pool;
}

/**************************************************************/

void *VSPoolAlloc(vs_pool_ty *vs_pool, size_t chunk_size)
{
	
	/* Create a pointer to the pool.*/
	void *ptr_to_pool = NULL;
	void *ret_val = NULL;
	
	assert(vs_pool);
	
	/* Word size AlignmentIMP to chunk_size*/
    chunk_size = AlignmentIMP(chunk_size);
    
    ptr_to_pool = (void *)vs_pool;
    
    /*while not end of memory*/
    while (*(size_t *)ptr_to_pool != END)
    {
    	/*  If there is a number exactly the size of the memory the user wants*/
    	if (*(size_t *)ptr_to_pool == chunk_size)
    	{
    		ret_val = MemoryExactlyIMP(ptr_to_pool);
			 
			return ret_val;
    	} 	
    	
    	/* If there is a negative number or the number is smaller
    								 than the requested memory size*/
		if ((*(ptrdiff_t *)ptr_to_pool < 0) || (*(ptrdiff_t *)ptr_to_pool < (ptrdiff_t)chunk_size))
		{
			/*We will walk to the next metadata*/
			ptr_to_pool = NextChunkIMP(ptr_to_pool);
		}
		
    	/*If the size requested by the user is smaller than the
    								 size of the memory_size*/
	 	if (*(size_t *)ptr_to_pool > chunk_size)
	 	{
	 		ret_val =  (char *)ptr_to_pool + sizeof(ptrdiff_t);
	 		
	 		ptr_to_pool = OverSupplyIMP(ptr_to_pool, chunk_size);
			
			/*Return the pointer ret_val*/
			return ret_val;
	 	}
    }
    return NULL;   
}

/***********************************************************/

void VSPoolFree(void *chunk_to_free)
{
	/*Going a step back*/
	chunk_to_free = (char *)chunk_to_free - sizeof(ptrdiff_t);
	
	/*Makes dereference and changes the value there from negative to positive*/
	*(char *)chunk_to_free *= -1;
}

/********************************************************/

size_t VSPoolBiggestChunk(vs_pool_ty *vs_pool)
{
	
	/*1.	We will define a max = 1*/
	ptrdiff_t max = 0;
	
	/*2.	We will define a run pointer to point on first */
	void *runner = vs_pool;
	
	/*3.	while the value of a run is not equal to END*/
	while (*(size_t *)runner != END)
	{
		/*We will check if the value of a runner is greater than the max*/
		if (*(char *)runner > max)
		{
			/*If yes then max will be equal to the new value*/
			max = *(char *)runner;
		}
		/*We will promote the runner to the next place*/
		runner = NextChunkIMP(runner);
	}
	return max;
}

/*********************************************************/

static vs_pool_ty *NextChunkIMP(vs_pool_ty *curr)
{

	/*1. Defines a ret pointer*/
	char *ret_val = NULL;
	
	/*2. Compares ret to the pointer we got*/
	ret_val = (char *)curr;
	
	/*3. Adds him his value*/
	ret_val = ret_val + (*ret_val);
	
	/*4. Adds to it the size of the meta data*/
	ret_val = ret_val + sizeof(ptrdiff_t);
	
	/*5. Returns it to the user*/
	return (vs_pool_ty *)ret_val;
}

/***********************************************************/

static ptrdiff_t GetChunkSizeIMP(vs_pool_ty *vs_pool)
{
	
	ptrdiff_t sum = 0;
	/*1.Loop to the end of the array*/
	while (*(char *)vs_pool =! END)
	{
		/*2.Take the value of the pointer, make it an AbsoluteIMP value 
												and add it to SUM*/
		sum += AbsoluteIMP(vs_pool);
		
		/*3.Advanced to the next meta-data*/
		vs_pool = NextChunkIMP(vs_pool);
	}
	
	/*4.Exit the loop and return the SUM*/
	return sum;
}

/****************************************************/

static vs_pool_ty * MemoryIntegrationIMP(vs_pool_ty *first, vs_pool_ty *seconde)
{
/*
1. The value of the first voter will be equal to the value of the first and another*/
	*(char *)first = *(char *)first + *(char *)seconde;
/*2. We will return the first pointer*/
	return first;
}

/*******************************************************/

static void DefragmentIMP(vs_pool_ty *vs_pool)
{
/*1. We will run with the pointer we got until the end of the array*/
	while (END != *(char *)vs_pool)
	{
		/*2. If the first gunk is available and also the next after its*/
		if ((0 < *(char *)vs_pool) && (0 < *(char *)NextChunkIMP(vs_pool)))
		{
			/*3. Send them to MemoryIntegrationIMP()*/
			MemoryIntegrationIMP(vs_pool, NextChunkIMP(vs_pool));
		}
		/*4. move on to the next meta-data*/
		vs_pool = NextChunkIMP(vs_pool);
	}
}

/*********************************************************/

static size_t AbsoluteIMP(vs_pool_ty *val)
{
	if (*(char *)val < 0)
	{
		return -(*(char *)val);
	}
	return ;
}

/************************************************************/

static size_t AlignmentIMP(size_t size)
{
	size = (char)size;
	
	while (size % sizeof(double) != 0)
	{
		++size;
	}
	return (size_t)size;
}

/*************************************************************/

void InitEndIMP(void *mem, size_t size)
{
	char *ptr = NULL;  
	
	ptr = (char *)mem + size;
	
	*(ptrdiff_t *)ptr = END;
}

/***********************************************************/

void *MemoryExactly(void *ptr_to_cunk)
{
	ptrdiff_t *curr = (ptrdiff_t *)ptr_to_cunk;
	
	/*We will make the content of the pointer to negative*/
	*curr= -(*curr);
	
	/* We will add ptrdiff to the pointer and give it to the user*/
	curr = curr + sizeof(ptrdiff_t);
	
	return (void *)curr;
}

/***********************************************************/

static vs_pool_ty *OverSupplyIMP(vs_pool_ty *ptr_to_cunk, size_t size)
{
	/*save the size of the chunk at tmp var*/
	ptrdiff_t *tmp = ()*ptr_to_cunk;
	
	/*Changes the value of the pointer to the complete 
										negative value that the user requested*/
	*ptr_to_cunk = -size;
	
	/*Advances with the pointer the amount the user wanted and ptrdiff more*/
	ptr_to_cunk = NextChunkIMP(ptr_to_cunk);
	
	/*Changes the value of the pointer to be equal to the temp less than
												 the user requested*/
	*ptr_to_cunk = tmp - size;
	
	return ptr_to_cunk;
}

static ptrdiff_t GetMetaDataIMP(void *data)
{
	/*Sets a pointer to a char*/
	char *curr = NULL;
	/*Makes him point to the address we got*/
	curr = (char *)data;
	/*Going back makes a dereference and returns to the user*/
	curr = curr - sizeof(ptrdiff_t);
	
	return *curr;
}



