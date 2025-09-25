#include <stdio.h>
#include "display.h"

void display (char** map) {
    for (int )
    for(int row = 0; row < 10; row++) {
        for(int column = 0; column < 10; column++) {
            printf("%c\t", map[row][column]);
        }
        printf("\n");
    }
}