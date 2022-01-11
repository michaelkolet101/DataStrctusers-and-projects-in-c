



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
	
	/*Suspended that his next would point to NULL*/
	runner1->next = NULL;
}



