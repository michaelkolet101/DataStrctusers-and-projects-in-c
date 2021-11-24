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


typedef struct print_me
	{
		int number;
		func ptr_func; /*TODO: change the name of var*/
	} print_me;
	
typedef struct
	{
		char *cmd;
		cmp_f_ty Comper;
		op_ft_ty Opration;	
	} special;



/*usefull functions*/

void Print(int number);
/*remove a file from the computer*/
int Removed(const char *user_input, const char *file_path); /*TODO static*/

/*close the program*/
int Exit(const char *user_input, const char *file_path);

/*print the count of lines in the file*/
int PrintCountLine(const char *user_input, const char *file_path);

/*append a string to the beging of thr file*/
int Prepend(const char *user_input, const char *file_path);

/*append a string to the beginning of the file*/
int Append(const char *user_input, const char *file_path);

/*comper betweem to strings*/
int Compere(const char *user_input, const char *cmd, size_t number);

static void InitArrayOfCommand(special srtuct_arry[ARRY_SIZE]);
static int CopyFileToFile(const char *source,const char *target);

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
		srtuct_arry[i].ptr_func(srtuct_arry[i].number);	/*TODO: change the name to someting else*/
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
	int count = 1;
	int i = 0;
	int len = 0, flag = 0;
	size_t cmd_len = 0;
	
	special srtuct_arry[ARRY_SIZE]; /*TODO: change the name to someting else*/
	
	/* init arry */ /*TODO init?*/
	InitArrayOfCommand(srtuct_arry);
	
	ptr_to_string = (char*)malloc(sizeof(char) * 100); /*TODO*/
	if (NULL == ptr_to_string)
	{
		return FAIL;
	}
	

	/* less then 100 char */
	puts("enter a command: ");
	
	while (0 == flag)
	{
		fgets(ptr_to_string, 100, stdin);
		
		/*the len of the input string*/
		len = strlen(ptr_to_string);
		
		/*loop over the array*/
		for (i = 0; i < len; ++i)
		{
			/*the len of the command*/
			cmd_len = strlen(srtuct_arry[i].cmd);
			
			if (srtuct_arry[i].Comper(srtuct_arry[i].cmd, ptr_to_string, 
			cmd_len) == 0 )
			{
				flag = srtuct_arry[i].Opration(ptr_to_string, file_name);
				break;
			}
		}
	}
	free(start_string);
	return flag;
}

int Removed(const char *user_input, const char *file_path)
{
/*TODO: Change Signture  to return status*/
	if (remove(file_path) == 0)
	{
		printf("Deleted successfully");
		return SUCSSES;
	}
	else
	{
		printf("Unable to delete the file");
		return FAIL;
	}
}

int Exit(const char *user_input, const char *file_path)
{
	return (EXIT_STATUS);
}

int PrintCountLine(const char *user_input, const char *file_path)
{
	char ch = '\0';
	int lines = 0;
	FILE *fp;

	fp = fopen(file_path, "r");
	
	if (NULL == fp)
	{
		return 1;
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
	printf("%d",lines);
	return 0;
}

int Prepend(const char *user_input, const char *file_path)
{
	/*creat a new file to swap data and copy the file to a tmp file*/
	CopyFileToFile(file_path, "tmpfile.txt");
	
	/* append the input string to the new file */ 
	Append(user_input, "tmpfile.txt");
	
	/*copy the temp file to my sorce file*/
	CopyFileToFile( "tmpfile.txt", file_path);
	
	/*delet the tmp file*/
	Removed(user_input, "tmpfile.txt");
	
	return 0;
}

int Append(const char *user_input, const char *file_path)
{
	FILE *fp;
	
	fp = fopen(file_path, "a");
	if (NULL == fp)
	{
		return 1;
	}
	fputs(user_input, fp);

	
	fclose(fp);
	return 0;
}

int Compere(const char* user_input, const char *cmd, size_t number)
{
	return (strncmp(user_input, cmd, number));
}


int CopyFileToFile(const char *source_name, const char *target_name)
{
	char ch = ' ';
	FILE *source, *target;
	
	source = fopen(source_name, "r");
	if( source == NULL )
	{
		 return 1;
	}
   
   	target = fopen(target_name, "w");
	if( target == NULL )
	{
		 return 1;
	}
	
	while((ch = fgetc(source)) != EOF )
	{
		fputc(ch, target);
	}
	
	fclose(source);
	fclose(target);

	return 0;
}

static void InitArrayOfCommand(special srtuct_arry[ARRY_SIZE])
{
	srtuct_arry[0].cmd = "-remove";
	srtuct_arry[0].Comper = Compere;
	srtuct_arry[0].Opration = Removed;
	
	srtuct_arry[1].cmd = "-count";
	srtuct_arry[1].Comper = Compere;
	srtuct_arry[1].Opration = PrintCountLine;
	
	srtuct_arry[2].cmd = "-exit";
	srtuct_arry[2].Comper = Compere;
	srtuct_arry[2].Opration = Exit;
	
	srtuct_arry[3].cmd = ">";
	srtuct_arry[3].Comper = Compere;
	srtuct_arry[3].Opration = Prepend;
	
	srtuct_arry[4].cmd=""  ;/*defult*/
	srtuct_arry[4].Comper = Compere;
	srtuct_arry[4].Opration = Append;

}

