#ifndef __CALCULATOR_H__
#define __CALCULATOR_H__

#include "stack.h"
#include "state_mach.h"


/* states */
typedef enum {WAIT_NUM = 0,
              WAIT_OP = 1, 
              BAD = 2, 
              EXP_END = 3, 
              CALC_NUM_STATES = 4} state_ty;

/* events */
typedef enum {NUMBER = 0, 
              OPERATOR = 1, 
              EQUAL = 2, 
              BAD_TOKEN = 3, 
              NUM_EVENTS = 4} event_ty;

typedef struct calculator calc_ty;

/* should be moved to source file */
struct calculator 
{
    stack_ty *m_num_stack;
    stack_ty *m_op_stack;
    char *m_last_token;

};

/* valid expression should contain at least one digit and assignment operator */
double Calculate(const char *exp);


#endif /*__CALCULATOR_H__*/