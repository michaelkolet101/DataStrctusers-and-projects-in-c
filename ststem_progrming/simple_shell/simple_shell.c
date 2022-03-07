#include <stdio.h>
#include <sys/wait.h>   /* wait */
#include <unistd.h>     /* execv */
#include <stdlib.h>     /* exit */
#include <string.h>     /* strcmp */
#include <errno.h>      /* ernno */
#include <time.h>      /* ctime  */

#define LOG(TYPE, M) fprintf(stderr, TYPE " Time:%s File:%s line:%d " M "\n",\
                             NowToStringIMP(), __FILE__, __LINE__);

#define LOGI(M) LOG("INF", M)
#define LOGW(M) LOG("WRN", M)
#define LOGE(M) LOG("ERR", M)



enum{
    INTERNUL_FUNC_SIZE = 1,
    MODE = 7,
    NUM_ARGS = 10,
    CMD_SIZE = 20
    };

typedef int(*mode_func)(char *);

int NativeRunWait(char *input);
int StandardRunWait(char *input_);
int IsInternal(char *input_);

void OpFuncIMP(int num_func);
static void NewLineToNullIMP(char *str_);
static void ParserIMP(char *str_, char **token_);
static int GetModeIMP(char *mode_);
static char *NowToStringIMP();
int ChangeDirectoryIMP(char *path);

/******************************************************************************/

int main()
{
    char mode[MODE];
    int status = 0;
    static mode_func func_table[] = {NativeRunWait, StandardRunWait};
    
    /* 0 is fork, 1 is system */
    int mode_num = 0; 

    /* get mode from the user - fork/system */
    fgets(mode, MODE, stdin);
    mode_num = GetModeIMP(mode);

    /* while (1) */
    while (1)
    {
        /* create char *str and scan */
        char str[CMD_SIZE];
        int num_func_internal = 0;
        
        fgets(str, CMD_SIZE, stdin);
        NewLineToNullIMP(str);

        /* translate first token to number - TokenToFuncIMP() */
        num_func_internal = TokenToFuncIMP(str);
        
        /* if num_func_internal */
        if (0 <= num_func_internal)
        {
            /* operation func in internal_ap */
            OpFuncIMP(num_func_internal);
            /* continue */
            continue;
        }
        /* status = StandardRunWait() or NativeRunWait() */
        status = func_table[mode_num](str);
    }
}

/******************************************************************************/
int NativeRunWait(char *input_)
{
    int status = 0;
    pid_t status_pid = 0;
    char *args[NUM_ARGS] = {0};

    /* fork the proccess */ 
    status_pid = fork();
    /* errors */
    if (0 > status_pid)
    {
        /* logger */
        LOGE("fork failed");
        /* return -1*/
        return -1;
    }

    /* if child */
    if (0 == status_pid)
    {
        /* split the line */
        ParserIMP(input_, args);
         
        /* execvp */
        status = execvp(*args, args);
        
        /* handle errors */
        if (-1 == status)
        {
            /* logger */
            LOGE("execvp failed");
        }
        /* exit */
        exit(errno);
    }

    /* if parent */
    /* wait */
    status_pid = wait(&status);
    
    /* handle errors */
    if (-1 == status_pid)
    {
        /* logger */
        LOGE("wait failed");

        /* return -1 */
        return -1;
    }

    /* return status */
    return status;
}

int StandardRunWait(char *input_)
{
    /* return status = system(input_) */
    return system(input_);
}

/******************************************************************************/
/* if token is not exist in internal_ap return -1 */
int TokenToFuncIMP(char *input_)
{
    int i = 0;
    /* input_ = first token of input */
    static char *internal_ap[INTERNUL_FUNC_SIZE] = {"exit", "cd"};
    NewLineToNullIMP(input_);

    for (i = 0; i < INTERNUL_FUNC_SIZE; ++i)
    {
        if(!strcmp(internal_ap[i], input_))
        {
            return i;
        }
    } 
    return -1;
}

static void ParserIMP(char *cmd_, char **args_)
{
    char *curr = cmd_;
    curr = strtok(cmd_, "\n");
    curr = strtok(cmd_, " ");
    *args_ = curr;
    ++args_;

    /* while (curr) */
    while (curr != NULL)
    {
        /* curr = strtok */
        curr = strtok(NULL, " ");
        *args_ = curr;
        
        /* ++curr */
        ++args_;
    }
    *args_ = NULL;
}   

/* return 0 if fork, 1 if system , -1 if input error */
static int GetModeIMP(char *mode_)
{
    NewLineToNullIMP(mode_);
    if (!strcmp(mode_, "fork"))
    {
        return 0;
    }
    
    if (!strcmp(mode_, "system"))
    {
        return 1;
    }
    
    return -1;
}

void OpFuncIMP(int num_func)
{
    if (0 == num_func)
    {
        exit(0);
    }
}

static void NewLineToNullIMP(char *str_)
{
    while(*str_)
    {
        if('\n' == *str_)
        {
            *str_ = '\0';
            break;
        }
        ++str_;
    }
}

static char *NowToStringIMP()
{
    time_t mytime = time(NULL);
    char *time_str = ctime(&mytime);
    time_str[strlen(time_str)-1] = '\0';

    return time_str;
}

int ChangeDirectoryIMP(char *path)
{
	/* If we write no path (only 'cd'), then go to the home directory*/
	if (path == NULL) {
		chdir(getenv("HOME")); 
		return 1;
	}
	/* Else we change the directory to the one specified by the*/ 
	/* argument, if possible*/
	else{ 
		if (chdir(path) == -1) {
			printf(" %s: no such directory\n", path);
            return -1;
		}
	}
	return 0;
}