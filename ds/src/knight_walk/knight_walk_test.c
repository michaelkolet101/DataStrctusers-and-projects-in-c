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
    move_ty start = {3, 3};

    int i = 0;
    printf("%d\n", KnightProblem(start, way));
    /*for (i = 0; i < 64; ++i)
    {         
        printf("%d, %d\n", way[i].m_row, way[i].m_column);
    } */    
return 0; }
