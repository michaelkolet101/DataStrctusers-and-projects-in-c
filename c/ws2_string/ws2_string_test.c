#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "ws2_string.h"


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

/*******************************TestStrChr**********************************/

void TestStrCmp()
{


char *str1 = "michael";
char *str2 = "michael";

/*printf("%d\n",strcmp(str1,str2));*/
printf("%d\n",StrCmp(str1,str2));


}





void TestStrChr()
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



void TestStrDup()
{
	char s[] = "it's working!!!!!! ";

	char *p = (char *)StrDup(s);

	puts(p);

	free(p);

}


void TestStrCat()
{

 char *str = (char*)calloc(100, 1);
 
    StrCat(str, "hii you, ");
    StrCat(str, "these ");
    StrCat(str, "– ");
    StrCat(str, "exercises ");
    StrCat(str, "are ");
    StrCat(str, "exhausting ");
    
     
    puts(str);
    free(str);

}





void TestStrnCat()
{
	char dest[30];
	char src[] = "kolet";
 
	strcpy(dest, "michael ");
	
	strncat(dest, src, 10); 	
	
	puts(dest);
    
    StrnCat(dest, src, 10);
    puts(dest);
    
 	

}


void TestStrStr()
{
	char *str1 = "Sitting on my vacation all day writing code";
	char *str2 = "all";
	char *str3 = "Sitting on my vacation all day writing code";
	char *str4 = "all";
	
	if (compare(StrStr(str1, str2),strstr(str3, str4)))
	{
	printf("SUCSSES\n");
	}
	else
	{
	printf("fail\n");
	}
	
}





/*TO DO - I did not really understand what to do*/
void TestStrSpn()
{
	char *str1 = "Sitting on my vacation all day writing code";
	char *str2 = "all";
	
	char *str3 = "Sitting on my vacation all day writing code";
	char *str4 = "all";
	
	printf("%ld \n",(size_t)(StrSpn(str1, str2)));
	printf("%ld \n",(size_t)(strspn(str3, str4)));
	
	if ((size_t)(StrSpn(str1, str2) == (size_t)strspn(str3, str4)))
	{
	printf("SUCSSES\n");
	}
	else
	{
	printf("fail\n");
	}
	
}






void TestisPalindrome()
{
char str[] = "michuelaleahcik";
IsPalindrome(str);
}



void TestSpace()
{
	char str[] = "     s        a       a         ";

	char *str1 = SpaceX(str);

	printf("%s\n",str1);
	printf("end\n");
}





int main(void)
{
	TestStrCmp(); 
	TestStrCpy();
	TestStrnCpy();
	test2StrCaseCmp();
	TestStrDup();
	TestStrCat();
	TestStrnCat();
	TestStrStr();
	TestStrSpn();
	TestisPalindrome();
	TestSpace();
    return 0;
}

























