#include <stdio.h>
#include "knight_walk.h"  


struct move
{
	int x;
	int y;
};

struct route
{
    int x;
    int y;
};

int main(void) 
{         
    route_ty way[64] = {0};
    move_ty start = {4, 4};

    
    printf("%d\n", KnightProblem(start, way));

return 0;
 }
