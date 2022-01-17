/*  API changelog

Version 1.2
	*Added informative Notes to following functions:
		- FSPoolInit - usage notes, failure and performance notes
		- FSPoolFree - undefined case.
		- FSPoolAlloc - failure notes.
		- FSPoolCalcSize - usage notes.
	*Added Time Complexities to all functions.

Version 1.1
	* FSPoolCountFree was updated to FSPoolCountFreeChunks
	* in function FSPoolInit the argument element_size was changed to chunk_size
	* the name of the struct was changed from fsp to fixed_size_pool
--------------------------------------------------------------------------------
Version 1.0
	* API after agreement
--------------------------------------------------------------------------------
*/

#ifndef __FS_POOL_H__
#define __FS_POOL_H__

#include <stddef.h> /*size_t*/

typedef struct fixed_size_pool fsp_ty;


/* 	Notes: memory_size should be acquired by calling FSPoolCalcSize.
		   Data should be aligned to word size by the user, otherwise 
		   performance may be diminished, in some systems a failure may occur.
		   chunk_size should be word size at the very least. 
* 	Time Complexity: O(n) - memory_size / chunk_size */
fsp_ty *FSPoolInit(void *memory, size_t memory_size, size_t chunk_size);


/* 	Notes: returns NULL pointer in case of fully allocated pool.
	Time Complexity: O(1) */
void *FSPoolAlloc(fsp_ty *fs_pool);


/* 	Notes: if sent chunk to free is not in range - undefined behaviour
Time Complexity: O(1) */  
void FSPoolFree(fsp_ty *fs_pool, void *chunk_to_free);


/* 	Notes: 
	Time Complexity: O(n) */
size_t FSPoolCountFreeChunks(fsp_ty *fs_pool);


/* 	Notes: chunk_size should be word size at the very least.
	Time Complexity: O(1) */
size_t FSPoolCalcSize(size_t num_chunks, size_t chunk_size);


#endif /*__FS_POOL_H__*/
