#include <limits.h>
#include "knight_walk.h"
#include "utils.h"

#define ROWS 8
#define COLUMNS 8
#define MAX_POSIALE_MOVES 8

#define NOT_VISITED 0
#define FIRST 0
#define VISITED 1

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


static size_t UpdateBitArrIMP(size_t bit_arr, size_t mask);
static move_ty NextStepIMP(int direction_, move_ty position);
static void UpdateVisitedIMP(move_ty position, route_ty *visited, int visited_count);
static size_t Coord2MaskIMP(move_ty position);
static size_t UpdateTheBordIMP(size_t board, move_ty position);
static IsBadMoveIMP(size_t board, move_ty position);


int KnightProblem(move_ty position , route_ty *visited)
{
    
    int ret = SUCCSES;
    size_t board = FIRST;  

    /*initialize the board and visit where the knight starts*/
    board = UpdateTheBordIMP(board, position);
    
    /*update the arr to return*/
    UpdateVisitedIMP(position, visited, FIRST);
    
    /*call to recurtion func*/
    ret = Solution(board, position, visited, VISITED);

    return ret;
}

int Solution(size_t board, move_ty position, route_ty *visited, int visited_count)
{
    
    size_t mask = 0; 

    int possible_moves = 0;

        /*if this tour covers all squares*/
    if (ULONG_MAX == board)
    {
        /*return visited*/
        return SUCCSES;
    }

    /*for all the untried tours*/
    for (possible_moves = 0; possible_moves <= MAX_POSIALE_MOVES; ++possible_moves)
    {
        /*generate the next tour */
        position = NextStepIMP(possible_moves, position);
    
        /*if visited already or is not a square on board*/
        if (IsBadMoveIMP(board, position))
        {
            /*contine*/
            continue;
        }
        
    
        board = UpdateTheBordIMP(board, position);
        
        /*update the arr to return*/
        UpdateVisitedIMP(position, visited, visited_count);

        /*call to recurtion func*/
        Solution(board, position, visited, VISITED + visited_count);
    }

    return FAIL;
}

static move_ty NextStepIMP(int direction_, move_ty position)
{
    /* Possible moves a knight can take */
    const move_ty directions[] = {{-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
                                {1, -2}, {1, 2}, {2, -1}, {2, 1}};
    
    position.x += directions[direction_].x;
    position.y += directions[direction_].y;

    return position;
}

static void UpdateVisitedIMP(move_ty position, route_ty *visited, int visited_count)
{
    visited[visited_count].x = position.x;
    visited[visited_count].y = position.y;
}


size_t Coord2MaskIMP(move_ty position)
{
    size_t idx = ROWS * position.y + position.x;
    
    return 1U << idx;
}

static size_t UpdateBitArrIMP(size_t bit_arr, size_t mask)
{
    return bit_arr | mask;
}

static size_t UpdateTheBordIMP(size_t board, move_ty position)
{
    /*convert cord to idx*/
    size_t mask = Coord2MaskIMP(position);
    /*update the idx of bit*/
    board = UpdateBitArrIMP(board, mask);  

    return board; 
}

static int IsBadMoveIMP(size_t board, move_ty position)
{
    size_t mask = Coord2MaskIMP(position);

    return ((mask == mask & board) ||
            (position.x > ROWS) ||
             (position.x < 0) ||
              (position.y < 0) ||
               (position.y > COLUMNS)); 
}