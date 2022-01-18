
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
	2. Bring him to first place after the pool
    3. Make a reference and check what is there
    
    4. If there is a number exactly the size of the memory the user wants
    5. 		We will make the content of the pointer to negative
    6. 		We will add another one to the pointer and give it to the user
    
	7. If there is a negative number
	8.		We will walk this number in its positive form and add one, 
													to get to the next metadata
													
	9. If the number is smaller than the requested memory size
	10.		We will walk the positive number of steps and another one to meta data
	
	11. If the size requested by the user is smaller than the size of the memory_size
	12. Maintains the size of the chunk at tmp
	13.		Changes the value of the pointer to the complete 
										negative value that the user requested
	14		Advances with the pointer the amount the user wanted and one more
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
