#ifndef BOARD_H
#define BOARD_H
#include "game.h"

typedef struct
{
    Position position;
    short is_boat;
} BoardTiles;

typedef struct
{
    int size;
    BoardTiles** board_table_2d;
} Board;

#endif // BOARD_H
