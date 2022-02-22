#include <stdlib.h>

#ifndef __HASH_MAP_H__
#define __HASH_MAP_H__



typedef int(*hash_func_ty)(const char *data);


int *CreateHaseMap(size_t num_of_elements, hash_func_ty hash_func);

int InsertToMap(int *hash_map, const char *name, hash_func_ty hash_func);

int FindInMap(int *hash_map, const char *name, hash_func_ty hash_func);





#endif /*__HASH_MAP_H__*/