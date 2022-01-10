/*******************************************************************************
Data Structures WorkSheet UID.

Written by: Michael Kolet
Reviewd by: tal

Functions for WS
*******************************************************************************/
#include <stddef.h>	/* size_t */
#include <time.h> /*time_t*/
#include <sys/types.h>
#include <unistd.h>

#include "simple_UID.h"

/****************************************************************************/

uid_ty const BadUID = {0};

uid_ty SimpleUIDCreate(void)
{
	static size_t uid_counter = 0;
	uid_ty new_uid = {0};
	
	new_uid.pid = getpid();
	new_uid.time = time(NULL);
	new_uid.counter = uid_counter;
	
	if (new_uid.time == (time_t)-1)
	{
		return BadUID;
	} 
	
	++uid_counter;
	
	return new_uid;
}

int SimpleUIDCmp(uid_ty uid1, uid_ty uid2)
{
	return (uid1.pid == uid2.pid) && 
			(uid1.time == uid2.time) && 
			(uid1.counter == uid2.counter);
}








