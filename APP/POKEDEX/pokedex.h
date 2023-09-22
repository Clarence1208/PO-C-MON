#ifndef POKEDEX_H
#define POKEDEX_H

#include "../POKEMON/pokemon.h"
#include "../PLAYER/player.h"

// struct of the pokédex who will regroup all available pokemons
typedef struct pokedex {
    Pokemon **pokemons;
    int nbPokemons;
} Pokedex;

Pokedex * newPokedexFromCsv(char *filename, Player *player);

Pokedex * newPokedexFromDB();

void printPokedex(Pokedex *pokedex);

#endif