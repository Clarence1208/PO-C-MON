#include "PERLIN/perlin.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int x;
    int y;
}Player;

void printMap(char ** map, int row, int column, Player * p) {
    for (int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            if (p->x == i && p->y == j) {
                printf("\033[1;31m%c\033[0m", 'X');
            } else if (map[i][j] == 'W'){
                printf("\033[1;32m%c\033[0m", 'W');
            } else if (map[i][j] == '@'){
                printf("\033[1;34m%c\033[0m", '@');
            } else {
                printf("%c", map[i][j]);
            }
        }
    }
}

void printAroudPlayer(char ** map, Player * p) {
    for(int i = -4; i < 5; i++) {
        if (p->x + i < 0 || p->x + i >= 24) {
            for(int j = 0; j < 13; j++) {
                printf("%c", '_');
            }
        } else {
            for(int j = -6; j < 7; j++) {
                if (p->y + j < 0 || p->y + j >= 29) {
                    printf("%c", '|');
                } else if (i == 0 && j == 0) {
                    printf("\033[1;31m%c\033[0m", 'X');
                } else {
                    if (map[p->x + i][p->y + j] == 'W') {
                        printf("\033[1;32m%c\033[0m", map[p->x + i][p->y + j]);
                    } else if (map[p->x + i][p->y + j] == '@') {
                        printf("\033[1;34m%c\033[0m", map[p->x + i][p->y + j]);
                    } else { 
                        printf("%c", map[p->x + i][p->y + j]);
                    }
                }
            }
        }
        printf("\n");
    }
}

void initPlayer(char ** map, Player * p) {

    int test = 0;

    int x = 0;
    int y = 0;
    int count = 0;

    while (count != 25) {
        count = 0;
        srand(time(NULL));
        x = rand() % 21 + 2;
        y = rand() % 26 + 2;
        for(int i = -2; i < 3; i++) {
            for(int j = -2; j < 3; j++) {
                if(map[x + i][y + j] == '.' || map[x + i][y + j] == 'W') {
                    count++;
                }
            }
        }
    }
    p->x = x;
    p->y = y;
}

int main(int argc, char *argv[])
{
    int x, y;

    Player * player = malloc(sizeof(Player));

    char ** map = malloc(sizeof(char *) * ((25 + 1)));
    for(int i = 0; i < 26; i++) {
        map[i] = malloc(sizeof(char) * 30);
    }

    for(y=0; y<26; y++) {
        for(x=0; x<30; x++) {
            double result = perlin2d(x, y, 0.1, 4);
            if(result > 0.65) {
                map[y][x] = 'W';
            } else if (result > 0.5) {
                map[y][x] = '.';
            } else {
                map[y][x] = '@';
            }
        }
        map[y][29] = '\n';
    }
    initPlayer(map, player);
    //printMap(map, 26, 30, player);
    printAroudPlayer(map, player);
    return 0;
}