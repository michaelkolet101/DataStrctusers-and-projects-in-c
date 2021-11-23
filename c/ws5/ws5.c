#include <stdio.h>/* scanf printf*/
#include <assert.h>/*assert*/
#include <ctype.h>/*size_t*/
#include <stdlib.h>/*exit*/

#include "ws5.h"

#define BUFFER_SIZE 1000
typedef int(*cmp_ft)(const char* user_input, const char *cmd);
typedef int(*op_ft)(const char* file_path, const char* user_input );

typedef enum {sucsses, fail} ret;

typedef struct print_me
	{
	
		int number;
		void (*func)(int);
		
	} print_me;
	
typedef struct
	{
	
		char *cmd;
		int *cmp_ft;
		int *op_ft;
		
	} special;



/*usefull functions*/

void Print(int number);
/*remove a file from the computer*/
void Removed(const char *user_input, const char *file_path);

/*close the program*/
int Exit(const char *user_input, const char *file_path);

/*print the count of lines in the file*/
int PrintCountLine(const char *user_input, const char *file_path);

/*append a string to the beging of thr file*/
int Prepend(const char *user_input, const char *file_path);

/*append a string to the beginning of the file*/
int Append(const char *user_input, const char *file_path);

/*******************************************************************/




void PrintFunction()
{
	
	print_me srtuct_arry[10];

	int i = 0;
	
	 
	
	for (i = 0; i < 10; ++i)
	{
		srtuct_arry[i].number = i;
		srtuct_arry[i].func = Print;
	}
	
	for (i = 0; i < 10; ++i)
	{
		srtuct_arry[i].func(srtuct_arry[i].number);	
	}
	
	
}

void Print(int number)
{
	printf("%d\n",number);
}




void Logger(char *file_name)
{


/*typedef struct
	{
	
		char *cmd;
		int *cmp_ft;
		int *op_ft;
		
	} special;
*/
	char ch = '\0';
	char *ptr_to_string = NULL;
	char *start_string = NULL;
	int count = 1;
	
	special srtuct_arry[5];
	
	srtuct_arry[0].cmd = "-remove";
	srtuct_arry[0].cmp_ft = Compere;
	srtuct_arry[0].op_ft = Removed;
	
	srtuct_arry[1].cmd = "-count";
	srtuct_arry[1].cmp_ft = Compere;
	srtuct_arry[1].op_ft =PrintCountLine;
	
	srtuct_arry[2].cmd = "-exit";
	srtuct_arry[2].cmp_ft = Compere;
	srtuct_arry[2].op_ft = Exit;
	
	srtuct_arry[3].cmd = "<";
	srtuct_arry[3].cmp_ft = Compere;
	srtuct_arry[3].op_ft = ;
	
	srtuct_arry[4].cmd = " " ;/*defult*/
	srtuct_arry[4].cmp_ft = Compere;
	srtuct_arry[4].op_ft = Append;
	
	ptr_to_string = malloc(sizeof(char) * 100);
	
	start_string = ptr_to_string;
	
	puts("enter a string: ");
	
	gets(start_string);
	
	ptr_to_string = start_string;
	
	
	Append(ptr_to_string, file_name);
	
	free(start_string);
}


void Removed(const char *user_input, const char *file_path)
{
/*TODO: Change Signture  to return status*/
	if (remove(file_path) == 0)
	{
		printf("Deleted successfully");
	}
	else
	{
		printf("Unable to delete the file");
	}
	
	
}

int Exit(const char *user_input, const char *file_path)
{
	exit(0);
}


int PrintCountLine(const char *user_input, const char *file_path)
{
	char ch = '\0';
	int lines = 0;
	FILE *fp;

	fp = fopen(file_path, "r");
	/*TODO:Check fp is not NULL*/
	while(!feof(fp))
	{
		ch = fgetc(fp);
		
		if(ch == '\n')
		{
			++lines;
		}
	}
	
	fclose(fp);
	return lines;
}

int Prepend(const char *user_input, const char *file_path)
{
	return 0;
}

int Append(const char *user_input, const char *file_path)
{
	FILE *fp;
	
	fp = fopen(file_path, "a");
	
	fputs((const char*)user_input, fp);
	fputc('\n',fp);
	
	fclose(fp);
	return 0;
}


int Compere(const char* user_input, const char *cmd)
{
	return (strcmp(user_input,cmd));
}
