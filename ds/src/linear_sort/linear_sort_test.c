#include <stdio.h>

#include "linear_sort.h"

static void PrintArr(int *arr, int len);

int main()
{
    int arr[7] = {1, 4, 1, 2, 7, 5, 2}; 
   
    PrintArr(arr, 7);
    CountingSort(arr, 7);
    
    PrintArr(arr, 7);
    
    return 0;
}


static void PrintArr(int *arr, int len)
{
    int i = 0;

    for (i = 0; i < len; ++i)
    {
        printf("%d, ", arr[i]);
    }
    puts("\n");
}