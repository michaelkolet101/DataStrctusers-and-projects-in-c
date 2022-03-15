/*******************************************************************************
Data Structures WorkSheet 4: Slist.

Written by: Michael Kolet
Reviewd by: larisa

Tests for WS
*******************************************************************************/

#include <stdio.h>	/* printf */
#include <assert.h>	/* assert */

#include "simple_UID.h"

/* Typedefs: */
typedef enum test_stat
{
	TEST_PASS = 0,
	TEST_FAIL = 1
	
}test_stat_ty;

/* Test functions declarations: */
test_stat_ty TestsSimpleUID(void);



/**************************** Main Function ***********************************/

int main(void)
{
	printf("\nSIMPLEUID final test result: %s\n", TestsSimpleUID()?"FAIL":"PASS");
	
	return 0;
}

/*************************** Test Functions ***********************************/

test_stat_ty TestsSimpleUID(void)
{
	
	int check = -1;
	
	uid_ty uid = SimpleUIDCreate();
	uid_ty uid2 = SimpleUIDCreate();
	
	/* Test for create a SimpleUIDCreate */
	
	if (!SimpleUIDCmp(uid, BadUID))
	{
		puts("SimpleUIDCreate SUCCESS");	
	}
	else
	{
		puts("SimpleUIDCreate FAIL");
		return TEST_FAIL;
	}

	/************************************************************************/
	/* Test for create a SimpleUIDCmp */
	
    check = SimpleUIDCmp(SimpleUIDCreate(), uid2);
	
	if (check == 0)
	{
		puts("SimpleUIDCmp SUCCESS");

	}
	else
	{
		puts("SimpleUIDCmp FAIL");
		return TEST_FAIL;
	}

	return TEST_PASS;
}





