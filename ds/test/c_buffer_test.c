#include <stdio.h> /* printf */
#include <stddef.h> /* size_t*/
#include <unistd.h>/* sleep */

#include "../include/c_buffer.h"
#include "../include/utils.h"

#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
static void Welcome();
static test_stat_ty TestCBuffer(void);
/*Service functions*/



/**************************** Main Function ***********************************/

int main(void)
{
	
	Welcome();
	printf("\nSLIST final test result: %s\n", TestCBuffer()?RED"FAIL":GREEN"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

static test_stat_ty TestCBuffer(void)
{
	size_t n = 15;
	int g = 6, i = 0;
	void *elem = (void *)&n;
	char *my_string = "it's my string!!!";
	char str[50];
	cbuffer_ty *p_buffer = CBufferCreate(n);
	

	/* Test for create a circular buffer */
	
	if(NULL == p_buffer)
	{
		puts("Failed to create a circular buffer");
		
		return TEST_FAIL;
	}
	else
	{
		
		puts(" Your circular buffer is ready to use !!!");
	}

/************************************************************************/
	/* Test for CBufferFreeSpace  */
	
	if (15 == CBufferFreeSpace(p_buffer))
	{
		puts("CBufferFreeSpace" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("CBufferFreeSpace FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for CBufferBufsiz  */
	
	if (15 == CBufferBufsiz(p_buffer))
	{
		puts("CBufferBufsiz" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("CBufferBufsiz FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for CBufferIsEmpty  */
	
	if (1 == CBufferIsEmpty(p_buffer))
	{
		
		puts("CBufferIsEmpty" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("CBufferIsEmpty FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for CBufferWrite */
	
	
	CBufferWrite(p_buffer, (void *) my_string, 5);
	
	if (0 == CBufferIsEmpty(p_buffer))
	{
		
		puts("CBufferWrite" GREEN " SUCCESS"WHITE);
	}
	else
	{
		puts("CBufferWrite FAIL");
		return TEST_FAIL;
	}
	
	if (10 == CBufferFreeSpace(p_buffer))
	{
		puts("CBufferWrite" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("CBufferWrite FAIL");
		return TEST_FAIL;
	}
	
	
	/************************************************************************/
	/* Test for CBufferRead  */
	
	CBufferRead(p_buffer, str , 3);
	
	if (13 == CBufferFreeSpace(p_buffer))
	{
		puts("CBufferRead" GREEN " SUCCESS" WHITE);
	}
	else
	{
		puts("CBufferRead FAIL");
		return TEST_FAIL;
	}
	
	CBufferDestroy(p_buffer);
	/************************************************************************/
	
	return TEST_PASS;
}

static void Welcome()
{
	int i = 0;
	system("clear");
	for (i = 0; i < 2; ++i)
	{
		puts(YELLOW" WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(BLUE"        WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(GREEN"            WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(RED"                   WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	 	puts(WHITE"                      WELCOME TO MY TEST");
		sleep(1);
	 	system("clear");
	}
}






