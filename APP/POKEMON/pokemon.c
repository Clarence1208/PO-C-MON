// define only if not already defined
#include "pokemon.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Pokemon * newPokemon(char *name, int hpMax, int attack, int defense, int speed, int isSeen, char *type){
    Pokemon * p = malloc(sizeof(Pokemon));
    p->name = malloc(sizeof(char) * 50) ;
    strcpy(p->name, name);
    p->hp = hpMax;
    p->hpMax = hpMax;
    p->attack = attack;
    p->defense = defense;
    p->speed = speed;
    p->isSeen = isSeen;
    p->type = malloc(sizeof(char) * 50) ;
    strcpy(p->type, type);
    return p;
}

void printPokemon(Pokemon *p){
    printf("Name: %s\n", p->name);
    printf("HP: %d/%d\n", p->hp, p->hpMax);
    printf("Attack: %d\n", p->attack);
    printf("Defense: %d\n", p->defense);
    printf("Speed: %d\n", p->speed);
    printf("Type: %s\n", p->type);
}