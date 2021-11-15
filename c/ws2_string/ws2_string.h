#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

/*Gets two strings and compares them while ignoring uppercase and
 lowercase letters*/
int StrCaseCmp(const char *s1, const char *s2);

/*function returns a pointer to the first occurrence of the character
 c in the string s*/
char *StrChr(const char *some_string, int ch);

char *StrDup(const char *s);

/*Receives two strings and returns a pointer to the string connected from both*/
char *StrCat(char *destination, const char *source);

/*The function gets two string strings and a number of characters per thread 
from the second string for the first time*/
char *StrnCat(char *destination, const char *source, size_t number_of_char);

/*Receives two strings and returns the first position of the small string 
inside the large one*/
char *StrStr(const char *haystack, const char *string_want_to_find);
int compare(const char *first_string, const char *second_string);


size_t StrSpn(const char *s1, const char *s2);

/*A function to check if a string str is palindrome*/
void IsPalindrome(char *str);

char* SpaceX(char *some_string);
/**********************      TESTS      **************************************/


void TestStrCmp();
void testStrCpy();/*Test for StrCpy function*/
void TestStrnCpy();/*Test for StrnCpy function*/
void testStrCaseCmp(const char *s1, const char *s2);
int test2StrCaseCmp();
void TestStrChr();

void TestStrDup();
void TestStrCat();
void TestStrnCat();
void TestStrStr();
void TestStrSpn();
void TestisPalindrome();

void TestSpace();



















