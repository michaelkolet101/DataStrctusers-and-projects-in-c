
#include "calculator.h"
#include "utils.h"


static event_ty Token2Event(const char_);
static void InitCalc(calc_ty *calc_)
static int IsOpStrongerIMP(calc_ty *calc_);
static int IsBadOperatorIMP(calc_ty *calc_);
static calcIMP(calc_ty *calc_);

static void BadFuncIMP();
static void AddOpIMP(calc_ty *calc_);
static void AddNumIMP(calc_ty *calc_);
static double FinalCalcIMP(calc_ty *calculator);
static const operator_ty *Token2OperIMP(const char *token_);
static  InitStaets();

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


static const stare_n_func_ty sm_table[] =
{
    {WAIT_OP, AddNumIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP},
    {BAD, BadFuncIMP}, {WAIT_NUM, AddOpIMP}, {EXP_END ,CalcIMP} ,{BAD, BadFuncIMP},
    {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP},
    {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}, {BAD, BadFuncIMP}
}


struct calculator
{
    stack_ty *m_num_stack;
    stack_ty *m_op_stack;
    char *m_curr_token;
};


struct operator_struct
{
    int m_precedence;
    double (*m_op_func)(double a, double b);
};




double Calculate(const char *exp_)
{
    /*declear calc_ty *calc */
    calc_ty *calc = NULL;
    event_ty curr_state = WAIT_NUM;
    state_mach_ty *state_mach = NULL; 

    /*creat state machin SMcreat(InitStaets(), NUM STATES, NUM EVENT)*/
    state_mach = SMCreate(InitStaets(), 
                            NUM STATES, 
                            NUM EVENT);
    /*chack alloc*/
    if (NULL == state_mach)
    {
        return FAIL;
    }
    
    /*initCalc(calc)*/
    calc = InitCalc(calc);

    /*chack alloc */
    if ( NULL == calc )
    {
        return FAIL;
    }
    
    /*while exp not '\0'*/
    while (curr_state != BAD)
    {
        /*calculator-> curr_token = *exp */
        calc->m_curr_token = *exp;

         /*curr_state = SMTriggerEvent(state_mach, curr_state, 
                        Token2Event(calculator->curr_token, calc))*/
        curr_state = SMTriggerEvent(state_mach, curr_state, calc);

        /*++exp*/
        ++exp;
        
        /*chaek the status of SM*/
        /*if we are in state BAD*/
        if (curr_state == BAD)
        {
            return FAIL;
        }
        
        /*return FAIL*/
    }
    

    /*return result*/
}   


static const void InitCalc(calc_ty *calc_)
{
    /*assert calculator*/

    /*calclo -> m_num_stack = CrtatStack*/

    /*chack alloc from stack creat*/

    /*calcul -> num_op = creatStack*/

     /*chack alloc from stack creat*/

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
    return char2event[token_];
}

Token2Oprator(calc_ty *calculator)
{
    /*Initialize a lut of all the ASCI with bad except the operators*/
    /*get the char token from the calc struct*/
    /**/
}

static calcIMP(calc_ty *calc)
{

}

static int IsOpStrongerIMP(calc_ty *calc)
{

}

static int IsBadOperatorIMP(calc_ty *calc)
{

}



