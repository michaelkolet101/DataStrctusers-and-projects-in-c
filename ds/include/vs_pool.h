
#ifndef __FS_POOL_H__
#define __FS_POOL_H__

#include <stddef.h> /*size_t*/


fsp_ty *FSPoolInit(void *memory);

void *VSPoolAlloc(fsp_ty *vs_pool);

void VSPoolFree();

size_t BigPiece(fsp_ty *vs_pool);



#endif /*__FS_POOL_H__*/
