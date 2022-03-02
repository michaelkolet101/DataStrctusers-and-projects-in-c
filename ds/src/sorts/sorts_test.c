#include <stdio.h>
#include "sorts.h"
#include "utils.h"

void TestBinarySearchRecursive(void);
void TestMergeSort(void);

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int *result = BinarySearch(arr, n , x);


if (result == NULL)
{
    puts("FAIL");
    return 0;
}


printf("bs iter res is: %d\n", *result);


/*TestBinarySearchRecursive();*/    
    
    TestMergeSort();
    
    
    return 0;
}

/*void TestBinarySearchRecursive(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
    int key = 10;
    int size = sizeof(arr) / sizeof(arr[0]);
    int found = BinarySearchRcur(arr, size , key);
   
    puts("BinarySearchRecursive:");
    
    if (found == -1)
    {
    	puts(""RED "FAIL!" BLACK);
    	puts("Element is not present in array\n");
    }
    
    puts(""GREEN "SUCCESS!" BLACK);
    printf("Element is present in array at idx %d\n", found);   /* requested result: idx = 3 */  
/*}*/

void TestMergeSort(void)
{
	int arr[]= {5,7,4,1,6,2,0,7,2,0,4,3};
    int i = 0, size = sizeof(arr)/sizeof(arr[0]);
    
    puts("BinarySearchRecursive:");
    
    printf("before running Merge sort, List is : \n");
    for(i = 0;i < size; i++)
    {
         printf("%d   ",arr[i]);
    }

    printf("\n");
    /*MeargSort(arr, size);*/
    
    QuickSort(arr, size);
    printf("After running Merge sort, Sorted List is :\n");
    for(i = 0;i < size; i++)
    {
         printf("%d   ",arr[i]);
    }

    printf("\n");
}
