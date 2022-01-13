



/************************************Answer 2*******************************/


Node *flip(Node *head) 
{
	Node* current = head;
    Node *prev = NULL, 
    Node *next = NULL;
	size_t count = 0;
	
	assert(head);
	
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;	
		current = next;
	}	
	
	return current;
}


/*******************************Answer 3 ***********************************/

/*Any task that does not require going over the entire list will be in o(1)
   else o(n)
   
   Create o(1)
   Destroy o(n)
   
   InsertBefore o(1)
   Remove o(1)
   GetData o(1)
   SetData o(1)
   Append o(1)
   
   Count o(n)
/*******************************Answer 4 a***********************************/


int IsNotAloop(Node *head)
{
	Node *faster = NULL; 
	Node *slower = NULL; 
	
	assert(head);
	
	faster = head;
	slower = head;
	
	while (faster && slower)
	{
		faster = faster->next->next;
		slower = slower->next;
		
		if (faster == slower)
		{
			return 0;
		}
	}
	
	return 1;
}

/*******************************Answer 4 b***********************************/


void ReleaseTheLoop(Node *head)
{
	Node *faster = NULL;
	Node *slower = NULL;
	Node *runner = NULL;
	Node *save_place = NULL;
	size_t count = 1;
	size_t tmp_count = 0;
	
	assert(head);
	
	faster = head;
	slower = head;
	
	/*Find the node we know for sure is in a loop*/
	while ((current->next->next) && (slower->next))
	{
		current = current->next->next;
		slower = slower->next;
		
		if (current == slower)
		{
			save_place = current;
		}
	}
	
	/*Count how many nodes there are inside the loop*/
	current = current->next;
	
	while (current != save_place)
	{
		++count;
		current = current->next;
	}
	
	/*We will proceed with a pointer on a node as a number in the nodes 
										in the loop*/
	tmp_count = count;
	
	runner = head;
	
	while (tmp_count)
	{
		runner = runner->next;
		--tmp_count;
	}
	
	save_place = runner;
	runner = head;
	
	/*Find where the loop begins*/
	while (save_place != runner)
	{
		save_place = save_place->next;
		runner = runner->next;
	}
	
	/*We will find the one node before the beginning of the loop and make 
				it point to NULL*/
	while (count - 1)
	{
		runner = runner->next;
		--count;
	}
	
	runner->next = NULL;
}

/**************************Answer 5 a **********************************/


int NotIntersect(Node *head1, Node *head2)
{
	size_t count1 = 0;
	size_t count2 = 0;
	size_t move_forward = 0;
	Node *runner1 = NULL;
	Node *runner2 = NULL;
	
	assert(head1);
	assert(head2);
	
	runner1 = head1;
	runner2 = head2;
	
	/*We will check what the size of each list is*/
	while (runner1)
	{
		++count1;
		runner1 = runner1->next;
	}
	
	while (runner2)
	{
		++count2;
		runner2 = runner2->next;
	}
	
	runner1 = head1;
	runner2 = head2;
	
	/*We will advance with the larger the difference in sizes*/
	if (count1 > count2)
	{
		move_forward = count1 - count2;
		
		while (move_forward)
		{
			runner1 = runner1->next;
			--move_forward;
		}
	}
	else
	{
		move_forward = count2 - count1;
		
		while (move_forward)
		{
			runner2 = runner2->next;
			--move_forward;
		}
	}
	
	/*We will check if the nodes are equal*/
	while (runner1)
	{
		if (runner1 == runner2)
		{
			return 0
		}
		
		runner2 = runner2->next;
		runner1 = runner1->next;
	}
	
	return 1;
}


/**************************Answer 5 b **********************************/


