/* Contributed by Alex */

#include <stdio.h>	/* printf, puts, putchar */
#include <stdlib.h> /* calloc, free */

#include "vs_pool.h"
#include "utils_Alex.h"

/******************************************************************************/
/* Test functions declarations */
static void PrintPool(ptrdiff_t *pool, size_t size);
void TestVSPool(void);

/******************************************************************************/
int main()
{
    TestVSPool();
    return 0;
}

/******************************************************************************/
/* Test functions declarations */

void TestVSPool(void)
{
    size_t pool_size = 10;
    ptrdiff_t *mem_pool = calloc(pool_size, sizeof(double));
    ptrdiff_t *curr1 = NULL;
    ptrdiff_t *curr2 = NULL;
    
    PrintPool(mem_pool, pool_size);
    
    VSPoolInit(mem_pool, pool_size * sizeof(double));
    PrintPool(mem_pool, pool_size);

    PrintIntTestResult("VSPoolInit", 
                        (pool_size - 1), 
                        *(ptrdiff_t *)mem_pool,
                        "first chunk value");

    PrintIntTestResult("VSPoolCalcLargestChunk", 
                    (pool_size - 2) * sizeof(double), 
                    VSPoolCalcLargestChunk((vs_pool_ty *)mem_pool), 
                    "initial pool size");                        
    
    curr1 = VSPoolAlloc((vs_pool_ty *)mem_pool, 2 * sizeof(double));
    PrintPool(mem_pool, pool_size);

    curr2 = VSPoolAlloc((vs_pool_ty *)mem_pool, 3 * sizeof(double));
    PrintPool(mem_pool, pool_size);

    VSPoolFree(curr1);
    PrintPool(mem_pool, pool_size);
    
    VSPoolFree(curr2);
    PrintPool(mem_pool, pool_size);
puts("here test 57");    
    VSPoolFree(NULL);

    curr1 = VSPoolAlloc((vs_pool_ty *)mem_pool, 3 * sizeof(double));
    PrintPool(mem_pool, pool_size);

    PrintIntTestResult("VSPoolCalcLargestChunk", 
                        32, 
                        VSPoolCalcLargestChunk((vs_pool_ty *)mem_pool), 
                        "");
    PrintPool(mem_pool, pool_size);

    PrintIntTestResult("VSPoolAlloc",
                        1,
                        NULL == VSPoolAlloc((vs_pool_ty *)mem_pool, 41),
                        "requesting more than there is");

    free(mem_pool);
}


static void PrintPool(ptrdiff_t *pool, size_t size)
{
    size_t i = 0;
    fputs("pool: ", stdout);
    for(i = 0; i < size; ++i)
    {
        if(pool[i])
        {
            printf("%ld ", pool[i]);
        }
        else
        {
            fputs(" 0 ", stdout);
        }
    }
    putchar('\n');
}


void PrintIntTestResult(
	const char *func_name, 
	const int expected,
	const int aquired,  	  
	char *test_case
)
{
	printf("%s: %s: %s\n", func_name, test_case, expected == aquired ? 
															"SUCCESS" : "FAIL");
}
