
#include "game.h"

#include <stdio.h>
#include <stdlib.h>

Player initPlayer(Boat* boats, char* playerName, int boat_number, int position) {
    Player player;
    player.position = position;
    player.boat_numbers = boat_number;
    player.name = playerName;
    player.boats = boats;

    return player;
}

Boat initBoat(int length, int size_x, int size_y) {
    Boat boat;
    boat.length = length;
    boat.hit = 0;
    boat.sunk = 0;
    boat.orientation = rand() % 2;
    boat.position.x = rand() % size_x;
    boat.position.y = rand() % size_y;

    return boat;
}

Boat* initBoatManual(int size_x, int size_y, int boat_number) {
    char *ship_names[] = {"Porte-avions", "Croiseur", "Destroyer 1", "Destroyer 2", "Torpilleur"};
    int ship_sizes[] = {5, 4, 3, 3, 2};
    Boat* boats = malloc(sizeof(Boat) * boat_number);


    for (int i = 0; i < boat_number; i++) {
        printf("Placez votre %s (%d cases)\\n", ship_names[i], ship_sizes[i]);
        printf("Position de départ (ex: B3): ");
        char* result[3] = {0};
        scanf("%s", &result[0]);

        char* orientation[2] = {0};
        printf("Enrez l'orientation (H/V): ");
        scanf("%c", &orientation[0]);

        int max_x= 65 + size_x;
        Position* position = malloc(sizeof(Position) * boat_);

        if (result[0] >= 65 && result[0] <= max_x){
            if (result[1] >= 1 && result[1] <= size_y){
                if (orientation[0] == 'H'){
                    if (result[0]+ship_sizes[i] <= max_x){

                        for (int j = 0; j < number_of_boats; j++) {
                            if (boats[j].position.x){

                            }
                        }
                    }
                } else if (orientation[0] == 'V') {

                }
            }
        }
    }
    return boats;
}

void initGame(Player* players, int number_of_boats, int number_of_players, int size_x, int size_y, int placement) {
    for (int i = 0; i < number_of_players; i++) {
        if (placement == 0){
            Boat* boats = malloc(sizeof(Boat) * number_of_boats);
            int counter = 2;
            for (int j = 0; j < number_of_boats; j++) {
                Boat boat = initBoat(counter, size_x, size_y);
                boats[j] = boat;
                counter++;
                if (counter > 5) {
                    counter = 3;
                }
            }
            char* name = malloc(sizeof(char) * 10);
            sprintf(name, "Player%d", i);
            players[i] = initPlayer(boats, name, number_of_boats, i);
        }
        else {
            initBoatManual(size_x, size_y, number_of_boats);
        }
    }
}

void attack(Player* player, Position position) {
    Boat* boats = player->boats;
    int any_hit = 0;
    for (int i = 0; i < player->boat_numbers; i++) {
        printf("boat x: %d, y: %d\n", boats[i].position.x, boats[i].position.y);
        printf("boat len: %d\n", boats[i].length);

        // boat horizontal check position x+j
        if (boats[i].orientation == BOAT_HORIZONTAL) {
            for (int j = 0; j < player->boats[i].length; j++) {
                if (boats[i].position.x+j == position.x && boats[i].position.y == position.y && boats[i].sunk == 0) {
                    boats[i].hit++;
                    any_hit = 1;
                    printf("HIT\n");

                    if (boats[i].hit >= boats[i].length) {
                        boats[i].sunk = 1;
                        printf("BOUM! Boat %d sunk\n", i);
                    }
                    break;
                }
            }
        }

        // boat vertical check position y+j
        else {
            for (int j = 0; j < player->boats[i].length; j++) {
                if (boats[i].position.x == position.x && boats[i].position.y+j == position.y && boats[i].sunk == 0) {
                    boats[i].hit++;
                    any_hit = 1;
                    printf("HIT\n");

                    if (boats[i].hit >= boats[i].length) {
                        boats[i].sunk = 1;
                        printf("BOUM! Boat %d sunk\n", i);
                    }
                    break;
                }
            }
        }
    }

    if (any_hit == 0) {
        printf("PLOUF\n");
    }
}

Position get_input(int size_x, int size_y) {
    Position input;
    input.x = rand() % size_x;
    input.y = rand() % size_y;
    return input;
}

int check_lose(Player player) {
    int sunk_boats = 0;
    for (int i = 0; i < player.boat_numbers; i++) {
        if (player.boats[i].sunk == 1) {
            sunk_boats++;
        }
    }
    if (sunk_boats >= player.boat_numbers) {
        return 1;
    }
    return 0;
}

void mainloop(int size_x, int size_y, Player* players) {
    int player_number = 2;

    while (1) {
        Position input = get_input(size_x, size_y);
        printf("input x: %d, y: %d\n", input.x, input.y);
        // attaque adversaire
        if (player_number == 0) {
            player_number++;
            attack(&players[1], input);

            if (check_lose(players[1])) {
                printf("Player: %s", players[1].name);
                break;
            }
        }
        // attaque adversaire
        else {
            player_number--;
            attack(&players[0], input);

            if (check_lose(players[0])) {
                printf("Player: %s", players[0].name);
                break;
            }
        }
        printf("Round finished\n");
    }
        printf("Game finished\n");
}