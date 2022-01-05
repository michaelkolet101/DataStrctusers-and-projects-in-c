
/*****************************************************************************/

char *FlipWordsStrng(char *src, char *dest)
{	
	assert(src);
	assert(dest);
	
	char *runner = dest;
	char *start = src;
	char *tmp_end = src + sizeof(src);
	char *tmp_start = tmp_end;
	
	while (tmp_end != start);
	{
		if (*tmp_start == ' ')
		{
			memcpy(runner, tmp_start, (tmp_end - tmp_start));
			runner += (tmp_end - tmp_start);
			--tmp_start;
			tmp_end = tmp_start;		
		}
		--tmp_start;
	}
	
	return dest;
}

	
	
	
	
	
	
	
	
	
	
	
	
 
