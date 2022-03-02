#include <stdlib.h>
#include <time.h> 

#include "sorts.h"
#include "utils.h"

void QuickSortIMP(int arr_[], int less, int greater );
void Swap(int *a, int* b);
int PlacePivot(int *arr_, int less,int  greater);


static void InsertLeftRightIMP(int *arr_, int *side_, size_t len_);

static int *Mearg(int *left_, int *right_, size_t len, int *res, size_t len_res);

static int *MeargSortIMP(int arr_to_sort_[],
                         int num_elements_,
                         int *left,
                         int *right,
                         int *res);

static int *CreatIntArrIMP(size_t size_);
static void Append(int *src, int* dest);
static int IsBigger (int num1, int num2);




int *BinarySearch(int arr_[], size_t len_, int num_to_find_)
{
    int *start = arr_;
    int *end = arr_ + len_ - 1;
    int middle = len_;
    
    while (0 != middle) 
    {
        middle = middle / 2;
        
        /* Check if num_to_find_ is present at middle*/
        if (*(start + middle) == num_to_find_)
        {
            return (start + middle);

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


    return NULL;
}


int *BinarySearchRcur(void *base,
                        size_t num_of_element,
                        size_t size,
                        void *elem_to_find,
                        int (*compar)(const void *, const void *))
{
    char *curr = (char*)base; 
    size_t len = num_of_element * sizeof(size);

    int res = compar((curr + (len / 2)), elem_to_find);

    /*if we find the element*/
    if (0 == res)
    {
        /*return the idx of the value*/
        return (void*)(curr + (len / 2));
    }
    
    /*if the middele smaller than num to find*/
    if (0 > res)
    {
        return BinarySearchRcur(curr + (len / 2),
                                num_of_element / 2,
                                size,
                                elem_to_find,
                                compar);
    }
    
    /*if the middele bigger than num to find*/
    return BinarySearchRcur(curr,
                        num_of_element / 2,
                        size,
                        elem_to_find,
                        compar);

    /* if we reach here, then element was not present */
    return NULL;
}

void QuickSort(int arr_[], int len_)
{
    /*var list less, greater*/
    int less = 0;
    int greater = len_ - 1;

    QuickSortIMP(arr_, less, greater);  
}

void QuickSortIMP(int arr_[], int less, int greater )
{
    
    int pivot = 0;

    /*if length(array) ≤ 1*/
    if (less >= greater)
    {
    /*  return */
		return;
    } 

    /*select and remove a pivot value*/
    pivot = PlacePivot(arr_, less, greater); 
    
    QuickSortIMP(arr_, less, pivot - 1);
    QuickSortIMP(arr_, less, pivot + 1);  
    
    
}

int PlacePivot(int *arr_, int less, int greater)
{
    int pivot = less;
    int switch_i = 0;
    int i = 0;

    /*for each idx in array*/
    for (switch_i = less + 1, i = less + 1; i <= greater; ++i)
    {
     
        if (i == pivot)
        {
            Swap(&i, &switch_i);
            Swap(&pivot, &switch_i);
            ++pivot;
            ++switch_i;
        }
        
    }

    return pivot;
}

void Swap(int *a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


int MeargSort(int arr_to_sort_[], int num_elements_)
{
    int *res = NULL;

    int *left = CreatIntArrIMP(num_elements_ + 1);
    int *right = CreatIntArrIMP(num_elements_ + 1);

    if (NULL == left || NULL == right)
    {
        return FAIL;
    }

    res = MeargSortIMP(arr_to_sort_, num_elements_, left, right, res);

    return SUCCSES;  
}
  
static int *MeargSortIMP(int arr_to_sort_[],
                         int len_,
                         int *left_,
                         int *right_,
                         int *res)
{ 
    /*if length(m) ≤ 1*/
    if (len_ <= 1)
    {
         /*return m*/
        return arr_to_sort_;
    }
        
        /*len_ = length(m) / 2*/
    len_ = len_ / 2;

    /*befor the center*/
    InsertLeftRightIMP(arr_to_sort_, left_, len_);
        
    /* after the center*/
    InsertLeftRightIMP((arr_to_sort_ + len_), right_, len_);

        /*left = mergesort(left)*/
    left_ = MeargSortIMP(left_, len_, left_, right_,res);

        /* right = mergesort(right)*/
    right_ = MeargSortIMP(right_, len_, left_, right_, res);

        /*result = merge(left, right)*/
    res = Mearg(left_, right_, len_, res, len_);


    /*   return result*/
    return res;
     
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


static int *Mearg(int *left_, int *right_, size_t len, int *res, size_t len_res)
{
    int *curr_left = left_;
    int *end_left = left_ + len;

    int *curr_right = right_; 
    int *end_right = right_ + len;

    /*while length(left) > 0 and length(right) > 0*/
    while ((curr_left < right_) && (curr_right <= end_right))
    {
        /*if first(left) ≤ first(right)*/
        if ( IsBigger(*curr_right, *curr_left) )
        {
            /*append first(left) to result*/
            Append(curr_left, res);
            
            /*left = rest(left)*/
            ++curr_left;
        }
        /*else*/
        else
        {
            /*append first(right) to result*/

            Append(curr_right, res);

            /*right = rest(right)*/
            ++curr_right;
        }
        ++res;
    }
     
    /* if length(left) > 0*/
    while (curr_left < end_left)
    {
        /*append left to result*/
        Append(curr_left, res);
        ++curr_left;
        ++res;
    }
       
    /*if length(right) > 0 */
    while (curr_right < end_right)
    {
        /*append right to result*/
        Append(curr_left, res);
        ++curr_left;
        ++res;
    }
    
    /* return result*/
    return res;
}
    
static int IsBigger (int num1, int num2)
{
    return num1 >= num2;
}

static void Append(int *src, int* dest)
{
    *dest == *src; 
}

     

     

     

     

     
     
    
