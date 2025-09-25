#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "display.h"
#include "game.h"


int main(void) {
    srand(time(NULL));

    //Boat boat;
    //initBoat(&boat, 5, 10, 10);


    int number_of_players = 2;
    int number_of_boats = 5;
    int size_x = 10;
    int size_y = 10;
    int placement = -1;

    while (placement != 1 && placement != 0) {
        printf("Comment placer les bateaux (0 = Aléatoire / 1 = (Em)Manuel)");
        scanf("%d", &placement);
    }

    Player* players = malloc(sizeof(Player) * number_of_players);
    initGame(players, number_of_boats, number_of_players, size_x, size_y, placement);

    for (int i = 0; i < number_of_players; i++) {
        printf("Player %d\n", i);
        for (int j = 0; j < players[i].boat_numbers; j++) {
            printf("x: %d, y: %d\n", players[i].boats[j].position.x, players[i].boats[j].position.y);
        }
        printf("\n");
    }

    mainloop(size_x, size_y, players);

}
