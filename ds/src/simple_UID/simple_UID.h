/* version 0.0 - after mentor's approval                                      */
/* version 1.0 - name correction for BadUID                                   */
/*             - complexity correction for Compare                            */

#include <time.h> /*time_t*/
#include <sys/types.h>
#include <unistd.h>

#ifndef __SIMPLE_UID_H__
#define __SIMPLE_UID_H__

typedef struct simple_uid
{
	pid_t pid;
	time_t time;
	size_t counter;
} uid_ty;



extern const uid_ty BadUID;

/******************************************************************************
* Function Description: returns a UID.   
* Arguments: none
* Return value: UID
* Notes: Returns BadUID in case of a failure

* Time Complexity: O(1)
*******************************************************************************/
uid_ty SimpleUIDCreate(void);

/******************************************************************************
* Function Description: compares two UIDs
* Arguments: two UIDs to compare
* Return value: int (boolean) with two possible values - 1 (true) and 0 (false)
* Notes:

* Time Complexity: O(1)
*******************************************************************************/
int SimpleUIDCmp(uid_ty uid1, uid_ty uid2);


#endif /*__SIMPLE_UID_H__*/
