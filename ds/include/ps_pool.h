/*  API changelog

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


/* Notes:  
* Time Complexity: */
fsp_ty *FSPoolInit(void *memory, size_t memory_size, size_t chunk_size);


/* Notes: 
* Time Complexity: */
void *FSPoolAlloc(fsp_ty *fs_pool);


/* Notes: 
Time Complexity:*/  
void FSPoolFree(fsp_ty *fs_pool, void *chunk_to_free);


/* Notes: 
* Time Complexity: */
size_t FSPoolCountFreeChunks(fsp_ty *fs_pool);


/* Notes: 
* Time Complexity: */
size_t FSPoolCalcSize(size_t num_chunks, size_t chunk_size);


#endif /*__FS_POOL_H__*/