#include <stdio.h> /*printf , puts */

#include "calculator.h"


enum{NUM_BAD_EXP = 6 , NUM_GOOD_EXP = 6};

void BadExpTest(void);
void GoodExpTest(void);
int main(void)
{
	BadExpTest();
	GoodExpTest();
	return 0;
}

void BadExpTest(void)
{
	int i = 0;
	static const char * bad_exps[] = {
	 "=",
	 "-",
	 "=4",
	 "7*",
	 "3+4",
	 "45"};
	 
	 puts("Test of bad expressions");

	 for (i = 0 ; i < NUM_BAD_EXP;++i)
	 {
		 printf("for exp %s -> %f \n",bad_exps[i],Calculate(bad_exps[i]));
	 }

}

void GoodExpTest(void)
{
	int i = 0;
	static const char * bad_exps[] = {
	 "4=",/*4.0*/
	 "5+6=",/*11.0*/
	 "5*5/5=",/*5.0*/
	 "7+9-3=",/*13.0*/
	 "1*1*5=",/*5.0*/
	 "4*5/7+5-6="};/*same as b*/
	 double b = 4.0 * 5.0/7.0 + 5.0 - 6.0;
	 printf("comlex exp= %f\n", b);
	 puts("Test of Good expressions");

	 for (i = 0 ; i < NUM_GOOD_EXP ;++i)
	 {
		 printf("for exp %s -> %f \n",bad_exps[i],Calculate(bad_exps[i]));
	 }
}
