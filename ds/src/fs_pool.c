#include<assert.h>
#include<stddef.h>
#include<limits.h>
#include <stdio.h>
#include "fs_pool.h"

static size_t Alignment(size_t mem_size, size_t chunk_size);


struct fixed_size_pool
{
    size_t first_block;
};


/* not need to normalize chunk_size to be word aligned */

/*  use start of memory to keep fsp ds metadata  
initialize metadata:    */

/*  initialize each freelist's index content with the index of the next one
the final index points to size_t MAX.
eager initialization */

fsp_ty *FSPoolInit(void *memory, size_t memory_size, size_t chunk_size)
{
    char *runner = NULL;
    size_t count = 0;
    size_t i = 0;
    fsp_ty *new_fs_pool = NULL;
    fsp_ty * start = NULL;
    
    memory_size = Alignment(sizeof(fsp_ty), chunk_size);
    
    count = (memory_size - sizeof(fsp_ty)) / chunk_size;

    new_fs_pool = (fsp_ty *)memory;
    new_fs_pool->first_block = 0;

/********************************************************/
	
	start = new_fs_pool + sizeof(fsp_ty);
	
    runner = (char *)start;

    while (0 != (count))
    {
    	*(size_t *)runner = i + 1;
    	
    	runner += chunk_size;
    	
    	--count;
    	++i; 
    }
    
    *runner = -1;
    
    return new_fs_pool;
}

/*  handle empty freelist */

/*  save freelist[first_blk] address in local temp var */

/*  copy first_blk */

/*  progression: first_blk = next */

/*  convert copy to pointer and return */

void *FSPoolAlloc(fsp_ty *fs_pool)
{
    
    char *runner = (char *)fs_pool;
    
	assert(fs_pool);
	
    if (0 == FSPoolCountFreeChunks(fs_pool))
    {
        return NULL;
    }

    runner = runner + sizeof(fs_pool);

    fs_pool->first_block = *runner;

    return runner; 
}

/*  assert given pointer is part of the pool"
    chunk >= freelist && chunk <= (char *)freelist + pool_size  */

/* copy first_blk into chunk */

/* point first_blk at chunk */
    
void FSPoolFree(fsp_ty *fs_pool, void *chunk_to_free)
{
    
    size_t index = 0;
    
    assert(fs_pool);
    assert((chunk_to_free >= fs_pool) && ((char *)chunk_to_free <=
                                     (char *)(fs_pool + fs_pool->first_block)));
 	
 	
 	index = (char *)chunk_to_free - (char *)fs_pool;
   
   
    *(size_t *)chunk_to_free = fs_pool->first_block;

    fs_pool->first_block = index;
}

/*  save first_blk to temp variable, create counter. */

/*  while temp isnt containing size_t max - dereference to that address */
    
/*  update counter */

/*  prgression: save temp with current address data */

/*  when while ends, return count; */    

size_t FSPoolCountFreeChunks(fsp_ty *fs_pool)
{
   size_t count = 0;
   size_t tmp = fs_pool->first_block;

   while (tmp != ULONG_MAX)
   {
       ++count;
        tmp = *(size_t *)(fs_pool + sizeof(fs_pool) + tmp);
   }
   
   return count;
}

/* assert chunk_size > sizeof(size_t) */

/*  calculate size of num_chunks * chunk_size + size of fsp_ty without 
the pointer (offset until pointer) */

/* need to make sure chunk_size starts at word boundary */

size_t FSPoolCalcSize(size_t num_chunks, size_t chunk_size)
{
    size_t ret_val = 0;
    
    assert(chunk_size > sizeof(size_t));
       
    ret_val = (chunk_size * num_chunks) + sizeof(fsp_ty);

    return ret_val;   
}


static size_t Alignment(size_t mem_size, size_t chunk_size)
{
	while (0 != (mem_size % chunk_size))
	{
		++mem_size; 
	}    
       
    return mem_size;
}













