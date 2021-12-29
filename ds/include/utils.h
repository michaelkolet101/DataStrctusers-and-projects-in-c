#ifndef __UTILS_H__
#define __UTILS_H__

#include <stdio.h>

#define UNUSED(x) ((void)x)

#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

#define RET_IF_BAD(aquired, bad) 		if(bad == (aquired)) \
{                                                            \																									   return bad;                                                  \
}



#define ALLOC_CHK_FREE(a,b,c)	\
{				 	 			\
	if(NULL == a) 			 	\
	{						 	\
			free(b);			\
			return c;		 	\
	} 							\
}																								

#define ALLOC_CHK(a,b)	\
{				 	 			\
	if(NULL == a) 			 	\
	{						 	\
			free(b);			\
							 	\
	} 							\
}	
	

/*																									puts(msg); \
																									return bad; \
																				 				}
#define RET_STAT_IF_BAD(aquired, bad, msg, status) 		if(bad == (aquired)) \
																								{\
																									/*puts( RED msg RESET); \
																									return status; \
																								}																				 				
#define RET_FREE_IF_BAD(aquired, msg, freeme) 		if(NULL == (aquired)) \
																								{\
																									puts( RED msg RESET); \
																									free(freeme); \
																									return NULL; \
																								}
																				 				
#define TESTBOOL(x) ( x? BOLDGREEN "GOOD" RESET : BOLDRED "BAD" RESET )
#define RESCMP(x) ( x? BOLDRED "BAD" RESET : BOLDGREEN "GOOD" RESET )

#define PRINTEST(name ,exp, res)  (printf(name "\tFunction Test ...... %s\n", TESTBOOL(res == exp)))

#define PRINTESTCMP(name ,exp, res, cmp)  \
(printf(name "\tFunction Test ...... %s\n", RESCMP(cmp(exp,res))))
*/
#define RESET   "\033[0m" 	/*	Reset Color */
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


#endif /*__UTILS_H__*/
