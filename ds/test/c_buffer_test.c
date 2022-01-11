#include <stdio.h>	/* puts size_t NULL*/

#include "c_buffer.h"

void TestSCBuffer(void);

/******************************************************************************/
int main(void)
{
	TestSCBuffer();
	
	return 0;
}

/******************************************************************************/
void TestSCBuffer(void)
{	
	cbuffer_ty *p_cbuff = NULL;
	size_t ctr = 0;
	
	size_t bufsiz = 100;
	char source[] = "hello world";
	char dest[100];

	/* Test for CBufferCreate */
	
	p_cbuff = CBufferCreate(bufsiz);
	
	if(NULL == p_cbuff)
	{
		puts("Failed to create Circular Buffer");
		return;
	}	
	else
	{
		puts("Your Circular Buffer is ready to use!");
	}
	
	/************************************************************************/
	/* Test for CBufferIsEmpty */
	
	if(1 == CBufferIsEmpty(p_cbuff))
	{
		puts("CBufferIsEmpty SUCCESS");
	}
	
	else
	{
		puts("CBufferIsEmpty FAIL");
	}
	
	/************************************************************************/
	/* Test for CBufferFreeSpace */
	
	if(bufsiz == CBufferFreeSpace(p_cbuff))
	{
		puts("CBufferFreeSpace SUCCESS");
	}
	else
	{
		puts("CBufferFreeSpace FAIL");
	}
	/************************************************************************/
	/* Test for CBufferBufsiz */
	
	if(bufsiz == CBufferBufsiz(p_cbuff))
	{
		puts("CBufferBufsiz SUCCESS");
	}
	else
	{
		puts("CBufferBufsiz FAIL");
	}
	
	/************************************************************************/
	/* Test for CBufferWrite */
	
	CBufferWrite(p_cbuff, source, 5);      /* Writing 5 characters to buffer*/
	
	if(95 ==  CBufferFreeSpace(p_cbuff))
	{
		puts("CBufferWrite SUCCESS");

	}
	else
	{
		puts("CBufferWrite FAIL");
	}
	
	/************************************************************************/
	/* Test for CBufferRead */
	
	ctr = 2;
	
	CBufferRead(p_cbuff, dest, ctr);
	
	if(97 ==  CBufferFreeSpace(p_cbuff))
	{
		puts("CBufferRead SUCCESS");

	}
	else
	{
		puts("CBufferRead FAIL");
	}
	
	
	/************************************************************************/
	/* Free DS */ 
	
	CBufferDestroy(p_cbuff);
	p_cbuff = NULL;
}
