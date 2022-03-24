#include <stdlib.h>
#include <stdio.h>
#include <assert.h> 
 
typedef struct node
{
	int data;
	struct node *next;
}node_ty;

typedef struct list
{
	node_ty *head;
	node_ty *tail;
}list_ty;


list_ty *AddTwoNumbers(node_ty *node_L1, node_ty *node_L2); 
node_ty *NodeCreateIMP(int data);
void *AddElemToLIstIMP(list_ty *list, int data);
void PrintList(list_ty *list);
list_ty *ListCreate();


int main(void) 
{
	/*create 2 lists*/
	
	/*push elements*/

	/*do the check*/
	list_ty *first_list = ListCreate();
	list_ty *second_list = ListCreate();
	list_ty *ans_list = NULL; 
	

	AddElemToLIstIMP(first_list, 2);
	AddElemToLIstIMP(first_list, 4);
	AddElemToLIstIMP(first_list, 3);
	
	AddElemToLIstIMP(second_list, 5);
	AddElemToLIstIMP(second_list, 6);
	AddElemToLIstIMP(second_list, 4);
	
	ans_list = AddTwoNumbers(first_list->head->next, second_list->head->next);

	PrintList(first_list);
	PrintList(second_list);
	PrintList(ans_list);

 	return(0);				 
}

list_ty *AddTwoNumbers(node_ty *node_L1, node_ty *node_L2)
{
	list_ty *ret_list = ListCreate();

	int sum = 0;
	int tmp = 0;

	assert(node_L1);
	assert(node_L2);

	while ((node_L1 != NULL) && (node_L2 != NULL))
	{
		sum = node_L1->data + node_L2->data;
		sum += tmp;
		if (sum > 9)
		{
			sum = sum % 10;
			tmp = 1;
		}
		else
		{
			tmp = 0;
		}
		
		AddElemToLIstIMP(ret_list, sum);

		node_L1 = node_L1->next;
		node_L2 = node_L2->next;

		
	}

	return ret_list;
}

list_ty *ListCreate()
{
	list_ty *new_list = (list_ty *)malloc(sizeof(list_ty *));
	new_list->head = NodeCreateIMP(0);
	new_list->tail = NodeCreateIMP(0);

	if (new_list == NULL || new_list->head == NULL || new_list->tail == NULL)
	{
		return NULL;
	}

	return new_list;
}


node_ty *NodeCreateIMP(int data)
{
	node_ty *new_node = (node_ty *)malloc(sizeof(node_ty));

	if (new_node == NULL)
	{
		return NULL;
	}
	
	new_node->data = data;
	new_node->next = NULL;

	return new_node;
}

void* AddElemToLIstIMP(list_ty *list, int data)
{
	node_ty *node_to_add = NodeCreateIMP(data);

	node_ty *curr = list->head;

	if (NULL == node_to_add)
	{
		return NULL;
	}
	
	while (curr->next != NULL)
	{
		curr = curr->next;
	}

	curr->next = node_to_add;
}

void PrintList(list_ty *list)
{
	node_ty *curr = list->head->next;

	while (curr != NULL)
	{
		printf("%d, ",curr->data);
		
		curr = curr->next;
	}
	puts("\n");
}