#include <stdlib.h>
#include "sorts.h"
#include "utils.h"


static int *Mearg(int *left_, int *right_);
static void InsertLeftRightIMP(int *arr_, int *side_, size_t len_);
static int *MeargSortIMP(int arr_to_sort_[], int num_elements_);
static int *CreatIntArrIMP(size_t size_);

int BinarySearch(int arr_[], size_t len_, int num_to_find_)
{
    int *start = arr_;
    int *end = arr_ + len_ - 1;
    int middle = len_ / 2;

    while (0 != middle) 
    {
        /* Check if num_to_find_ is present at middle*/
        if (*(start + middle) == num_to_find_)
        {
            return middle;
        }
            
        /* If num_to_find_ greater, ignore left half*/
        if (*(start + middle) < num_to_find_)
        {
            start += middle + 1;
        }
  
        /* If num_to_find_ is smaller, ignore right half*/
        else
        {
            end -= middle - 1;
        }
    }    
}


int BinarySearchRcur(int arr_[], size_t len_, int num_to_find_)
{
    
    /*if we find the element*/
    if (arr_[(len_ / 2)] == num_to_find_)
    {
        /*return the idx of the value*/
        return (len_ / 2);
    }
    
    /*if the middele smaller than num to find*/
    if (arr_[(len_ / 2)] < num_to_find_)
    {
        return BinarySearchRcur(arr_ + (len_ / 2),
                                len_ - (len_ / 2) ,
                                 num_to_find_);
    }
    
    /*if the middele bigger than num to find*/
    return BinarySearchRcur(arr_, (len_ / 2), num_to_find_);

    /* if we reach here, then element was not present */
    return -1;
}

void Qsort(void *base,
           size_t nmemb,
           size_t size,
           int (*compar)(const void *, const void *))

{
    /*var list less, greater*/

    /*if length(array) ≤ 1*/
        /*  return */
    
    /*select and remove a pivot value*/

    /*for each idx in array*/
        /* if idx ≤ pivot then append x to less*/
        /* else append x to greater*/

    /* return concatenate(quicksort(less), pivot, quicksort(greater))*/

}

int MeargSort(int arr_to_sort_[], int num_elements_)
{

}
  
static int *MeargSortIMP(int arr_to_sort_[], int num_elements_)
{
    int middle = 0;
    int *res = NULL;
    int *left = CreatIntArrIMP(num_elements_ / 2);
    int *right = CreatIntArrIMP(num_elements_ / 2);

    if (NULL == left || NULL == right)
    {
        return FAIL;
    }
    
    /*if length(m) ≤ 1*/
    if (num_elements_ <= 1)
    {
         /*return m*/
        return 1;
    }
    

     /*else*/
     else
     {
        /*middle = length(m) / 2*/
        middle = num_elements_ / 2;
        InsertLeftRightIMP(arr_to_sort_, left, middle);
            
            /*  for each element in arr_to_sort_ after middle*/
               /* add element to right*/
        InsertLeftRightIMP((arr_to_sort_ + middle), right, middle);

            /*left = mergesort(left)*/
            left = MeargSortIMP(left, middle);

           /* right = mergesort(right)*/
           left = MeargSortIMP(right, middle);

            /*result = merge(left, right)*/
            res = Mearg(left, right);

         /*   return result*/
         return res;
     }

}


static void InsertLeftRightIMP(int *arr_, int *side_, size_t len_)
{
    int *end = arr_ + len_ - 1;

    /* for each element in arr_to_sort_ up to middle*/
    while (arr_ != end)
    {
       /*  add element to left*/
       *side_ = *arr_;
       ++arr_;
       ++side_;
    }
}

static int *CreatIntArrIMP(size_t size_)
{
    int *new_arr = (int *)malloc(sizeof(int) * size_);

    return new_arr;
}


static int *Mearg(int *left_, int *right_)
{
    /*while length(left) > 0 and length(right) > 0*/ 
        /*if first(left) ≤ first(right)*/
            /*append first(left) to result*/
            /*left = rest(left)*/
        /*else*/
            /*append first(right) to result*/
            /*right = rest(right)*/
    /* if length(left) > 0*/
        /*append left to result*/
    /*if length(right) > 0 */
        /*append right to result*/
    /* return result*/

}
    
     

     

     

     

     

     

     
     
    
}