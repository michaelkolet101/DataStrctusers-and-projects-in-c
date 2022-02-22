#include <stdlib.h>

#ifndef __KNIGHT_WALK_h__
#define __KNIGHT_WALK_h__

typedef struct move move_ty;
typedef struct route route_ty; 

int KnightProblem(move_ty position , route_ty *visited);


#endif /*__KNIGHT_WALK_h__*/
