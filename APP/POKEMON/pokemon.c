// define only if not already defined
#include "pokemon.h"
#include <stdlib.h>

Pokemon * newPokemon(char *name, int hpMax, int attack, int defense, int speed, int isSeen, char *type){
    Pokemon * p = malloc(sizeof(Pokemon));
    p->name = malloc(sizeof(char) * 50) ;
    p->name = name;
    p->hp = hpMax;
    p->hpMax = hpMax;
    p->attack = attack;
    p->defense = defense;
    p->speed = speed;
    p->isSeen = isSeen;
    p->type = malloc(sizeof(char) * 50) ;
    p->type = type;
    return p;
}