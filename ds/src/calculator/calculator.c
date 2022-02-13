#include <assert.h> /* assert */

#include "calculator.h"
#include "state_mach.h"
#include "stack.h"

#include "utils.h"

#define ILRD_NAN (0.0/0.0)
enum {CAPACITY = 10};

/* states */
typedef enum {WAIT_NUM,
              WAIT_OP, 
              BAD, 
              EXP_END, 
              CALC_NUM_STATES} state_ty;

/* events */
typedef enum {NUMBER, 
              OPERATOR, 
              EQUAL, 
              BAD_TOKEN, 
              NUM_EVENTS} event_ty;
              
/* should be moved to source file */
typedef struct calculator 
{
    stack_ty *m_num_stack;
    stack_ty *m_op_stack;
    const char *m_curr_token;

}calc_ty;

typedef struct operator
{
    int m_precedence;
    double (*m_op_func)(double a, double b);
}operator_ty;

typedef void (*state_m_func)(void *);


/******************************************************************************/
static event_ty Token2EventIMP(const char *token_);
static int IsOpStrongerIMP(calc_ty *calc_, const operator_ty *operator_);  
const operator_ty *Token2OperIMP(const char* token);
void DestroyAllAllocMem(calc_ty *cala, state_mach_ty *state_mach_);

/* event functions */ 
static void AddNumIMP(calc_ty *calc_);
static void AddOpIMP(calc_ty *calc_);
static void BadFuncIMP(void *calc_);
static void FinalCalcIMP(calc_ty *calc_);

/* single calculate functions */
static double PlusIMP(double left_operand_, double right_operand_);
static double MinusIMP(double left_operand_, double right_operand_);
static double MultiIMP(double left_operand_, double right_operand_);
static double DivideIMP(double left_operand_, double right_operand_);
static double NoOpIMP(double left_operand_, double right_operand_);

/* service functions for stack */
static void PushDoubleIMP(calc_ty *calc_, double number_);
static double PopDoubleIMP(calc_ty *calc_);
static void PushOperIMP(calc_ty *calc_, const operator_ty *operator_);
static operator_ty *PopOperIMP(calc_ty *calc_);
/******************************************************************************/
/* valid expression should contain at least one digit and assignment operator */
double Calculate(const char *exp_)
{
    static const state_n_func_ty state_event_table[] =
    /* event/state NUMBER                               OPERATOR                            EQUAL                                   BAD_TOKEN */
    /* WAIT_NUM */ {{WAIT_OP, (state_m_func)AddNumIMP}, {BAD, BadFuncIMP},                  {BAD, BadFuncIMP},                      {BAD, BadFuncIMP},
    /* WAIT_OP */  {BAD, BadFuncIMP},                   {WAIT_NUM, (state_m_func)AddOpIMP}, {EXP_END, (state_m_func)FinalCalcIMP},  {BAD, BadFuncIMP},
    /* BAD */      {BAD, BadFuncIMP},                   {BAD, BadFuncIMP},                  {BAD, BadFuncIMP},                      {BAD, BadFuncIMP},
    /* EXP_END */  {BAD, BadFuncIMP},                   {BAD, BadFuncIMP},                  {BAD, BadFuncIMP},                      {BAD, BadFuncIMP}};
    
    /* create curr_state state_ty variable and init to WAIT_OP */
    state_ty curr_state = WAIT_NUM;
    
    /* create curr_event event_ty variable and init to 0 */
    event_ty curr_event = 0;
    
    /* create res double variable and init to NaN */
    double ret = ILRD_NAN;
    
    /* create state macine */
    state_mach_ty *s_machine = SMCreate(state_event_table, CALC_NUM_STATES, NUM_EVENTS);

    /* create and init calc_ty variable */
    calc_ty calc = {0};
    /* create 2 stacks */
    calc.m_num_stack = StackCreate(sizeof(double), CAPACITY);
    calc.m_op_stack = StackCreate(sizeof(operator_ty *), CAPACITY);
    if (NULL == s_machine || NULL == calc.m_num_stack || NULL == calc.m_op_stack)
    {
        DestroyAllAllocMem(&calc, s_machine);
        return ret;
    }
    calc.m_curr_token = (char *)exp_;

    assert(exp_);

    /* while *exp_ && state != BAD */
    while (*calc.m_curr_token && curr_state != BAD)
    {      
        /* sending a char to Token2EventIMP and recive back event */
        curr_event = Token2EventIMP(calc.m_curr_token);
        
        /* sending SM the event and the curr_state and save tha state in curr_state variable */
        curr_state = SMTriggerEvent(s_machine, curr_state, curr_event, &calc);

        /* calc.m_curr_token ++ */
        ++calc.m_curr_token;
    }
    /* if curr_state is EXP_END */
    if (curr_state == EXP_END)
    {
        /* ret is res */
        ret = PopDoubleIMP(&calc);
        assert(StackIsEmpty(calc.m_num_stack));
/*         assert(StackIsEmpty(calc.m_op_stack));
 */    }
    
    /* destroy SM */
    DestroyAllAllocMem(&calc, s_machine);    
    /* return ret */
    return ret;
}

