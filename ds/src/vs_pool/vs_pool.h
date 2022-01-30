/* API Log:
    *Version 1.1: Notes updated in all functions */

#ifndef __VS_POOL_H__
#define __VS_POOL_H__

#include <stddef.h> /* size_t */


typedef struct vsp vs_pool_ty;

/*  Notes:  some of the memory will be used to store metadata.
            memory must be alligned to your platform needs (implemented with size of double)
    Time Complexity: O(1)*/
vs_pool_ty *VSPoolInit(void *memory, size_t mem_size);

/*  Notes: if size of chunks is not multiplication of size of double,
           it will be rounded up.
    Return Value: returns NULL if fails. 
    Time Complexity: O(n) (n = number of fragments) */
void *VSPoolAlloc(vs_pool_ty *vs_pool, size_t chunk_size);

/*  Notes: Chunk to free must be an address acquired from VSPoolAlloc.
           free NULL is allowed.
    Time Complexity: O(1)*/
void VSPoolFree(void *chunk_to_free);

/*  Return Value: size_t amount of largest consecutive memory available 
    Time Complexity: O(n)*/
size_t VSPoolCalcLargestChunk(vs_pool_ty *vs_pool);

#endif /* __VS_POOL_H__ */
