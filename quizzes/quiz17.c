
void *NFromLast(node_ty *head, size_t n)
{
	node_ty *iterator = head;
	size_t count = 0;
	
	while (iterator -> next != NULL)
	{
		++count;
		iterator = iterator -> next;
	}
	
	iterator = head;
	
	n = count - n;
	
	while (0 != n)
	{
		iterator = iterator -> next;
		--n;
	}
	
	return iterator -> data;
}
