#include <unistd.h> /*sleep*/
#include <pthread.h> /*create*/
#include <stdlib.h> /*size_t*/
#include <stdio.h> /*printf*/
#include <time.h> /*time*/


typedef struct MemoryMaping data_ty;

void *TrFunc(void *data)
{
    
}

struct MemoryMaping
{
    int data;
};


int main(int argc, char const *argv[])
{
    
    data_ty* s_data = (data_ty*)malloc(sizeof(data_ty));
    pthread_t id = 0;
    /*cerate a thread*/
    /* Creating uninitialize attribute*/
    pthread_attr_t attr;
    
    /* Function to init attr to default so it can be set later to other
    attribute */
    pthread_attr_init (&attr);
	pthread_attr_setdetachstate (&attr, PTHREAD_CREATE_DETACHED); 

    pthread_create(&id, &attr, , s_data ) != 0);

    return 0;
}
