#include<assert.h>
#include<stddef.h>
#include<limits.h>
#include <stdio.h>
#include "fs_fool.h"

static Alignment(chunk_size);

struct fixed_size_pool
{
    size_t first_block;
    /*DEBUG_ONLY(size_t size_mem);*/
} ;


 /* need to normalize chunk_size to be word aligned */
    
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
    
    chunk_size = Alignment(chunk_size);

    count = (memory_size - sizeof(fsp_ty)) / chunk_size;

    new_fs_pool = (fsp_ty *)memory;
    new_fs_pool->first_block = 0;

    runner = (char *)(new_fs_pool->first_block + 1);

    for (i = 0; i < count; i++)
    {
        *(size_t *)runner += chunk_size;

        runner += chunk_size;
    }
    
    *(size_t *)runner = ULONG_MAX;
}

/*  handle empty freelist */
    
    /*  save freelist[first_blk] address in local temp var */

    /*  copy first_blk */

    /*  progression: first_blk = next */

    /*  convert copy to pointer and return */
void *FSPoolAlloc(fsp_ty *fs_pool)
{
    assert(fs_pool);
    char *runner = (char *)fs_pool;

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
    assert(fs_pool);
    assert((chunk_to_free >= fs_pool) && ((char *)chunk_to_free <=
                                     (char *)(fs_pool + fs_pool->first_block)));
   
    *(size_t *)chunk_to_free = fs_pool->first_block;

    fs_pool->first_block = chunk_to_free;
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
        tmp = *(size_t)(fs_pool + sizeof(fs_pool) + tmp);
   }
   
   return count;
}

/* assert chunk_size > sizeof(size_t) */

/*  calculate size of num_chunks * chunk_size + size of fsp_ty without 
the pointer (offset until pointer) */

/* need to make sure chunk_size starts at word boundary */
size_t FSPoolCalcSize(size_t num_chunks, size_t chunk_size)
{
    assert(chunk_size > sizeof(size_t));

    chunk_size = Alignment(chunk_size);
       
    size_t ret_val = (chunk_size * num_chunks) + sizeof(fsp_ty);

    return ret_val;   
}


static Alignment(chunk_size)
{
    while (chunk_size % 8 != 0)
    {
        ++chunk_size;
    }
    return chunk_size;
}