

#ifndef __FIXED_SIZE_POOL_H__


void Init(char *memory);

char *MemoryRequest(void);

int MemoryReturn(char * return_memory);

size_t Capacity(void);

size_t MetaDataCapacity(size_t const size_memory_piece,
										  size_t const pieces_memory_number);
										  
#endif /*__FIXED_SIZE_POOL_H__*/
