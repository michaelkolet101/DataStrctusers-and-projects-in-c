#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>	/* fputs fprintf */
#include <string.h>	/* strlen strcmp */

/* colors */
#define RED   "\x1B[31m"
#define GREEN "\x1B[32m"
#define GOLD  "\x1B[33m"
#define RST   "\x1B[0m"

/******************************************************************************/
/* MIN2 and MAX2 */
#define MIN2(x, y) ((x < y) ? x : y)
#define MAX2(x, y) ((x > y) ? x : y)

/******************************************************************************/
/* failure handler macro functions */
#define RETURN_VAL_IF_VAL(x, v)  if(v == x)    return x;
#define RETURN_NULL_IF_VAL(x, v) if(v == x)    return NULL;
#define RETURN_NULL_IF_NULL(x)   if(NULL == x) return NULL;
#define RETURN_FAIL_IF_NULL(x)   if(NULL == x) return FAIL;
#define RETURN_FAIL_IF_FAIL(x)   if(FAIL == x) return FAIL;

/* general "return if bad macro: " */
#define RETURN_IF_BAD(IS_GOOD, RET, MSG)                             \
if(!IS_GOOD)                                                         \
{                                                                    \
	fputs(MSG, stderr);                                              \
	fprintf(stderr, " expression: %s has failed\n", #IS_GOOD);       \
	fprintf(stderr, "file: %s line: %d compiled at: %s\n",           \
	                    __FILE__, __LINE__,      __TIME__);          \
	return RET;                                                      \
}                                                            

/* free struct and return if member allocation failed */
#define MEMBER_ALLOC_CHECK(s, m)	                \
if(NULL == (s->m))									\
{													\
	free(s);                                        \
	s = NULL;										\
	return NULL;									\
}

/******************************************************************************/
/* static assert macro (language sensetive) */
#if __cplusplus<201104
#define STATIC_ASSERT(EXP, NAME) enum {NAME = 1/EXP};
#else
#define STATIC_ASSERT(EXP, NAME) static_assert(EXP);
#endif

/* debug mode macros */
#ifndef NDEBUG
	#define DEBUG_ONLY(exp) exp;
	#define DEBUG_ONLY_ARG(exp) ,exp
#else
	#define DEBUG_ONLY(exp) 
	#define DEBUG_ONLY_ARG(exp)
#endif


/******************************************************************************/
/* Test utities functions declarations */

void PrintTestHeader();

/* prints the boolean result of test function */
void PrintTestResult(const char *func_name, const int state,  char *test_case);

/* prints the boolean result of int test function, 
   prints additional info in case */
void PrintIntTestResult(
	const char *func_name, 
	const int expected,
	const int aquired,  	  
	char *test_case
);

void PrintDblTestResult(
	const char *func_name, 
	const double expected,
	const double aquired,  	  
	char *test_case
);

void PrintStrTestResult(
	const char *func_name, 
	const char *expected,
	const char *aquired,  	  
	char *test_case
);

#endif /*__UTILS_H__*/
