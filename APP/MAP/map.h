#ifndef PO_C_MON_MAP_H
#define PO_C_MON_MAP_H

#include "../PERLIN/perlin.h"
#include "../UTILS/utils.h"
#include "../PLAYER/player.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void movePlayer(char ** map, Player * p, char movement, Pokedex * poke);

void printMap(char ** map, int row, int column, Player * p);

void printAroudPlayer(char ** map, Player * p);

void initPlayer(char ** map, Player * p);

void printCurrentPokedex(Pokedex * pokedex);

void createMap(Player * p, Pokedex * poke);

#endif