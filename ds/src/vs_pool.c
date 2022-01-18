


struct vs_pool
{
	size_t memory_size;
};

vsp_ty *VSPoolInit(void *memory ,size_t memory_size)
{
/*
	1. Defines a pointer for a pool of our structure type and compares it to memory
	2. Initializes the members in the structure
	3. The first place after the structure - its value will be equal to the entire size of the memory
	4. We will return the pointer we defined

*/
}

void *VSPoolAlloc(vsp_ty *vs_pool, size_t chunk_size)
{
	/*
	1. Create a pointer to the pool.
	2. Word size alignment to chunk_size
    
    while not end of memory
    
    3. Make a dereference and check what is there
     
    4. If there is a number exactly the size of the memory the user wants
    5. 		We will make the content of the pointer to negative
    6. 		We will add ptrdiff to the pointer and give it to the user
    
	7. If there is a negative number or the number is smaller than the requested memory size
	8.		We will walk to the next metadata
													
	11. If the size requested by the user is smaller than the size of the memory_size
	12. save the size of the chunk at tmp var
	13.		Changes the value of the pointer to the complete 
										negative value that the user requested
	14		Advances with the pointer the amount the user wanted and ptrdiff more
	15 		Changes the value of the pointer to be equal to the temp less than
					 the user requested
	16 Return the pointer ret_val
	*/
}

void VSPoolFree(void *chunk_to_free)
{
/*
	1.Going a step back
	2.Makes dereference and changes the value there from negative to positive
*/
}

size_t VSPoolBiggestChunk(vsp_ty *vs_pool)
{
	/*
	1.	We will define a max = 1
	2.	We will define a run pointer to point on first 
	3.	while the value of a run is not equal to 0
	4.	We will check if the value of a runner is greater than the max
	5.	If so then Max will be equal to the new value
	6.	We will promote the runner as the positive number of houses in 
									his value and another one to the next place
	7.	return max	
	*/
}

static vsp_ty *NextChunk(vsp_ty *curr);
{
/*
	1. Defines a ret pointer
	2. Compares ret to the pointer we got
	3. Adds him his value
	4. Adds to it the size of the meta data
	5. Returns it to the user
*/
}

static ptrdiff GetChunkSize(vsp_ty *vs_pool)
{
	/*
	1.Loop to the end of the array
	2.Take the value of the pointer, make it an absolute value and add it to SUM
	3.Advanced to the next meta-data
	4.Exit the loop and return the SUM
	*/
}

vsp_ty * MemoryIntegration(vsp_ty *first, vsp_ty *seconde)
{
/*
1. The value of the first voter will be equal to the value of the first and another
2. We will return the first pointer
*/
}

void Defragment(vsp_ty *vs_pool)
{
/*
1. We will run with the pointer we got until the end of the array
2. If the first gunk is available and also the next after its
3. Send them to MemoryIntegration()
4. move on to the next meta-data

*/
}