/******************************************************************************/
static event_ty Token2EventIMP(const char *token_)
{
    /* static arr to all ascii table and their event */
    static const event_ty char2event[] =
    {   
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, OPERATOR,  OPERATOR,  BAD_TOKEN, 
    OPERATOR,  BAD_TOKEN, OPERATOR,  NUMBER,    NUMBER,    
    NUMBER,    NUMBER,    NUMBER,    NUMBER,    NUMBER,    
    NUMBER,    NUMBER,    NUMBER,    BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, EQUAL,     BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
    BAD_TOKEN   
    };

    /* return and translate token to enent */
    return char2event[(int)*token_];
}

const operator_ty *Token2OperIMP(const char *token_)
{
    /* create const static array of operator_ty in size 6 */
    /* init arr [0]('*'), arr[5]('/') to 1, and arr[1]('+'), arr[3]('-') to 0 */
    static const operator_ty token_2_op_table [6] = {{3, MultiIMP}, {4, PlusIMP}, 
                                                     {0, NoOpIMP}, {4, MinusIMP}, 
                                                     {0, NoOpIMP}, {3, DivideIMP}};
    
    /* translate and return */
    return (operator_ty *)token_2_op_table + *token_ - '*';
}

/* return if curr_token operator stronger than first operator in the stack of operators */
static int IsOpStrongerIMP(calc_ty *calc_, const operator_ty *operator_)
{
    /* smaller precedence is strong */
    /* return curr_token->precedence is stronger than first operator in m_op_stack precedence */
    return operator_->m_precedence < (*(operator_ty **)StackPeek(calc_->m_op_stack))->m_precedence;
} 

void DestroyAllAllocMem(calc_ty *calc_, state_mach_ty *state_mach_)
{
    StackDestroy(calc_->m_num_stack);
    StackDestroy(calc_->m_op_stack);
    SMDestroy(state_mach_);
}

/******************************************************************************/
static void AddNumIMP(calc_ty *calc_)
{
    /* translate to double and push curr token to stack of number */
    PushDoubleIMP(calc_, *(calc_->m_curr_token) - '0');
}

static void AddOpIMP(calc_ty *calc_)
{
    /* create operator_ty* operator */
    /* init operator - Token2OperIMP */
    const operator_ty *operator = {0};
    double res = 0;

    operator_ty *op = NULL;

    assert(calc_);

    operator = Token2OperIMP(calc_->m_curr_token);
    if (StackIsEmpty(calc_->m_op_stack))
    {
        PushOperIMP(calc_, operator);
        return;
    }
    while (1 < StackSize(calc_->m_num_stack))    
    {
        /* if curr token (the operator) is stronger (according to priority) */
        if (IsOpStrongerIMP(calc_, operator))
        {
            /* push curr token to stack of numbers */
            PushOperIMP(calc_, operator);
            return;
        }
        
        /*if (1 < StackSize(calc->m_num_stack))     
        {*/
        op = PopOperIMP(calc_);
        res = op->m_op_func(PopDoubleIMP(calc_), 
                                PopDoubleIMP(calc_));
                
            /* push the res to stack of numbers */
        StackPush(calc_->m_num_stack, &res);
    }
    PushOperIMP(calc_, operator);
}

static void BadFuncIMP(void *calc_)
{
   ;

}

static void FinalCalcIMP(calc_ty *calc_)
{
    double res = 0;
    double right_operand = 0;
    double left_operand = 0;
    operator_ty *op = NULL;

    /* finish calculation: */
    /* while the stack of numbers */
    while (1 < StackSize(calc_->m_num_stack))    
    {
        /* calculate 1st and 2nd numbers from stack of number and the 1st operator from stack operator  */
        right_operand = PopDoubleIMP(calc_);
        left_operand = PopDoubleIMP(calc_);
        /* right_operand = *(double *)PeekPopStack(((calc_ty *)calc_)->m_num_stack);
        left_operand = *(double *)PeekPopStack(((calc_ty *)calc_)->m_num_stack);
        op = (operator_ty *)PeekPopStack(((calc_ty *)calc_)->m_num_stack); */
        op = PopOperIMP(calc_);
        res = op->m_op_func(left_operand, right_operand);
        
        /* push the res to stack of numbers */
        StackPush(calc_->m_num_stack, &res);
    }
}

/******************************************************************************/
static double PlusIMP(double left_operand_, double right_operand_)
{
    return left_operand_ + right_operand_;
}

static double MinusIMP(double left_operand_, double right_operand_)
{
    return left_operand_ - right_operand_;
}

static double MultiIMP(double left_operand_, double right_operand_)
{
    return left_operand_ * right_operand_;
}

static double DivideIMP(double left_operand_, double right_operand_)
{
    return left_operand_ / right_operand_;
}

static double NoOpIMP(double left_operand_, double right_operand_)   
{
    
    

    return ILRD_NAN;
}

/******************************************************************************/
static void PushDoubleIMP(calc_ty *calc_, double number_)
{
    assert(calc_);

    StackPush(calc_->m_num_stack, &number_);
}

static double PopDoubleIMP(calc_ty *calc_)
{
    double ret = 0;
    
    assert(calc_);
    ret = *(double *)StackPeek(calc_->m_num_stack); 
    StackPop(calc_->m_num_stack);

    return ret;
}

static void PushOperIMP(calc_ty *calc_, const operator_ty *operator_)
{
    assert(calc_);

    StackPush(calc_->m_op_stack, &operator_);
}

static operator_ty *PopOperIMP(calc_ty *calc_)
{
    operator_ty *ret = {0};
    
    assert(calc_);

    ret = *(operator_ty **)StackPeek(calc_->m_op_stack);
    
    StackPop(calc_->m_op_stack);
    return ret;
}
