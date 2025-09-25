#include <stdio.h>
#include "display.h"

void display (char** map) {
    for (char row = 'A'; row < 'A' + 10; row++) {
        printf("\t%c", row);
    }
    for(int row = 0; row < 10; row++) {
        printf("%c\t", row);
        for(int column = 0; column < 10; column++) {
            printf("%c\t", map[row][column]);
        }
        printf("\n");
    }
}