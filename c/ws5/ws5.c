#include <stdio.h>/* scanf printf*/
#include <assert.h>/*assert*/
#include <ctype.h>/*size_t*/
#include <stdlib.h>/*exit*/
#include <string.h> /*strncmp strlen */


#include "ws5.h"

#define EXIT_STATUS -5
#define ARRY_SIZE 5
#define SUCSSES 0
#define FAIL 1

typedef int ( *cmp_f_ty)(const char* user_input, const char *cmd, size_t num);
typedef int (*op_ft_ty)(const char* file_path, const char* user_input );
typedef void(*func)(int);

enum status{sucsses, open_file_fail, malloc_fail, remove_fail, exit_logger};

typedef struct print_me
	{
		int number;
		func ptr_func;
	} print_me;
	
typedef struct
	{
		char *cmd;
		cmp_f_ty Compar;
		op_ft_ty Opration;	
	} special;



/*usefull functions*/
/*print int number*/
void Print(int number);

/*remove a file from the computer*/
static int Removed(const char *user_input, const char *file_path); 

/*close the program*/
static int Exit(const char *user_input, const char *file_path);

/*print the count of lines in the file*/
static int PrintCountLine(const char *user_input, const char *file_path);

/*append a string to the beging of thr file*/
static int Prepend(const char *user_input, const char *file_path);

/*append a string to the beginning of the file*/
static int Append(const char *user_input, const char *file_path);

/*comper betweem to strings*/
static int Compare(const char* user_input, const char *cmd, size_t number);

/*init the arry command*/
static void InitArrayOfCommand(special srtuct_arry[ARRY_SIZE]);


static int CopyFileToFile(const char *source,const char *target);

/*append a string to the beginning of the file*/
static int AppendToStart(const char *user_input, const char *file_path);
/******************************************************************************/

void PrintFunction()
{
	print_me srtuct_arry[10];
	int i = 0;
	
	for (i = 0; i < 10; ++i)
	{
		srtuct_arry[i].number = i;
		srtuct_arry[i].ptr_func = Print;
	}
	
	for (i = 0; i < 10; ++i)
	{
		srtuct_arry[i].ptr_func(srtuct_arry[i].number);/*TODO: change the name to someting else*/
	}
}

void Print(int number)
{
	printf("%d\n",number);
}
/******************************************************************************/

int Logger(char *file_name)
{
	char ch = '\0';
	char *ptr_to_string = NULL;
	char *start_string = NULL;
	int i = 0;
	int len = 0, flag = 0;
	size_t cmd_len = 0;
	
	special srtuct_arry[ARRY_SIZE]; /*TODO: change the name to someting else*/
	
	/*clear the screen*/
	system("clear");
	
	/* init arry */ /*TODO init?*/
	InitArrayOfCommand(srtuct_arry);
	
	ptr_to_string = (char*)malloc(sizeof(char) * 100); /*TODO*/
	if (NULL == ptr_to_string)
	{
		return  malloc_fail;
	}
	
	while (0 == flag)
	{
		/* less then 100 char */
		puts("enter a command or string to the logger -remove, -count, >, or -exit ");
		fgets(ptr_to_string, 100, stdin);
		
		/*the len of the input string*/
		len = strlen(ptr_to_string);
		
		/*loop over the array*/
		for (i = 0; i < len; ++i)
		{
			/*the len of the command*/
			cmd_len = strlen(srtuct_arry[i].cmd);
			
			/*compere and opret the currect function*/
			if (srtuct_arry[i].Compar(srtuct_arry[i].cmd, ptr_to_string, 
			cmd_len) == 0 )
			{	
				/*the flag get the status of the function SUCSSES OR FAIL*/
				flag = srtuct_arry[i].Opration(ptr_to_string, file_name);
				break;
			}
		}
	}
	free(start_string);
	return flag;
}

static int Removed(const char *user_input, const char *file_path)
{
	if (remove(file_path) == 0)
	{
		printf("Deleted successfully\n");
		return SUCSSES;
	}
	else
	{
		printf("Unable to delete the file\n");
		return remove_fail;
	}
}

static int Exit(const char *user_input, const char *file_path)
{
	/*clear the screen*/
	system("clear");
	return (exit_logger);
}

static int PrintCountLine(const char *user_input, const char *file_path)
{
	char ch = '\0';
	int lines = 0;
	FILE *fp;

	fp = fopen(file_path, "r");
	
	if (NULL == fp)
	{
		return open_file_fail;
	}
	
	while(!feof(fp))
	{
		ch = fgetc(fp);
		
		if(ch == '\n')
		{
			++lines;
		}
	}
	
	fclose(fp);
	
	printf("\nlines in file: %d\n\n",lines);
	
	return sucsses;
}

static int Prepend(const char *user_input, const char *file_path)
{
	/*creat a new file to swap data and copy the file to a tmp file*/
	CopyFileToFile(file_path, "tmpfile.txt");
	
	/* append the input string to the new file */ 
	AppendToStart(user_input, file_path);
	
	/*copy the temp file to my sorce file*/
	CopyFileToFile( "tmpfile.txt", file_path);
	
	/*delet the tmp file*/
	Removed(user_input, "tmpfile.txt");
	
	return sucsses;
}

static int Append(const char *user_input, const char *file_path)
{
	FILE *fp;
	
	fp = fopen(file_path, "a");
	if (NULL == fp)
	{
		return open_file_fail;
	}
	fputs(user_input, fp);
	fclose(fp);
	return sucsses;
}

/*TODO: Compare*/
static int Compare(const char* user_input, const char *cmd, size_t number)
{
	return (strncmp(user_input, cmd, number));
}

static int CopyFileToFile(const char *source_name, const char *target_name)
{
	char ch = ' ';
	FILE *source, *target;
	
	source = fopen(source_name, "r");
	if( source == NULL )
	{
		 return open_file_fail;
	}
   
   	target = fopen(target_name, "w");
	if( target == NULL)
	{
		 return open_file_fail;
	}
	
	while((ch = fgetc(source)) != EOF )
	{
		fputc(ch, target);
	}
	
	fclose(source);
	fclose(target);

	return sucsses;
}

static void InitArrayOfCommand(special srtuct_arry[ARRY_SIZE])
{
	srtuct_arry[0].cmd = "-remove";
	srtuct_arry[0].Compar = Compare;
	srtuct_arry[0].Opration = Removed;
	
	srtuct_arry[1].cmd = "-count";
	srtuct_arry[1].Compar = Compare;
	srtuct_arry[1].Opration = PrintCountLine;
	
	srtuct_arry[2].cmd = "-exit";
	srtuct_arry[2].Compar = Compare;
	srtuct_arry[2].Opration = Exit;
	
	srtuct_arry[3].cmd = ">";
	srtuct_arry[3].Compar = Compare;
	srtuct_arry[3].Opration = Prepend;
	
	srtuct_arry[4].cmd="";/*defult*/
	srtuct_arry[4].Compar = Compare;
	srtuct_arry[4].Opration = Append;

}


static int AppendToStart(const char *user_input, const char *file_path)
{
	FILE *fp;
	
	fp = fopen(file_path, "w");
	if (NULL == fp)
	{
		return open_file_fail;
	}
	fputs(user_input, fp);
	fclose(fp);
	return sucsses;
}
