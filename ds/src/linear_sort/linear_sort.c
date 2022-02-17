#include <stdio.h>
#include <stdlib.h>
#include "linear_sort.h"

static void PrintArr(int *arr, int len);

static void AddSumBefor(int *arr ,size_t len);
static void LutArrayFilling(int *src, int *arr_to_fill, int len_src);
static void Array2Index(int *array_to_sort_, int *lut_, int *ret_, int len_);
static void ArrayIntCpy(int *arr1_, int* arr2_, int len);
static void ArrayRotLeft(int *arr , int len);
int MaxArrayVal(int *arr, int len);


void CountingSort(int *some_array , size_t len)
{
    int reange = MaxArrayVal(some_array, len);
    /*We will assign an arras the size of the range we have*/
    int *new_arr = (int *)calloc(sizeof(int), reange);
    int *ret = (int *)malloc(sizeof(int) * len + 1);
    
    /*We will check memory allocation*/
    if ( (NULL == new_arr) || (NULL == ret))
    {
        free(new_arr);
        free(ret);
        puts("alloc fail !!!");
        return;
    }

    /*init all the indexes in the new array acording to the count of value src */
    LutArrayFilling(some_array, new_arr, len);

    /*Each element in array will be the sum of the previous element and itself*/
    AddSumBefor(new_arr, reange);

    /*reorder the array acording the index val of the new array*/
    Array2Index(some_array, new_arr, ret, len);

    /*copy to user arry*/
    ArrayIntCpy(ret , some_array, len);

    free(new_arr);
    free(ret);
}

static void AddSumBefor(int *arr, size_t len)
{
    int *curr = arr + 1;
    int *prev = arr;
    int *end = arr + len;

    /*loop from the place 1 to the end - 1*/
    while ( curr <= end )
    {
        /*the element equal to curr + prev */
        *curr += *prev;
        ++curr;
        ++prev;
    }   
}

static void LutArrayFilling(int *src, int *arr_to_fill, int len_src)
{
    int *end = src + len_src;
    
    /*loop over thr src*/
    while (src <= end)
    {
        /*use the val as index to fill*/
        *(arr_to_fill + (*src)) += 1;
        ++src;
    }   
}


static void Array2Index(int *array_to_sort_, int *lut_, int *ret_, int len_)
{
    int *end = array_to_sort_ + len_;

    /*loop over the array to sort*/
    while (array_to_sort_ < end)
    {
        /*insert val to ret array*/
        *(ret_ + *(lut_ + *array_to_sort_) - 1) = *array_to_sort_;
        *(lut_ + *array_to_sort_) -= 1;
        ++array_to_sort_;
    }
}

static void ArrayIntCpy(int *arr1_, int* arr2_, int len)
{
    int *end = arr1_ + len;

    while (arr1_ <= end)
    {
        *arr2_ = *arr1_; 
        ++arr1_;
        ++arr2_;
    }
}

int MaxArrayVal(int *arr, int len)
{
    size_t i = 0;

    int max = arr[0];

    for (i = 1; i < len; ++i)
    {
        arr[i] > max ? max = arr[i]: 0; 
    }

    return max;
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
