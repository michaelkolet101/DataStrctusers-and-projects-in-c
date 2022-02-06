#include<stdio.h>
#include<stdlib.h>

int Min(int *arr, size_t k)
{
    int *cutnt = arr;
    int min = *cutnt;

    while (cutnt != (arr + k))
    {
        ++cutnt;
        if (*cutnt < min)
        {
            min = *cutnt;
        }
    }
    return min;
}

int main()
{
    int arr[20] = {100,400,203,50,43,2020,240,64,640,43,86,345,24,54,24,46,46,24,75,24};
    int res = Min(arr, 17);
    printf("%d\n",res);
    return 0;
}
