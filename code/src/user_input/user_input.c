//
// Created by narbo on 26/09/2025.
//
#include <stdio.h>
#include "user_input.h"

#include <stdlib.h>

int user_input(char *str) {
    int input;
    int isError;
    do {
        printf("%s", str);
        isError = scanf("%d", &input);
    } while (isError);

    return input;
}

Position *choice_attack() {
    int col;
    do {
        col = user_input("Which column ?");
    } while (col >= 'A' && col < 'A' + 10);

    int row;
    do {
        row = user_input("Which row ?");
    } while (row >= 1 && row <= 10);

    Position *position = malloc(sizeof(Position));
    position->x = col - 'A';
    position->y = row - 1;
    return position;
}
