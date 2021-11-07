#include <stdio.h>

/*Statements of functions*/

int NumberToThePower(int n);
void HelloXua();
int FlipOrder(int n);
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


void HelloXua(void)
/*Converts an array of HEX to Hello World and prints.*/
	{
		char list_of_xs[] = {0x22,0x48,0x65,0x6c,0x6c,0x6f,0x20,0x57,0x6f,0x72,0x6c,0x64,0x21,0x22};
		printf("%s\n",list_of_xs);
	}
	
	
int NumberToThePower(int n)
/*Receives a number and returns it by a power of 10*/
	{
		int result = 10, i;
		
		if (n < 0)
		{
			n*= -1;
			result = (1/result); 
		}
		
		for (i = 0; i < n; i++)
		result = result * 10;
		return result;
  	}

int FlipOrder(int n)
/*Gets a number and reverses the order of the digits*/	
	{
		int rev = 0, remainder;
		
		while (n)
			{
				remainder = n % 10;
				rev = (rev * 10) + remainder;
				n /= 10;
			}
		
		return rev;
	}
	
void Swap(int *xp, int *yp)
/*Receives two pointers on values ​​in memory and switches between them*/
	{
		int temp = *xp;
		*xp = *yp;
		*yp = temp;
	}
