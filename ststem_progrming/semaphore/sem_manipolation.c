
#include <stdio.h>
#include <stdlib.h>    /* exit */
#include <unistd.h>
#include <errno.h>     /*perror */
#include <sys/sem.h>
#include <semaphore.h> /*semaphore*/
#include <fcntl.h>     /* For O_* constants */
#include <assert.h>
#include <string.h>

enum
{
	EXIT = 1
};


enum
{
	TOKEN_NUMS = 2, 
	BUF_SIZE = 50
};


typedef union semun 
{
    int val;               				/* used for SETVAL only */
    struct semid_ds *buf;  				/* used for IPC_STAT and IPC_SET */
    unsigned int short *array;         /* used for GETALL and SETALL */
}semun_ty;



int SemManipulationIMP(char *name_); 
static int InputMangerIMP(int sem_);
static void TokenizeIMP(char cmd_[], char **tokens_); 
static int InpufCommandIMP(int sem_, semun_ty *semun_, char *input_);
static int SemPostIMP(int sem_, semun_ty *semun_ ,int inc_with); 
static int SemWaitIMP(int sem_, semun_ty *semun_, int dec_with);
static int SemCloseIMP(int sem_, semun_ty *semun_);
static int SemGetValIMP(int sem_);
static int GetInputNumberIMP(char cmd_[]);

/* this function for the shared memory ex */
/***********************************************/
/*static int ShmatIMP(void);*/ 
static int CheckIfFailIMP(int to_check_); 
static int CheckIfShmatFailIMP(void *to_check_); 
/************************************************/

int main(int input, char **argv) 
{ 

    
    key_t key = 0;
    int semid = 0;
    int status = 0;
    char path_buff[BUF_SIZE] = {'\0'};

    FILE *fp = NULL;
    

    sprintf(path_buff, "/tmp/%s", argv[1]);
    
    
    fp = fopen(path_buff, "a");
    if (NULL == fp)
    {
        return 1;
    }

	key = ftok(path_buff , 1);

    if (CheckIfFailIMP(key))
    {
    	perror("fail to ftok");
    	exit(1);
    }

    semid = semget(key, 1, 0666 | IPC_CREAT);
    if (CheckIfFailIMP(semid))
    {
    	perror("semget");
    	exit(1);
    }

    status =  InputMangerIMP(semid);

    fclose(fp);

    return status; 
}


static int InputMangerIMP(int sem_)
{
	int status = 0;
	semun_ty semun = {0};

	assert(sem_);

	while (status != EXIT)
	{
		char input_buffer[BUF_SIZE] = {0};

		read(0, input_buffer, BUF_SIZE);

		status = InpufCommandIMP(sem_, &semun , input_buffer);
	}

	/* CLOSE */
	return SemCloseIMP(sem_, &semun);
}



static int InpufCommandIMP(int sem_, semun_ty *semun_, char *input_)
{
	int input_number = 0;

	assert(sem_);

	switch(*input_)
	{
		case 'I':
		{
			input_number = GetInputNumberIMP(input_);

			return SemPostIMP(sem_, semun_,input_number);
		}
		case 'D':
		{
			input_number = GetInputNumberIMP(input_);

			return SemWaitIMP(sem_, semun_ ,input_number);	
		}
		case 'V':
		{
			return SemGetValIMP(sem_);
		}
		case 'X':
		{
			return EXIT; 			
		}
		default: 
		{
			break; 
		}
	}

	return 0;
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

static int SemPostIMP(int sem_, semun_ty *semun_ ,int inc_with)
{
	int val = semctl(sem_, 0, GETVAL);

	assert(sem_);

	val += inc_with;  

	if(-1 == semctl(sem_, 0, SETVAL, val))
	{
		perror("fail to sem_close");
		exit(1);
	}

	return 0;
}

static int SemWaitIMP(int sem_, semun_ty *semun_ ,int dec_with)
{
	int val = semctl(sem_, 0, GETVAL);

	assert(sem_);

	val -= dec_with;   

	if(-1 == semctl(sem_, 0, SETVAL, val))
	{
		perror("fail to SemWait");
		exit(1);
	}

	return 0;
}

static int SemCloseIMP(int sem_, semun_ty *semun_)
{
	assert(sem_);

	if(-1 == semctl(sem_, 0, IPC_RMID, semun_))
	{
		perror("fail to SemWait");
		exit(1);
	}

	return 0;	
}

static int SemGetValIMP(int sem_)
{
	int value = 0;

	assert(sem_);

	value = semctl(sem_, 0, GETVAL);

	if(-1 == value)
	{
		perror("fail to sem_getvalue");
		exit(1);
	}

	printf("value now is %d \n", value);

	return 0;		
}

static int GetInputNumberIMP(char cmd_[])
{
	char *tokens[TOKEN_NUMS] = {NULL};

	TokenizeIMP(cmd_ ,tokens);

	return atoi(tokens[1]); 
}


static int CheckIfFailIMP(int to_check_)
{
	return (to_check_ == -1);
}
















