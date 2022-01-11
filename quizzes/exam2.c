



/************************************Answer 2*******************************/

Node *flip(Node *slist)
{
	Node *current = slist->head;
	Node *next = slist->head;
	Node *prev = slist->head;
	
	size_t count = 0;
	
	assert(slist);
	
	while (slist->tail != current->next)
	{
		++count;
	}
	
	current = slist->head;

	current->next = slist->tail;
	
	
	while (count - 1)
	{
		current = slower;
		next = current->next;
		current.slist_node->next = prev;
		prev = current;	
		--count;
	}	
	
	return current;
}

/*******************************Answer 4 a***********************************/

int IsNotAloop(Node *slist)
{
	Node *faster = slist->head;
	Node *slower = slist->head;
	
	while ((current->next->next != tail) && (slower->next != tail))
	{
		current = current->next->next;
		slower = slower->next;
		
		if (current == slower)
		{
			return 0;
		}
	}
	
	return 1;
}

/*******************************Answer 4 b***********************************/


void ReleaseTheLoop(Node *slist)
{
	Node *faster = NULL;
	Node *slower = NULL;
	Node *runner = NULL;
	Node *save_place = NULL;
	size_t count = 1;
	size_t tmp_count = 0;
	
	assert(slist);
	assert(!IsNotAloop(slist));
	
	faster = slist->head;
	slower = slist->head;
	
	/*Find the node we know for sure is in a loop*/
	while ((current->next->next != slist->tail) && (slower->next != slist->tail))
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
	
	runner = slist->head;
	
	while (tmp_count)
	{
		runner = runner->next;
		--tmp_count;
	}
	
	save_place = runner;
	runner = slist->head;
	
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

int NotIntersect(Node *slist1, Node *slist2)
{
	size_t count1 = 0;
	size_t count2 = 0;
	size_t move_forward = 0;
	Node *runner1 = NULL;
	Node *runner2 = NULL;
	
	assert(slist1);
	assert(slist2);
	
	runner1 = slist1->head;
	runner2 = slist2->head;
	
	/*We will check what the size of each list is*/
	while (runner1 != slist1->tail)
	{
		++count1;
		runner1 = runner1->next;
	}
	
	while (runner2 != slist2->tail)
	{
		++count2;
		runner2 = runner2->next;
	}
	
	runner1 = slist1->head;
	runner2 = slist2->head;
	
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
	while (runner1 != slist->tail)
	{
		if (runner1 = runner2)
		{
			return 0
		}
		
		runner2 = runner2->next;
		runner1 = runner1->next;
	}
	
	return 1;
}


/**************************Answer 5 b **********************************/

void SeparatorOfLists(Node *slist1, Node *slist2)
{
	
	size_t count1 = 0;
	size_t count2 = 0;
	size_t move_forward = 0;
	Node *runner1 = NULL;
	Node *runner2 = NULL;
	Node *save_place = NULL;
	
	assert(slist1);
	assert(slist2);
	assert(!NotIntersect(slist1,slist2));
	
	runner1 = slist1->head;
	runner2 = slist2->head;
	
	/*We will check what the size of each list is*/
	while (runner1 != slist1->tail)
	{
		++count1;
		runner1 = runner1->next;
	}
	
	while (runner2 != slist2->tail)
	{
		++count2;
		runner2 = runner2->next;
	}
	
	runner1 = slist1->head;
	runner2 = slist2->head;
	
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
	while (runner1 != slist->tail)
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
	runner1 = slist->head;
	
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
	
	node_to_insert->data = data;
	where->prev->next = node_to_insert;
	node_to_insert->next = where;
	node_to_insert->prev = where->prev;
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

/************                 Solution 1  Pseudo code                  ******/
/*We will sort the array*/
/*We will run on the sorted array*/

/*We will check in each iteration if the next number is larger than one 
of the previous ones*/

/*If not then we will return the number we are in plus 1 and that is
 the missing number*/

/************                 Solution 2                       ******/

int TheMissingNumber(int *arr)
{
/**/
	int new[1024];
	int i = 0;
	int index_to_on = 0;
	
	for (i = 0; i <= 1024; ++i)
	{
		new[i] = 0;
	}  
	
	for (i = 0; i <= 1024; ++i)
	{
		
		index_to_on = *(arr + i);
		new[index_to_on] = 1;
	}  
	
	for (i = 0; i <= 1024; ++i)
	{
		if (0 == new[i])
		{
			return i;
		}
	}  
	
	return 1
}















unctio
