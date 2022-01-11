#include <stdio.h> /* printf, BUFSIZ */ 
#include <stddef.h> /* size_t, sizeof */

#include "c_buffer.h"

#define DEST 100

/***************************Helpers********************************************/
static void PrintCBuffer(cbuffer_ty *cbuffer);
static void PrintCharArr(char *array, size_t size);
/**********************Tests declarations**************************************/

static void TestSuit1();
static void TestSuit2();


/****************************Main********************************************/
int main(void)
{
	TestSuit1();
	TestSuit2();

	return 0;	

}

/***********************Tests Implementation***********************************/
static void TestSuit1()
{
		cbuffer_ty *cbuffer = NULL;
	size_t capacity = 5;

	char *src = "Heliot";
	char dest[DEST] = {0};

	cbuffer = CBufferCreate(capacity);
	if(cbuffer == NULL)
	{
		printf("failed to create a circular buffer\n");
	}
	printf("New Circular buffer created\n");
	
	CBufferIsEmpty(cbuffer) ?
			printf("The circular buffer is empty \t\tTest Passed\n") :
			printf("The circular buffer is not empty \tTest Failed\n");

	CBufferBufsiz(cbuffer) == capacity ?
			printf("The buffer capacity is %ld bytes \t\tTest Passed\n", capacity) :
			printf("Wrong buffer capacity \t\tTest Failed");

	CBufferFreeSpace(cbuffer) == capacity ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));

	/* writing 2 bytes to cbuffer */
	CBufferWrite(cbuffer, src, 2) == 2 ?
			printf("2 bytes were written to cbuffer \tTest passed\n") :
			printf("Wrong amount of bytes were written \t\tTest Failed\n");

	CBufferFreeSpace(cbuffer) == 3 ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));

     /*	PrintCBuffer(cbuffer); */

	/* writing 2 bytes to cbuffer */
	CBufferWrite(cbuffer, src, 2) == 2 ?
			printf("2 bytes were written to cbuffer \tTest passed\n") :
			printf("Wrong amount of bytes were written \t\tTest Failed\n");
			
	/*	PrintCBuffer(cbuffer); */
	CBufferFreeSpace(cbuffer) == 1 ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));	

	/*  writing 2 bytes to cbuffer attempt, should write just 1 */
	CBufferWrite(cbuffer, src, 2) == 1 ?
			printf("1 bytes were written out of 2 bytes \tTest passed\n") :
			printf("Wrong amount of bytes were written\t\tTest Failed\n");

	CBufferFreeSpace(cbuffer) == 0 ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));
			
	/* PrintCBuffer(cbuffer); */

	/* attempt writing to full buffer */
	CBufferWrite(cbuffer, src, 1) == 0 ?
			printf("0 bytes were written out of 1 bytes \tTest passed\n") :
			printf("Wrong amount of bytes were written\t\tTest Failed\n");

	CBufferFreeSpace(cbuffer) == 0 ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));


	/* read all 5 bytes from buffer to dest */
	CBufferRead(cbuffer, dest, 5) == 5 ?
			printf("Reading 5 bytes from cbuffer \t\tTest Passed\n") :
			printf("Reading wrong count \t\t\tTest Failed\n");

	CBufferFreeSpace(cbuffer) == 5 ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));

	PrintCharArr(dest, DEST);

	CBufferDestroy(cbuffer);

}

static void TestSuit2()
{
	cbuffer_ty *cbuffer = NULL;
	size_t capacity = 5;

	char *src = "Heliot";
	char dest[DEST] = {0};

	cbuffer = CBufferCreate(capacity);
	if(cbuffer == NULL)
	{
		printf("failed to create a circular buffer\n");
	}
	printf("New Circular buffer created\n");
	
	
	/*  writing 4 bytes to cbuffer attempt, should write just 1 */
	CBufferWrite(cbuffer, src, 4) == 4 ?
			printf("4 bytes were written \tTest passed\n") :
			printf("Wrong amount of bytes were written\t\tTest Failed\n");
	

	/* read 3 bytes from buffer to dest */
	CBufferRead(cbuffer, dest, 3) == 3 ?
			printf("Reading 3 bytes from cbuffer \t\tTest Passed\n") :
			printf("Reading wrong count \t\t\tTest Failed\n");

	PrintCharArr(dest, DEST);

	/*  writing 4 bytes to cbuffer attempt, should write just 1 */
	CBufferWrite(cbuffer, src, 4) == 4 ?
			printf("4 bytes were written \tTest passed\n") :
			printf("Wrong amount of bytes were written\t\tTest Failed\n");

	CBufferFreeSpace(cbuffer) == 0 ?
			printf("Free space: %ld \t\t\t\tTest Passed\n", CBufferFreeSpace(cbuffer)) :
			printf("Free Space wrong %ld \t\tTest Failed\n", CBufferFreeSpace(cbuffer));
	

	/* read more the the capacity, 5 expected to be read */
	CBufferRead(cbuffer, dest, 6) == 5 ?
			printf("Reading 5 bytes from cbuffer \t\tTest Passed\n") :
			printf("Reading wrong count \t\t\tTest Failed\n");

	PrintCharArr(dest, DEST);

	CBufferDestroy(cbuffer);
}

/****************************Helpers Implementation****************************/
/*
static void PrintCBuffer(cbuffer_ty *cbuffer)
{
	size_t i = 0;
	char *buf = ((char *)cbuffer + sizeof(size_t) * 3);

	printf("Bufer:  ");
	while (i < CBufferBufsiz(cbuffer)+1)
	{
		printf("%c", *buf);
		++buf;
		++i;
	}
	printf("\n");
}
*/

static void PrintCharArr(char *array, size_t size)
{
	size_t i = 0;

printf("Dest:  ");
	for(i = 0; i < size; ++i)
	{
		printf("%c ", array[i]);
	}
	printf("\n");
}
