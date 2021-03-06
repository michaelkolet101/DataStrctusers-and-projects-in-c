#include<assert.h>	/* ALEX: ASSERT.H ETC.*/
#include<stddef.h>
#include<limits.h>
/* ALEX: SHOULD LEAVE A LINE BETWEEN GENERAL AND LOCAL LIBRARIES   */
#include <stdio.h>	/* ALEX: WHY IS THIS NEEDED? */
#include "fs_pool.h"

#ifndef NDEBUG
	#define DEBUG_ONLY(exp) exp;
#else
	#define DEBUG_ONLY(exp) 
#endif
/******************************************************************************/

static size_t RoundUp(size_t mem_size, size_t chunk_size);


struct fixed_size_pool
{
    size_t first_block;	/* ALEX: WHAT ABOUT DEBUG_ONLY pool_size? */
};




/******************************************************************************/


fsp_ty *FSPoolInit(void *memory, size_t memory_size, size_t chunk_size)
{
	/*  use start of memory to keep fsp ds metadata initialize metadata: */   
    fsp_ty *ret_val = (fsp_ty *)memory;
    
    char *current = NULL;
    char *end = (char *)memory -(memory_size % chunk_size) + memory_size - chunk_size; 
    
    assert(memory);
    /*assert(2 * chunk_size < mem_size);*/	
    assert(sizeof(size_t) <= chunk_size);
    
    ret_val->first_block = RoundUp(sizeof(fsp_ty), chunk_size);
    
    current = (char *)memory + ret_val->first_block;
	
	/*  initialize each freelist's index content with the index of the next one
										the final index points to size_t MAX */
    while (current != end)
    {
    	*(size_t *)current = current - (char *)memory + chunk_size;
    	current += chunk_size;
    }
    
    *(size_t *)current = ULONG_MAX;
    
    return ret_val;
}

void *FSPoolAlloc(fsp_ty *fs_pool)
{
    char *tmp = (char *)fs_pool;
    
	assert(fs_pool);

	/*  handle empty freelist */	
    if (0 == FSPoolCountFreeChunks(fs_pool))	/* ALEX:  'FSPoolCountFreeChunks' IS AN O(n) FUNCTION, WHY USE IT HERE?
    											 IT IS LIKE USING Size INSTEAD OF IsEmpty, YOU COULD JUST USE (ULONG_MAX == fs_pool->first_block) */
    {
        return NULL;
    }
    
	/*  save freelist[first_blk] address in local temp var */
    tmp = tmp + (char)fs_pool->first_block;
	
	/*  copy first_blk */
	fs_pool->first_block = *(size_t *)tmp ;

	/*  progression: first_blk = next */

	/*  convert copy to pointer and return */
		
    return tmp; 
}
 
void FSPoolFree(fsp_ty *fs_pool, void *chunk_to_free)
{
    
    size_t index = 0;
    
    assert(fs_pool);
    assert(chunk_to_free);
    /*  assert given pointer is part of the pool"
    chunk >= freelist && chunk <= (char *)freelist + pool_size  */
   /* assert((chunk_to_free >= fs_pool) && ((char *)chunk_to_free <=
                                     (char *)(fs_pool + fs_pool->first_block)));*/
 	
 	/* copy first_blk into chunk */
 	index = (char *)chunk_to_free - (char *)fs_pool;
   
   /* point first_blk at chunk */
    *(size_t *)chunk_to_free = fs_pool->first_block;

    fs_pool->first_block = index;
}

size_t FSPoolCountFreeChunks(fsp_ty *fs_pool)
{
	size_t count = 0;
	size_t next_idx = 1;
	char *current = NULL;

	assert(fs_pool);
	
/*  save first_blk to temp variable, create counter. */
	next_idx = fs_pool->first_block;
	current = (char *)fs_pool + next_idx;
	
/*  while temp isnt containing size_t max - dereference to that address */	
	while (ULONG_MAX != next_idx)
	{
		/*  prgression: save temp with current address data */
		
		current = (char *)fs_pool + next_idx;
		next_idx = *(size_t *)current;
		/*  update counter */
		++count;
	}

/*  when while ends, return count; */    
	return count;
}

size_t FSPoolCalcSize(size_t num_chunks, size_t chunk_size)
{
    size_t ret_val = 0;
    
    /* assert chunk_size > sizeof(size_t) */
    assert(chunk_size > sizeof(size_t));
    
    /*  calculate size of num_chunks * chunk_size + size of fsp_ty without 
the pointer (offset until pointer) */   
    ret_val = (chunk_size * num_chunks) + sizeof(fsp_ty);

    return ret_val;   
}

static size_t RoundUp(size_t mem_size, size_t chunk_size)
{
	while (0 != (mem_size % chunk_size)) /* ALEX: NOT SURE YOU NEED 'WHILE' HERE, IT IS A MATTER OF A SIMPLE IF AND A LITTLE CALCULATION */
	{
		++mem_size; 
	}    
       
    return mem_size;
}







