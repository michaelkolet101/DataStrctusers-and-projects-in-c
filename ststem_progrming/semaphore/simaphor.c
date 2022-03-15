#include <sys/ipc.h>
#include <sys/sem.h>

#include <string.h> 
#include <stdio.h>
#include <stdlib.h>

#include <semaphore.h>


union semun 
{
            int val;
            struct semid_ds *buf;
            unsigned short  *array;
} arg;

struct sembuf sem_buf = {0};
/*aaa.sem_num = 5;
aaa.sem_flg = SEM_UNDO;
*/
    /* data */


static void TokenizeIMP(char cmd_[], char **tokens_);
void SetBuffer(char *buffer);


int main(void) 
{ 
    char *comands[] = {"X", "D", "I" , "V" };
    char **input_cmd = NULL;
	key_t key = 0;
    int semid = 0;
    char buffer[50] = "\0";

    /*create a semaphore*/
    
    if ((key = ftok("/home/michael/michael-kolet/ststem_progrming/semaphore/simaphor.c", 1)) == -1) 
    { 
        perror("ftok");
        exit(1); 
    }

    if ((semid = semget(key, 1, 0666 | IPC_CREAT) == -1)) 
    {
        perror("semget");
        exit(1); 
    }

    while (fgets (buffer, 50, stdin) != NULL)
    {
        TokenizeIMP(buffer, input_cmd);

        if ( strcmp( input_cmd[0] , comands[0] ) == 0)
        {
	        puts("work!");
            exit(0);
        }

        /*lock */
        if (strcmp(buffer,comands[1]) == 0)
        {

            if (semop(semid, &sem_buf , 1) == -1) 
            { 
                perror("semop");
                exit(1); 
            }
        }
            
        /*decrement*/
        /*if (strcmp( buffer , "dn" ))
        {
            ;
        }*/
        
    }
    
	return(0);			 
}


void SetBuffer(char *buffer)
{
    while ( '\0' != *buffer )
    {
        *buffer = '\0';
    }
}

static void TokenizeIMP(char cmd_[], char **tokens_)
{
	*tokens_ = strtok(cmd_, "\n");
	*tokens_ = strtok(cmd_, " ");

	do
	{
		/* split cmd to args */
		/* re arrenge arguments */
		++tokens_;

		*tokens_ = strtok(NULL, " ");

	}while(NULL != *tokens_);
}
