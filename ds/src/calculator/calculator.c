#include <stdio.h>
#include "calculator.h"
#include "utils.h"
#include "state_mach.h"
#include <assert.h>


#define CAPACITY 10
#define ASCII_CHARS 256

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

struct calculator
{
    stack_ty *m_num_stack;
    stack_ty *m_op_stack;
    char *m_curr_token;
};
typedef struct calculator calc_ty;


struct operator_struct
{
    int m_precedence;
    double (*m_op_func)(double a, double b);
};
typedef struct operator_struct operator_ty;



static void AddNumIMP(void *calc_);
static char *PeekAndPop(stack_ty *stack);
double CharToDouble(char ch);
static void PopOperIMP(calc_ty *calc);
static void PushOperIMP(calc_ty *calc, void *elem);
static void PopDoubleIMP(calc_ty *calc);
static void PushDoubleIMP(calc_ty *calc, double *elem);

static double PlusFuncIMP(double num1, double num2);
static double MinusIMP(double num1, double num2);
static double MultiIMP(double num1, double num2);
static double DivIMP(double num1, double num2);


static event_ty Token2Event(const char *token_);

static calc_ty *InitCalc(calc_ty *calc_);
static int IsOpStrongerIMP(const char* op_token1, const char* op_token2);
static int IsBadOperatorIMP(calc_ty *calc_);


static void BadFuncIMP();
static void AddOpIMP(void *calc_);


static double FinalCalcIMP(calc_ty *calc_);
static const operator_ty *Token2OperIMP(const char *token_);

static double CalcIMP(void *calc_);






static const state_n_func_ty sm_table[] = {
    {WAIT_OP, AddNumIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP},
    {BAD, BadFuncIMP}, {WAIT_NUM, AddOpIMP}, {EXP_END ,CalcIMP} ,{BAD, BadFuncIMP},
    {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP},
    {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}
};

double Calculate(const char *exp)
{
    /*declear calc_ty *calc */
    calc_ty *calc = {0};
    state_ty curr_state = WAIT_NUM;
    event_ty event = NUMBER;
    state_mach_ty *state_mach = NULL;
    double ret = 0; 

    /*creat state machin SMcreat(InitStaets(), NUM STATES, NUM EVENT)*/
    state_mach = SMCreate(sm_table, 
                            CALC_NUM_STATES, 
                            NUM_EVENTS);
    /*chack alloc*/
    if (NULL == state_mach)
    {
        return ILRD_NAN;
    }
    
    /*initCalc(calc)*/
    calc = InitCalc(calc);

    /*chack alloc */
    if ( NULL == calc )
    {
        return ILRD_NAN;
    }

    /*calculator-> curr_token = *exp */
    calc->m_curr_token = (char *)exp;


    /*while exp not '\0'*/
    while ('\0' != *(calc->m_curr_token))
    {
         /*curr_state = SMTriggerEvent(state_mach, curr_state, 
                        Token2Event(calculator->curr_token, calc))*/
                        /*TODO chang the op to func!*/
        curr_state = SMTriggerEvent(state_mach, curr_state, event, calc);

        /*++calc->m_curr_token*/
        ++calc->m_curr_token;

        /*chaek the status of SM*/
        /*if we are in state BAD*/
        if (curr_state == BAD)
        {
            /*return FAIL*/
            return ILRD_NAN;
        }
    }
    
    if (curr_state == EXP_END)
    {
        /*ret is result of the stacks*/
        ret += FinalCalcIMP(calc);
    }
    
    return ret;
}   

static calc_ty *InitCalc(calc_ty *calc_)
{
    /*assert calculator*/
    assert(calc_);
    
    /*calclo -> m_num_stack = CrtatStack*/
    calc_->m_num_stack = StackCreate(sizeof(double), CAPACITY);
    /*chack alloc from stack creat*/
    if ( NULL == calc_->m_num_stack )
    {
        return NULL;
    }
    
    /*calcul -> num_op = creatStack*/
    calc_->m_op_stack = StackCreate(sizeof(char), CAPACITY);

     /*chack alloc from stack creat*/
    if ( NULL == calc_->m_op_stack )
    {
        return NULL;
    }

    return calc_;
}

