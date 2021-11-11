#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "ws2_string.h"
char *StrChr(const char *some_string, int ch);

/********************************TestStrCpy()********************************/

int TestStrCpy()

{
	const char *source = "michael";
	char *destination = (char*)malloc(sizeof(source) + 1);
	
	if (destination == NULL)
	{
		   return 1;
	}
	else
	{
	StrCpy(destination, source);
	printf("it is from TestStrCpy() %s\n", destination);

	}
 	
 	free(destination);
	destination = NULL;

	return 0;



}


/*******************************TestStrnCpy()**********************************/




void TestStrnCpy()
{
	char* source = "michael";
    	char destination[20];
    	size_t num = 4;
	
	StrnCpy(destination, source, num);
	printf("it is from TestStrnCpy() %s\n", destination);


}





/*****************************testStrCaseCmp*******************************/



void testStrCaseCmp(const char *s1, const char *s2)
{
    printf("%s v. %s = ",s1,s2);
    if( StrCaseCmp(s1,s2)==0 )
        puts("match");
    else
        puts("no match");
}

int test2StrCaseCmp()
{
    char string1[] = "my name is michael kolet";
    char string2[] = "MY NAME IS MICHAEL KOLET";
    char string3[] = "my name is kolet michael";

    testStrCaseCmp(string1,string1);
    testStrCaseCmp(string1,string2);
    testStrCaseCmp(string1,string3);

    return(0);

}

/******************************************************************************/
void test()
{

char *string1 = "my name is michael kolet";
char ch = 'e';
char const *ptr1 = NULL;
char *ptr2 = NULL;



ptr1 = (char *)StrChr(string1 ,ch);
ptr2 = (char *)strchr(string1 ,ch);

printf("%s\n", ptr2);
printf("%s\n", ptr1);




}
















































/******************************************************************************/


























/******************************************************************************/
int main(void)
{
    /*testStrCpy();*/
    /*TestStrnCpy();*/
    /*test2StrCaseCmp();*/
    test();
    return 0;
}

























