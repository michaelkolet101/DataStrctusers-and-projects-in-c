#include <stdio.h>
#include "sorts.h"

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = BinarySearch(arr, n , x);

printf("res is: %d\n", result);

    (result == -1) ? printf("Element is not present"
                            " in array")
                   : printf("Element is present at "
                            "index %d\n",
                            result);
    return 0;
}