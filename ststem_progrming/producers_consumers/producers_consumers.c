#include <stdio.h>
#include <pthread.h>

void *WriteIMP(void *data);
void *ReadIMP(void *data);

volatile char buffer[10000] = {'\0'};
volatile int flag = 1; 

int main()
{
    pthread_t thread_id = 0;
    char *data = "abcdefgh";

    pthread_create(&thread_id, NULL, WriteIMP, (void*)&data);
    pthread_create(&thread_id, NULL, ReadIMP, NULL);

    return 0;
}


void *WriteIMP(void *data)
{
    
    return NULL;
}

void *ReadIMP(void *data)
{
    return  
}