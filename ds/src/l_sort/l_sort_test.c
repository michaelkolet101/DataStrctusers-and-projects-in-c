

#include <stdio.h>
#include <stdlib.h>

#include "l_sort.h"

enum { LOAD_SIZE = 5000 };

/******************************************************************************/
/* Service functions declrations */
void PrintIntArr(int *arr_, size_t size, char *dest_);
static void FillArrRandIMP(int *_start, int *_end);

/******************************************************************************/
/* Test functions declarations */

int TestLSort(void);

/******************************************************************************/
int main(void)
{
    printf("%d/n", TestLSort());
    return 0;
}
/******************************************************************************/

/* Test functions implementations */

int TestLSort(void)
{
    int result = 0;
    int to_sort[10] = {2,4,1,7,3,5,9,8,6,0};
    int sorted[10] = {0};   /* 0 1 2 3 4 5 6 7 8 9 */
    int data_set[LOAD_SIZE] = {0};
    int data_set_output[LOAD_SIZE] = {0};
    size_t histogram[16] = {0};
    char *dest = calloc(100, 1);
    
  PrintIntArr(to_sort, 10, dest);
  puts("\n");
    CountSort(to_sort, sorted, 10, 0, 4, histogram);
    PrintIntArr(sorted, 10, dest);
    puts(dest);
    
    RadixSort(to_sort, sorted, 10, 3, 0, 4, histogram);
    PrintIntArr(sorted, 10, dest);
    puts(dest);

    /* srand(1);
    FillArrRandIMP(data_set, data_set + LOAD_SIZE);

    RadixSort(data_set, data_set_output, LOAD_SIZE, 4, 0, 7, histogram);
    PrintIntArr(data_set_output, LOAD_SIZE, dest);
    puts(dest);
 */
    free(dest);
    return result;
}

/******************************************************************************/
/* Service functions implementations */

void PrintIntArr(int *arr_, size_t size_, char *dest_)
{
    int *end = arr_ + size_;
    char *curr = dest_;
    while(arr_ != end)
    {
        curr += printf("%d ", *arr_);
        ++arr_;
    }
}

static void FillArrRandIMP(int *_start, int *_end)
{
    for( ; _start != _end; ++_start)
    {
        *_start = rand() % 100;
    }
}