static event_ty Token2Event(const char *token_)
{
    /*Initialize a lut of all the ASCI with bad except the numbers*/
    static const event_ty char2event[ASCII_CHARS] =
	{   
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		OPERATOR, OPERATOR, BAD_TOKEN, OPERATOR, BAD_TOKEN, OPERATOR, NUMBER, 
		NUMBER,NUMBER, NUMBER, NUMBER, NUMBER, NUMBER, NUMBER, NUMBER, NUMBER, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, EQUAL, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN,
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, BAD_TOKEN, 
		BAD_TOKEN, BAD_TOKEN     
	};
	
    /*Returns the index of the  character*/
    return char2event[*(int *)token_];
}

operator_ty *Token2Oprator(const char op)
{

    

    /*Initialize a lut of all the ASCI with bad except the operators*/
    operator_ty plus = {0}, minus = {0}, multi = {0}, division = {0} ;
    
    operator_ty opers[] = {{3 ,MultiIMP}, { 4, PlusFuncIMP}, {0} , {4 , MinusIMP}, {0} , { 3,DivIMP }};
    
    assert((op >= 42) || (op <= 47));   

    return &opers[op - 42]; 
}

static double PlusFuncIMP(double num1, double num2)
{
    return num1 + num2;
}

static double MinusIMP(double num1, double num2)
{
     return num1 - num2;
}

static double MultiIMP(double num1, double num2)
{
     return num1 * num2;
}

static double DivIMP(double num1, double num2)
{
     return num1 / num2;
}


static int IsOpStrongerIMP(const char* op_token1, const char* op_token2)
{                       
    operator_ty *op1 = {0};
    operator_ty *op2 = {0};

    op1 = Token2Oprator(*op_token1);
    op2 = Token2Oprator(*op_token2);

    return op1->m_precedence > op2->m_precedence;
}

static int IsBadOperatorIMP(calc_ty *calc)
{
    
}

/*print errow*/
static void BadFuncIMP(void *p)
{
    printf("Error");
}

/*add oprator to stack and chack if need to do calculet befor */
static void AddOpIMP(void *calc_)
{
    calc_ty *calc = (calc_ty *)calc_;
    char *oper_to_insert = calc->m_curr_token;
    char *oper_in_stack = (char *)StackPeek(calc->m_op_stack);

    if (IsOpStrongerIMP(oper_in_stack, oper_to_insert))
    {
        double ret = CalcIMP(calc_);
        const void *to_push = (void *)&ret;
        /*to do the calc and remove from stack*/
        StackPush(calc->m_num_stack, to_push);
    }
    
    StackPush(calc->m_op_stack, (void *)(calc->m_curr_token));
}

static double CalcIMP(void *calc_)
{
    calc_ty *calc = (calc_ty *)calc_; 
    double res = 0;

    double num1 = CharToDouble(*(PeekAndPop(calc_->m_num_stack))) ;
    double num2 = CharToDouble(*(PeekAndPop(calc_->m_num_stack)));
    operator_ty *oper = Token2Oprator(*(PeekAndPop(calc_->m_num_stack))) ;

    res = oper->m_op_func(num1, num2);

    return res;
} 

/* add number to number stack*/
static void AddNumIMP(void *calc_)
{
     StackPush(((calc_ty *)calc_)->m_num_stack,(((calc_ty *)calc_)->m_curr_token));
}

static char *PeekAndPop(stack_ty *stack)
{
    char *top_ch_in_stack = (char *)StackPeek(stack);
    StackPop(stack);

    return top_ch_in_stack;
}

double CharToDouble(char ch)
{
    double num = 0;
    num = (double)((int)(ch) - '0'); 

    return num;
}

static void PopOperIMP(calc_ty *calc)
{
    StackPop(calc->m_op_stack);
}

static void PushOperIMP(calc_ty *calc, void *elem)
{
    StackPush(calc->m_op_stack, elem);
}

static void PopDoubleIMP(calc_ty *calc)
{
    StackPop(calc->m_num_stack);        
}

/*stack_ty *m_num_stack;
stack_ty *m_op_stack;
char *m_curr_token;*/

static void PushDoubleIMP(calc_ty *calc, double *elem)
{
    StackPush(calc->m_num_stack, (void *)elem);
}

static double FinalCalcIMP(calc_ty *calc_)
{
    double res = 0;
    
    while (!StackIsEmpty(calc_->m_num_stack))
    {
        res += CalcIMP(calc_);
    }

    return res;    
}