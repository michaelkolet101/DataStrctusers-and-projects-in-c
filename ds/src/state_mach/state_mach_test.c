#include <stdio.h> /* printf */

#include "state_mach.h"

/* States */
typedef enum {EVEN,
              ODD,
              BAD,
              NUM_STATES} state_ty;

/* Events */
typedef enum {ZERO, 
              ONE, 
              BAD_TOKEN, 
              NUM_EVENTS} event_ty;
              

void TestStateMachine(void);              
static void PrintOddIMP(void *param_);
static void PrintEvenIMP(void *param_);
static void PrintBadIMP(void *param_);


int main()
{
	TestStateMachine();
	
	return 0;
}


void TestStateMachine(void)
{       
	state_mach_ty *mach = NULL;
	int events [] = {1, 0, 0, 1, 2, 1, 0, 2};
	state_ty state = EVEN;
	
	static const state_n_func_ty sm_table[] = 
	{
	/* events: 	 ZERO, 				ONE, 				BAD_TOKEN */
	/*EVEN*/ {ODD, PrintOddIMP},   {ODD, PrintOddIMP},   {BAD, PrintBadIMP},
	/*ODD*/  {EVEN, PrintEvenIMP}, {EVEN, PrintEvenIMP}, {BAD, PrintBadIMP},
	/*BAD*/	 {BAD, PrintBadIMP},   {BAD, PrintBadIMP},   {BAD, PrintBadIMP}
	};
		
	mach = SMCreate(sm_table, NUM_STATES, NUM_EVENTS);
	if (NULL != mach)
	{
		puts("SUCCSES");
	}
	
	state = SMTriggerEvent(mach, state, events[0], events);


	printf("%s\n", state == ODD ? "SUCCESS" : "FAIL");
	
	state = SMTriggerEvent(mach, state, events[1], events + 1);
	printf("%s\n", state == EVEN ? "SUCCESS" : "FAIL");
															
	state = SMTriggerEvent(mach, state, events[2], events + 2);
	printf("%s\n", state == ODD ? "SUCCESS" : "FAIL");
	
	state = SMTriggerEvent(mach, state, events[3], events + 3);
	printf("%s\n", state == EVEN ? "SUCCESS" : "FAIL");
	
	state = SMTriggerEvent(mach, state, events[4], events + 4);
	printf("%s\n", state == BAD ? "SUCCESS" : "FAIL");
															
	state = SMTriggerEvent(mach, state, events[5], events + 5);
	printf("%s\n", state == BAD ? "SUCCESS" : "FAIL");
	
	state = SMTriggerEvent(mach, state, events[6], events + 6);
	printf("%s\n", state == BAD ? "SUCCESS" : "FAIL");
	
	state = SMTriggerEvent(mach, state, events[7], events + 7);
	printf("%s\n", state == BAD ? "SUCCESS" : "FAIL");
															
	SMDestroy(mach);
}



static void PrintOddIMP(void *param_)
{
	printf("%d was inserted - odd # of numbers\n", *(int *)param_);
}


static void PrintEvenIMP(void *param_)
{
	printf("%d was inserted - even # of numbers\n", *(int *)param_);
}


static void PrintBadIMP(void *param_)
{
	printf("%d was inserted - bad state\n", *(int *)param_);
}
