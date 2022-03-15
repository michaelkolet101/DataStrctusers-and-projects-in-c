#include <unistd.h> /*sleep*/
#include <pthread.h> /*create*/
#include <stdlib.h> /*size_t*/
#include <stdio.h> /*printf*/
#include <time.h> /*time*/

#define MAX_THREADS 100000


typedef struct Threads_of_sadness
{
    size_t val;

}threads_ty;

/**********************************************/

void PrintArr();
void *PutIdx(void *ptr_strcut);

/***********************************************/

int arr[MAX_THREADS] = {0};

/**********************************************/



int main()
{
    pthread_t id[MAX_THREADS] = {0};
    time_t start = 0;
    time_t end = 0;
    threads_ty *th = (threads_ty *)malloc(sizeof(size_t));

    size_t i = 0;

    start = time(NULL);
    for (i = 0; i < MAX_THREADS; ++i)
    {
        th->val = i;       
        pthread_create(&id[i], NULL, PutIdx, th);
    }
    end = time(NULL);

    sleep(5);

    PrintArr();
    puts("\n");
    printf(" %ld\n", end - start);
    return 0;
}

void *PutIdx(void *ptr_strcut)
{
    threads_ty *data = (threads_ty *)ptr_strcut;
    arr[data->val] = data->val;

}

void PrintArr()
{
    size_t i = 0;

    for (i = 0; i < MAX_THREADS/2; ++i)
    {
        printf("%d ,", arr[i]);
    }
}
