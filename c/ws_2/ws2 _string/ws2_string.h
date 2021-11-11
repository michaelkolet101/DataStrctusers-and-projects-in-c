#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SUCSSES 1
#define FAIL 0


/***************************  My functions   ********************************/

/*A function that receives a pointer to a string and returns the character 
association in the string*/
size_t StrLen(const char *pointer_to_string);


/*A function that checks if strings are equal to each other, if returns 0 
then they are equal*/
int StrCmp(const char *first_string, const char *second_string);

/*The function copies a string that points to a pointer to one destination and 
returns a pointer that points to it*/
char *StrCpy(char* destination, const char* source);

/**/
char *StrnCpy(char* destination, const char* source, size_t num);


int StrCaseCmp(const char *s1, const char *s2);

/*function returns a pointer to the first occurrence of the character
 c in the string s*/
char *StrChr(const char *some_string, int ch);


/**********************      TESTS      **************************************/


/*Test for StrCpy function*/
void testStrCpy();

/*Test for StrnCpy function*/
void TestStrnCpy();
void testStrCaseCmp(const char *s1, const char *s2);
int test2StrCaseCmp();
void test();