void SeparatorOfLists(Node *head1, Node *head2)
{
	size_t count1 = 0;
	size_t count2 = 0;
	size_t move_forward = 0;
	Node *runner1 = NULL;
	Node *runner2 = NULL;
	Node *save_place = NULL;
	
	assert(slist1);
	assert(slist2);
	
	runner1 = head1;
	runner2 = head2;
	
	/*We will check what the size of each list is*/
	while (runner1)
	{
		++count1;
		runner1 = runner1->next;
	}
	
	while (runner2)
	{
		++count2;
		runner2 = runner2->next;
	}
	
	runner1 = head1;
	runner2 = head2;
	
	/*We will advance with the larger the difference in sizes*/
	if (count1 > count2)
	{
		move_forward = count1 - count2;
		
		while (move_forward)
		{
			runner1 = runner1->next;
			--move_forward;
		}
	}
	else
	{
		move_forward = count2 - count1;
		
		while (move_forward)
		{
			runner2 = runner2->next;
			--move_forward;
		}
	}
	
	/*Find the place where they intersect*/
	while (runner1)
	{
		if (runner1 = runner2)
		{
			save_place = runner1;
			break;
		}
		
		runner2 = runner2->next;
		runner1 = runner1->next;
		/*We will use a counter that counts one of them until the intersection*/
		++count1;
	}
	
	/*We will promote our runner on the list to one place before the intersection*/
	runner1 = head1;
	
	while (count1 - 1)
	{
		runner1 = runner1->next;
		--count1;
	}
	
	/*His next was made to point to NULL*/
	runner1->next = NULL;
}

/************************** Answer 6 **********************************/

Node *Remove(Node *where)
{
	/*We will create a pointer to the Node*/
	Node *tmp = NULL;
	
	assert(where);
	
	/*The pointer will point to the next after what we got in the function*/
	tmp = where->next;
	
	/*Our node in the list will get the values ​​of it after it*/
	where->data = tmp->data;
	where->next = tmp->next;
	
	/*We will release the next node after it*/
	tmp->next = NULL;
	free(tmp);
	tmp = NULL;
}

/************************** Answer 7 **********************************/


DNode_ty *DlistInsert(DNode_t *where, const void *data)
{
	
	DNode_ty *node_to_insert = NULL;
	
	assert(where);
	
	node_to_insert = (DNode_ty)malloc(sizeof(DNode_ty));
	if (NULL == node_to_insert)
	{
		return NULL;
	}
	node_to_insert->next = NULL;
	node_to_insert->prev = NULL;
	node_to_insert->data = data;
	
	node_to_insert->next = where;
	node_to_insert->prev = where->prev;
	
	where->prev->next = node_to_insert;
	where->prev = node_to_insert;
	
	return node_to_insert;
}

DNode_ty *DlistRemove(DNode_t *where)
{
	*DNode_ty ret_val = NULL;
	
	assert(where);
	
	ret_val = where->next;
	
	where->prev->next = where->next;
	where->next->prev = where->prev;
	
	free(where);
	where = NULL;
	
	return ret_val;
}


/************************** Answer 8 **********************************/


int TheMissingNumber(int *arr)
{
/*We will create an array of 1024 places*/
	int new[1024];
	int i = 0;
	int index_to_on = 0;
	
	/*We will reset the entire array*/
	for (i = 0; i <= 1024; ++i)
	{
		new[i] = 0;
	}  
	/*We will run on the array we got from the function and turn on indexes
	 accordingly in our array*/
	for (i = 0; i <= 1024; ++i)
	{	
		index_to_on = *(arr + i);
		new[index_to_on] = 1;
	}  
	/*We will look for the undexed index in the array and return it*/
	for (i = 0; i <= 1024; ++i)
	{
		if (0 == new[i])
		{
			return i;
		}
	}  
	
	return 1 /*for fail*/
}


/*********************************Answer 9 ********************************/





/*********************************Answer 10 ********************************/

typedef struct Queue
{
    char m_queue[Q_SIZE];
    size_t m_elements_in_q;
    size_t m_first_element;
}Queue_ty;

void PushChar(Queue_ty *q, char *data)
{
	assert(q);
	
	if ((q->m_first_element + q->m_elements_in_q >= Q_SIZE))
	{
		return 1;
	}
	
	q->m_queue[m_first_element + m_elements_in_q] = data;
	q->m_elements_in_q += 1;
	
	return 0;
}

char *PopChar(Queue_ty *q)
{
	char *ret_val = NULL;
	
	assert(q);
	
	ret_val = q->m_queue[q->m_first_element];
	
	q->m_first_element += 1;
	
	q->m_elements_in_q -= 1;
	
	return ret_val;
}












