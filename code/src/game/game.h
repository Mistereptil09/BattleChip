#ifndef GAME_H
#define GAME_H
typedef struct
{
    int x;
    int y;
} Position;

typedef enum
{
    BOAT_HORIZONTAL,
    BOAT_VERTICAL,
} BoatOrientation;

typedef struct
{
    Position position;
    int length;
    int orientation;
    int hit;
    int sunk;
} Boat;

typedef struct
{
    char* name;
    int position;
    Boat* boats;
} Player;

#endif // GAME_H
