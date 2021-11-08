#include <stdio.h>

/*Statements of functions*/


/*Converts an array of HEX to Hello World and prints.*/
void HelloXua();

/*Gets a number and reverses the order of the digits*/
int FlipOrder(int n);

/*Receives a number and returns it by a power of 10*/
int NumberToThePower(int n);

/*Receives two pointers on values ​​in memory and switches between them*/
void Swap(int *xp, int *yp);

/*Main function*/
int main() 
{	
	int number = 123456, x = 5, y = 7;
	
	HelloXua();
	
	printf("%d\n",FlipOrder(number));
	
	Swap(&x, &y);
	
	printf("%d  %d\n",x,y);
	
	printf("%d\n",NumberToThePower(5));
	
	return (0);
}

/* Converts an array of HEX to Hello World and prints. */
void HelloXua(void)

{
	char list_of_xs[] = {0x22,0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,
	                                                  /0x6c,0x64,0x21,0x22};
	
	printf("%s\n",list_of_xs);
}
	
/*Receives a number and returns it by a power of 10*/	
float NumberToThePower(int expo)

{
	float result = 10;
	
	int i;
	
	if (expo < 0)
	{
		expo*= -1;
		
		result = (1/result); 
	}
	
	for (i = 0; i < expo; i++)
	
	result = result * 10;
	
	return result;
}
  	
/*Gets a number and reverses the order of the digits*/
int FlipOrderOfNumber(int n)
	
{
	int revers = 0, remainder;
	
	while (0 != n)
	{
		remainder = n % 10;
		
		revers  = (revers * 10) + remainder;
		
		n /= 10;
	}

	return revers;
}

/*Receives two pointers on values ​​in memory and switches between them*/	
void SwapVall(int *x_ptr, int *y_ptr)

	{
		int temp = *xp;
		
		*x_ptr = *y_ptr;
		
		*y_ptr = temp;
	}
