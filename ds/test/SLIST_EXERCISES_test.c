#include <stdio.h>
#include <stdlib.h>

#include "../includ/SLIST_EXERCISES.h"


/* Declarations for test functions */
static void TestFlip(void);
static void TestHasLoop(void);
static void TestFindIntersection(void);

/* Service functions */
static void PrintLinkedList(node_ty *head); 
/******************************************************************************/
int main()
{
	TestFlip();
	TestHasLoop();
	TestFindIntersection();
	
    return 0;
}

static void TestFlip(void)
{
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int num4 = 4;
	int num5 = 5;
	
	/* Create 5 nodes on the heap */
	node_ty *new_node1 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node2 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node3 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node4 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node5 = (node_ty *)malloc(sizeof(node_ty));
	
	/* Init @data and @next in the list's nodes */
	new_node1->data = (void *)&num1; 
	new_node2->data = (void *)&num2; 
	new_node3->data = (void *)&num3; 
	new_node4->data = (void *)&num4; 
	new_node5->data = (void *)&num5; 

	new_node1->next = new_node2; 
	new_node2->next = new_node3; 
	new_node3->next = new_node4; 
	new_node4->next = new_node5; 
	new_node5->next = NULL; 
		
	puts("EXC. 1 :");
	printf("Before flipping the list the nodes are :\n");
	PrintLinkedList(new_node1);
	
	printf("\nAfter flipping the list the nodes are :\n");
	PrintLinkedList(Flip(new_node1));

	/* Free all allocations from the heap */
	free(new_node1);
	free(new_node2);
	free(new_node3);
	free(new_node4);
	free(new_node5);
}

static void TestHasLoop(void)
{
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int num4 = 4;
	int num5 = 5;
	
	/* Create 5 nodes on the heap */
	node_ty *new_node1 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node2 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node3 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node4 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node5 = (node_ty *)malloc(sizeof(node_ty));
	
	/* Init @data and @next in the list's nodes */
	new_node1->data = (void *)&num1; 
	new_node2->data = (void *)&num2; 
	new_node3->data = (void *)&num3; 
	new_node4->data = (void *)&num4; 
	new_node5->data = (void *)&num5; 
	
	new_node1->next = new_node2; 
	new_node2->next = new_node3; 
	new_node3->next = new_node4; 
	new_node4->next = new_node5; 
	new_node5->next = new_node3; 
	
	puts("\n\nEXC. 2 :");
	if(1 == HasLoop(new_node1))
	{
		puts("HasLoop SUCCSES\n");
	}
	else
	{
		puts("HasLoop FAIL\n");
	}

	/* Free all allocations from the heap */
	free(new_node1);
	free(new_node2);
	free(new_node3);
	free(new_node4);
	free(new_node5);
}

static void TestFindIntersection(void)
{
	int num1 = 1;
	int num2 = 2;
	int num3 = 3;
	int num4 = 4;
	int num5 = 5;
	int num6 = 6;
	int num7 = 7;
	
	/* Create variable for the returned value of FindIntersection */
	node_ty *result = {NULL};
	
	/* Create 5 nodes on the heap for the first list */
	node_ty *new_node1 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node2 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node3 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node4 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node5 = (node_ty *)malloc(sizeof(node_ty));
	
	/* Create 2 nodes on the heap for the second list */	
	node_ty *new_node6 = (node_ty *)malloc(sizeof(node_ty));
	node_ty *new_node7 = (node_ty *)malloc(sizeof(node_ty));

	/* Init @data and @next in the both list's nodes */
	new_node1->data = (void *)&num1; 
	new_node2->data = (void *)&num2; 
	new_node3->data = (void *)&num3; 
	new_node4->data = (void *)&num4; 
	new_node5->data = (void *)&num5; 
	new_node6->data = (void *)&num6;   /* Start of second list*/
	new_node7->data = (void *)&num7; 
	
	new_node1->next = new_node2; 
	new_node2->next = new_node3; 
	new_node3->next = new_node4; 
	new_node4->next = new_node5; 
	new_node5->next = NULL; 
	new_node6->next = new_node7;       /* Start of second list*/
	/* the second's list "last" node points to the first list third node */
	new_node7->next = new_node3;       
	
	result = FindIntersection(new_node1, new_node6);
	
	puts("EXC. 3 :");
	
	if((void *)&num3 == result->data)
	{
		puts("Find Intersection SUCCSES\n");
	}
	else
	{
		puts("Find Intersection FAIL\n");
	}
	
	/* Free all allocations from the heap */
	free(new_node1);
	free(new_node2);
	free(new_node3);
	free(new_node4);
	free(new_node5);
	free(new_node6);
	free(new_node7);

}

/* Service function to print linked list using only the head node */
static void PrintLinkedList(node_ty *head) 
{
    node_ty *curr_node = head;
    
    int *ptr = NULL; 
    
   	while (NULL != curr_node) 
   	{
   		ptr = curr_node -> data;
   		
        printf("  %d", *ptr);
        
        curr_node = curr_node -> next;
    }
}





