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
    int boat_numbers;
    Boat* boats;
}
Player;

typedef struct
{
    int player_list_size;
    Player* players;
} PlayerList;



Player initPlayer(Boat* boats, char* playerName, int boat_number, int position);
Boat initBoat(int length, int size_x, int size_y);
void initGame(Player* players, int number_of_boats, int number_of_players, int size_x, int size_y, int placement);
void mainloop(int size_x, int size_y, Player* players);
Boat* initBoatManual(int size_x, int size_y, int boat_number);
#endif // GAME_H
