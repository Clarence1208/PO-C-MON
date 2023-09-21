// define only if not already defined
#include "pokemon.h"
#include <stdio.h>
#include <stdlib.h>

Pokemon * newPokemon(char *name, int hpMax, int attack, int defense, int speed, char *type){
    Pokemon * p = malloc(sizeof(Pokemon));
    p->name = malloc(sizeof(char) * 50) ;
    p->name = name;
    p->hp = hpMax;
    p->hpMax = hpMax;
    p->attack = attack;
    p->defense = defense;
    p->speed = speed;
    p->type = malloc(sizeof(char) * 50) ;
    p->type = type;
    return p;
};
