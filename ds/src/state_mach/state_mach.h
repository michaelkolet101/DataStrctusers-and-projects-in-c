/* FSM Update log:
	- V 1.1:	- changed CreateSM to SMCreate.
				- added header guards
				- added calculate() (move to test file?)
	
	- V 1.2		- added Matrix "definition"
				
	*/

#ifndef __STATE_MACH_H__
#define __STATE_MACH_H__


#include <stddef.h>


/******************************************************************************/

typedef struct state_machine state_mach_ty;

typedef struct
{
	int m_state;
	void (*func)(void *param);
} state_n_func_ty;

/*	Matrix: State marks number of row 
			Events marks number of column */
state_mach_ty *SMCreate(const state_n_func_ty *states, 
                        size_t num_states, 
                        size_t num_events);

int SMTriggerEvent(state_mach_ty *st_m, 
                   int curr_state, 
                   int event,
                   void *func_param);

void SMDestroy(state_mach_ty *st_m);





#endif /* __STATE_MACH_H__ */

