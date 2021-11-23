#ifndef __WS5_H__
#define __WS5_H__


#include <stdlib.h>/*size_t*/

/*progmer name: michael kolet
  reviewer's name: tal cohen*/



 
/***************************  My functions   ********************************/

/*remove a file from the computer*/
void Removed(const char *user_input, const char *file_path);

/*close the program*/
int Exit(const char *user_input, const char *file_path);

/*print the count of lines in the file*/
int PrintCountLine(const char *user_input, const char *file_path);

/*append a string to the beging of thr file*/
int Prepend(const char *user_input, const char *file_path);

/*append a string to the beginning of the file*/
int Append(const char *user_input, const char *file_path);


#endif /*__WS5_H__*/






