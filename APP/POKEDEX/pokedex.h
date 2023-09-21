#include "../POKEMON/pokemon.h"

#ifndef POKEDEX_H
#define POKEDEX_H

// struct of the pokédex who will regroup all available pokemons
typedef struct pokedex {
    Pokemon **pokemons;
    int nbPokemons;
} Pokedex;

Pokedex * newPokedexFromCsv(char *filename);

Pokedex * newPokedexFromDB();

void printPokedex(Pokedex *pokedex);

#endif