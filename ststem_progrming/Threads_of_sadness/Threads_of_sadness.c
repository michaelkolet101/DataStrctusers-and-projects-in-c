#include <unistd.h> /*sleep*/
#include <pthread.h> /*create*/
#include <stdlib.h> /*size_t*/
#include <stdio.h> /*printf*/
#include <time.h> /*time*/

#define MAX_THREADS 100000



/**********************************************/

void PrintArr();
void *PutIdx(void *ptr);
void UpdatDividors(int num);

/***********************************************/

int arr[MAX_THREADS] = {0};
int sum_of_divisors = 0;

/**********************************************/



int main()
{
    pthread_t id[MAX_THREADS] = {0};
    int *arg = NULL;
    int **ptr = &arg;
    time_t start = 0;
    time_t end = 0;
    

    size_t i = 0;
    /* Creating uninitialize attribute*/
	pthread_attr_t attr;
	
	/* Function to init attr to default so it can be set later to other
	attribute */
	pthread_attr_init (&attr);
	
	/* Set detach state for the created threads */
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED); 

    start = time(NULL);
    
          

    for (i = 0; i < MAX_THREADS; ++i)
    {
        while (pthread_create(&id[i], &attr, PutIdx, (void *)i ) != 0)
        {
            continue;
        }
        
        (void) pthread_join(id[i], NULL);

    }
    end = time(NULL);

    sleep(3);
    /* Destroy attribute */
	pthread_attr_destroy (&attr); 
    
    PrintArr();
    
    /*print the time*/
    printf(" %ld\n", end - start);

    return 0;
}

void *PutIdx(void *ptr)
{
    int *data = (int *)&ptr;
    /*UpdatDividors(*data);*/
    arr[*data] = *data;
}

void PrintArr()
{
    size_t i = 0;

    for (i = 0; i < MAX_THREADS; ++i)
    {
        printf("%d ,", arr[i]);
    }
    puts("\n");
}


void UpdatDividors(int num)
{
    int i = 0;

    for ( i = 0; i < num; ++i)
    {
        if (0 == num % i)
        {
            sum_of_divisors += i;
        }
        
    }
}