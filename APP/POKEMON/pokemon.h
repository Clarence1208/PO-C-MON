#ifndef POKEMON_H
#define POKEMON_H

// struct of a pokémon
typedef struct {
    char *name;
    int hp;
    int hpMax;
    int attack;
    int defense;
    int speed;
    int isSeen;
    char *type;
} Pokemon;

Pokemon * newPokemon(char *name, int hpMax, int attack, int defense, int speed, int isSeen, char*type);

void printPokemon(Pokemon *p);

#endif