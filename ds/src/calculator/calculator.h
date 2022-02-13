/* Calc API LOG:
    - V 1.0     added header guards.
    - V 1.1     operator_struct and operator_ty typedef 
    */

#ifndef __CALC_H__
#define __CALC_H__

#include "stack.h"
#include "state_mach.h"

#define ILRD_NAN (0.0/0.0)


/* valid expression should contain at least one digit and assignment operator */
double Calculate(const char *exp);



#endif /* __CALC_H__ */