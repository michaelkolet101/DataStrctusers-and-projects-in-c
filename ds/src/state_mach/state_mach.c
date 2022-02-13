#include <stdlib.h>

#include <assert.h>
#include "state_mach.h"


struct state_machine
{
    const state_n_func_ty *states; 
    size_t num_states; 
    size_t num_events;
};

state_mach_ty *SMCreate(const state_n_func_ty *states, 
                        size_t num_states, 
                        size_t num_events)
{
    state_mach_ty *ret_val = NULL;

    /*assert(states);*/
    assert(states);

    /*allioc a memory to the Return State*/
    ret_val = (state_mach_ty *) malloc(sizeof(state_mach_ty));
	
	
    /*We will check the alocation*/
    if (NULL == ret_val)
    {
        return NULL;
    }

    /*We will initialize the values ​​in the structure*/
    ret_val->states = states;
    ret_val->num_states = num_states;
    ret_val->num_events = num_events;

    /*We'll return the state*/
    return ret_val;
}

/*
int SMTriggerEvent(state_mach_ty *st_m, 
                   int curr_state, 
                   int event,
                   void *func_param)
{
    state_n_func_ty *curr = NULL;
    
    /*assert(st_m);*/
/*    assert(st_m);

    curr = (state_n_func_ty *)st_m->states;
    
    /*move to the correct place in the table
             according to the rows and columns*/
/*    curr += (curr_state * st_m->num_events) + event;

    /*Performs the function according to the parameter*/
/*    curr->func(func_param);

    /*Returns the next state*/
/*    return curr->m_state;
}

*/

int SMTriggerEvent(state_mach_ty *st_m_, 
                   int curr_state_, 
                   int event_,
                   void *func_param_)
{
    int idx = 0;   /* idx of struct state_n_func */
    
    assert(NULL != st_m_);
    assert(NULL != func_param_);
    assert(curr_state_ < (int)st_m_->num_states  &&  0 <= curr_state_ );
    assert((size_t)event_ < st_m_->num_events  &&  0 <= event_);
    
    idx = curr_state_ * st_m_->num_events + event_;
    st_m_->states[idx].func(func_param_);            /* TODO what is func_param  ? */
    
    return st_m_->states[idx].m_state;
}

void SMDestroy(state_mach_ty *st_m)
{
    assert(st_m);
    
    st_m->states = NULL;

    free(st_m);
}
