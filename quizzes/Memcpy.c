#include <stdio.h>
#include <string.h> 
#include <assert.h>


void *Memcpy(void *dest, const void *src, size_t n);





int main(void) 
{ 
				
	const char src[50] = "dfgdfgdhhgf";
   	char dest[50] = {'\0'};
   	
   	
   	Memcpy(dest, src, strlen(src) + 1);
   	printf("After memcpy dest = %s\n", dest);
   



	return(0);			 
}

void *Memcpy(void *dest_, const void *src_, size_t n_)
{ 
	void *ret = dest_;
	char *src = (char *)src_;
	char *dest = (char *)dest_;

	assert(dest);
	assert(src);
	while (0 < n_ / 8)
	{
		*(size_t *)dest = *(size_t *)src;
		dest += 8;
		src += 8;
		n_ -= 8;
	}
	
	while (0 < n_)
	{
		*dest = *src;
		++dest;
		++src;
		--n_;
	}
	


	return ret;	
}