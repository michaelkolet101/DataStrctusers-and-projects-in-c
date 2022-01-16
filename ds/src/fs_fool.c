#include <stdio.h>
#include "fs_fool.h"

struct fixed_size_pool
{
    size_t free_chunks;
    size_t chunk_size;
    size_t next_to_free;
} ;

fsp_ty *FSPoolInit(void *memory, size_t memory_size, size_t chunk_size)
{
    /*
    1. Defines a variable i = 1 type of fixed_size_pool
        We define a new_fixed_size_pool = memory
        We will initialize the free_chunks and next_to_free.
        We will initialize the chunk_size
    2. Loop from to size of (all memory Divisions of cunks) - 1.
    3. Initialize each index in the last set of ballads that
                                    will indicate the next index.
    4. Initialize the last index in an array that points to NULL.
    5. The member who represents the top of the list in the 
        structure will point to the first free Icades which is Incodes 1.
    */
}

void *FSPoolAlloc(fsp_ty *fs_pool)
{
    /*
    1. Sets a pointer and compares it to NULL for the return value "ret val".
    2. Check if there is a space that can be allocated to the user.
    3. If yes then the pointer for the return value 
                            will point to the (fs_pool + OFFSETOF)[next_to_free].
    4. The next place to FREE will be the 
                            indexing dereference of what we send to the user.
    5. free_chunks -= 1.
    6. Returns to the user a pointer to the memory he requested.
    */
}

void FSPoolFree(fsp_ty *fs_pool, void *chunk_to_free)
{
    /*
    1. We will check if the pointer we got from the user is not equal to NULL.
    2. Put the next place for release inside the pointer we got from the user.
    3. free_chunks += 1.
    4. It was made that the next place for release would be
                         equal to the voter we received.
    */
}


size_t FSPoolCountFreeChunks(fsp_ty *fs_pool)
{
    /*
    We return the member that represents the count.
    */
}

size_t FSPoolCalcSize(size_t num_chunks, size_t chunk_size)
{
    /*
    We will return the size of the structure plus the product of
    num_chunks * chunk_size
    */
}