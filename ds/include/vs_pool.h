#ifndef __VS_POOL_H__
#define __VS_POOL_H__
/* ------------API Updates----------------
    -Version 1.0:Approved by mentor (Edited by : Maoz Shechtman )
*/
#include <stddef.h> /*size_t*/
typedef struct vs_pool vsp_ty;

/*Notes:
  Time Complexity :
    */
vsp_ty *VSPoolInit(void *memory ,size_t memory_size);

/*Notes:
  Time Complexity :
    */
void *VSPoolAlloc(vsp_ty *vs_pool, size_t chunk_size);

/*Notes:
  Time Complexity :
    */
void VSPoolFree(void *chunk_to_free);

/*Notes:
  Time Complexity :
    */
size_t VSPoolBiggestChunk(vsp_ty *vs_pool);


#endif /*--VS_POOL_H__*/
