#include "../PERLIN/perlin.h"
#include "../UTILS/utils.h"
#include "../PLAYER/player.h"
#include "../POKEDEX/pokedex.h"
#include "../BATTLE/battle.h"
#include "../DATABASE/database.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "map.h"
#include <unistd.h>

const int MAX_X = 100;
const int MAX_Y = 100;

void movePlayer(char ** map, Player * p, char movement, Pokedex * pokedex) {

    int x = 0;
    int y = 0;

    if(movement == 'z' || movement == 'Z') {
        x = -1;
    } else if (movement == 's' || movement == 'S') {
        x = 1;
    } else if (movement == 'q' || movement == 'Q') {
        y = -1;
    } else if (movement == 'd' || movement == 'D') {
        y = 1;
    } else {
        return;
    }

    if(p->x + x < 0 || p->x + x >= MAX_X - 1 || p->y + y < 0 || p->y + y >= MAX_Y - 1) {
        return;
    }

    if(map[p->x + x][p->y] == '@' || map[p->x][p->y + y] == '@') {
        return;
    }

    if(map[p->x + x][p->y] == 'W' || map[p->x][p->y + y] == 'W') {
        srand(time(NULL));
        if(rand() % 10 == 0) {
            launchBattle(p, pokedex);
            healPokemon(p);
        }
    }    
    
    if(x != 0) {
        p->x += x;
    } else {
        p->y += y;
    }
}

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
    printf("Move around with ZQSD or zqsd, 'p' or 'P' to see the pokedex, 'x' or 'X' to save and 'o' or 'O' to exit !\n\n");
    for(int i = -10; i < 11; i++) {
        if (p->x + i < 0 || p->x + i >= MAX_X - 1) {
            for(int j = 0; j < 51; j++) {
                printf("%c", '_');
            }
        } else {
            for(int j = -25; j < 26; j++) {
                if (p->y + j < 0 || p->y + j >= MAX_Y - 1) {
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
        x = rand() % (MAX_X - 4) + 2;
        y = rand() % (MAX_Y - 4) + 2;
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

void freeMap(char ** map) {
    for(int i = 0; i < MAX_X+1; i++) {
        free(map[i]);
    }
    free(map);
}

void printCurrentPokedex(Pokedex * pokedex) {

    printf("This is your current pokedex !\n\n");

    for(int i = 0; i < pokedex->nbPokemons; i++) {
        if (pokedex->pokemons[i]->isSeen == 1) {
            printf("%s - %s", pokedex->pokemons[i]->name, "Seen\n");
        } else {
            printf("%s - %s", "???????", "Unknown\n");
        }
    }

    sleep(10);

    return;

}

void createMap(Player * player, Pokedex * pokedex)
{
    cls();
    printf("Game is Launching......");
    int x, y;

    char ** map = malloc(sizeof(char *) * ((MAX_X + 1)));
    for(int i = 0; i < MAX_X+1; i++) {
        map[i] = malloc(sizeof(char) * MAX_Y);
    }

    for(y=0; y<MAX_X+1; y++) {
        for(x=0; x<MAX_Y; x++) {
            double result = perlin2d(x, y, 0.1, 4);
            if(result > 0.65) {
                map[y][x] = 'W';
            } else if (result > 0.4) {
                map[y][x] = '.';
            } else {
                map[y][x] = '@';
            }
        }
        map[y][MAX_Y-1] = '\n';
    }
    initPlayer(map, player);
    //printMap(map, 26, 30, player);
    cls();
    //printAroudPlayer(map, player);
    char movement = 0;
    do {

        scanf("%c", &movement);
        fflush(stdin);
        cls();
        if (movement == 'p' || movement == 'P') {
            printCurrentPokedex(pokedex);
        } else if (movement == 'x' || movement == 'X') {
            savePlayer(player);
        } else {
            movePlayer(map, player, movement, pokedex);
        }
        printAroudPlayer(map, player);

    }while(movement != 'o' && movement != 'O');

    freeMap(map);

    return;
}