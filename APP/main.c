#include "PERLIN/perlin.h"
#include <stdio.h>
#include <stdlib.h>

void printMap(char ** map, int row, int column) {
    for (int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            printf("%c", map[i][j]);
        }
    }
}

int main(int argc, char *argv[])
{
    int x, y;

    char ** map = malloc(sizeof(char *) * ((25 + 1)));
    for(int i = 0; i < 26; i++) {
        map[i] = malloc(sizeof(char) * 30);
    }

    for(y=0; y<26; y++) {
        for(x=0; x<30; x++) {
            double result = perlin2d(x, y, 0.1, 4);
            if(result > 0.70) {
                map[y][x] = 'W';
            } else if (result > 0.55) {
                map[y][x] = '.';
            } else {
                map[y][x] = '#';
            }
        }
        map[y][29] = '\n';
    }
    printMap(map, 26, 30);
    return 0;
}