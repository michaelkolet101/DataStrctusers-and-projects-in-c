#include <stdio.h>/* scanf printf puts */
#include <assert.h>/* assert */

#include "ws4.h"

/**/
typedef void (*n_t)(void); 


/*usefull functions that i use in the progrem*/
static void OnEcho();
static void OffEcho();
static char in(char ch);
void PressT();
void PressA();
void PressEsc();
void Empty();

/*******************************************************************/

/*Prints A or T or return depending on user input using if else*/
int CheckFromUserIfElseVariation()
{
	char input = 0;
	
	/*loop thet run while input not equl to the ascii val of 27 that it "Esc"*/
	while (input != 27)
	{
		/*using a function to get val from the user */
		input = in(input);
		
		if (input == 'A')
		{
			puts("A-pressed");
		}
		else if (input == 'T')
		{
			puts("T-pressed");
		}
	}
	
	OnEcho();
	return 0;
}

/*Prints A or T or return depending on user input using Switch*/
int CheckFromUserSwitchVariation()
{
	char input = 0;
	
	/*loop thet run while input not equl to the ascii val of 27 that it "Esc"*/
	while (input != 27)
	{
		/*using a function to get val from the user */
		input = in(input);
		
		switch(input)
		{
			case 'A':
			{
				puts("A-pressed");
				break;
			}
			case 'T':
			{
				puts("T-pressed");
				break;
			}
		}
	}
	
	OnEcho();
	
	return 0;
}

/*Prints A or T or return depending on user input using LUT*/
void CheckFromUserLUTVariation()
{
	/*using a function to get val from the user */
	char ch = '\0';
	
	n_t func[256];
	int i = 0;
	
	for (i = 0; i < 256; ++i)
	{
		func[i] = Empty;
	}
	
	func[65] = PressA;
	func[84] = PressT;
	func[27] = PressEsc;
	
	/*loop that run while input not equl to the ascii val of 27 that it "Esc"*/
	while (ch != 27)
	{
		ch = in(ch);
		func[ch]();
	}
	/*func[ch]();*/
	OnEcho();
}


 void PressT()
{
	puts("T-pressed");
}

 void PressA()
{
	puts("A-pressed");
}

 void PressEsc()
{
	;
	
}



/*turn on the echo*/
static void OnEcho()
{
int on = system("stty icanon echo");
assert(0 == on);
}


/*turn off the echo*/
static void OffEcho()
{
	int off = system("stty -icanon -echo");
	assert(0 == off);
}


/*get input from thr user*/
static char in(char ch)
{
	OffEcho();
	
	puts("Press on keybord");
	
	scanf("%c",&ch);
	
	return (ch);
}

void Empty()
{
	;
}




















