#include <stdlib.h>

#ifndef __SORTS_H__
#define __SORTS_H__

int *BinarySearch(int arr_[], size_t len_, int num_to_find_);

int *BinarySearchRcur(void *base,
                        size_t num_of_element,
                        size_t size,
                        void *elem_to_find,
                        int (*compar)(const void *, const void *));


void QuickSort(int arr_[], int len_);

int MeargSort(int arr_to_sort_[], int num_elements_);


#endif /*__SORTS_H__*/
