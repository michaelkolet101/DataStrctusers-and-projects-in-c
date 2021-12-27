#include <stdio.h> /* printf */
#include <stddef.h> /* size_t*/

#include "queue.h"
#include "utils.h"

#define SUCCESS 0
#define FAIL 1

typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
static test_stat_ty Testqueue(void);
/*Service functions*/



/**************************** Main Function ***********************************/

int main(void)
{
	printf("\nSLIST final test result: %s\n", Testqueue()?"FAIL":"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

static test_stat_ty Testqueue(void)
{
	int n = 5;
	int g = 6, i = 0;
	void *elem = (void *)&n;
	
	queue_ty *p_queue = QueueCreate();
	queue_ty *p_queue2 = QueueCreate();

	/* Test for create a queue */
	
	if(NULL == p_queue)
	{
		puts("Failed to create a queue");
		
		return TEST_FAIL;
	}
	else
	{
		puts("Your queue is ready to use !!!");
	}

/************************************************************************/
	/* Test for QueueIsEmpty  */
	
	if (1 == QueueIsEmpty(p_queue))
	{
		puts("QueueEnqueue SUCCESS");
	}
	else
	{
		puts("QueueEnqueue FAIL");
		return TEST_FAIL;
	}
	
	
	
	/************************************************************************/
	/* Test for QueueEnqueue  */
	
	if (SUCCESS == QueueEnqueue(p_queue, elem))
	{
		puts("QueueEnqueue SUCCESS");
	}
	else
	{
		puts("QueueEnqueue FAIL");
		return TEST_FAIL;
	}
	
	QueueEnqueue(p_queue, elem);
	
	/************************************************************************/
	/* Test for QueueSize  */
	
	if (2 == QueueSize(p_queue))
	{
		
		puts("QueueSize SUCCESS");
	}
	else
	{
		puts("QueueSize FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for QueueDequeue */
	
	QueueDequeue(p_queue);
	
	if (1 == QueueSize(p_queue))
	{
		
		puts("QueueDequeue SUCCESS");
	}
	else
	{
		puts("QueueDequeue FAIL");
		return TEST_FAIL;
	}
	
	/************************************************************************/
	/* Test for QueuePeek  */
	
	elem = QueuePeek(p_queue);
	
	if (5 == *(int *)elem)
	{
		puts("QueuePeek SUCCESS");
	}
	else
	{
		puts("QueuePeeks FAIL");
	}
	
	/************************************************************************/
	/* Test for QueueAppend  */
	
	elem = (void *)&g;
	for (i = 0; i < 5; ++i)
	{
		QueueEnqueue(p_queue2, elem);
	}
	
	QueueAppend(p_queue, p_queue2);
	
	if (6 == QueueSize(p_queue))
	{
		puts("QueueAppend SUCCESS");
	}
	else
	{
		puts("QueueAppend FAIL");
		return TEST_FAIL;
	}
	
	QueueDequeue(p_queue);
	
/************************************************************************/
	/* Test for QueueDestroy  */
	
	
	elem = QueuePeek(p_queue);
	
	if (6 == *(int *)elem)
	{
		puts("QueuePeek SUCCESS");
	}
	else
	{
		puts("QueuePeeks FAIL");
	}
	/************************************************************************/
	QueueDestroy(p_queue);
	
	return TEST_PASS;
}








