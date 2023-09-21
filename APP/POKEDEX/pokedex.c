#include "pokedex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Pokedex * newPokedexFromCsv(char *filename){
    Pokedex * pokedex = malloc(sizeof(Pokedex));
    pokedex->pokemons = malloc(sizeof(Pokemon) * 11);

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error while opening the file.\n");
        exit(1);
    }

    char *name = malloc(sizeof(char) * 50);
    int hpMax;
    int attack;
    int defense;
    int speed;
    int isSeen = 0;
    char *type = malloc(sizeof(char) * 50);

    char buffer[500];

    char line[500];
    //skip first line
    fgets(buffer, 500, file);

    int i = 0;



    while (fgets(line, sizeof(line), file)) {

        sscanf(line, "%49[^;];%d;%d;%d;%d;%19[^\n]", name, &hpMax, &attack, &defense, &speed, type);

        //add \0 at the end of the string
        name[strlen(name)] = '\0';
        type[strlen(type)] = '\0';

        pokedex->pokemons[pokedex->nbPokemons] = newPokemon(name, hpMax, attack, defense, speed, isSeen, type);
        pokedex->nbPokemons++;
    }



    free(name);
    free(type);





    fclose(file);

    return pokedex;

}

void printPokedex(Pokedex *pokedex){
    for (int i = 0; i < pokedex->nbPokemons; i++) {
        printPokemon(pokedex->pokemons[i]);
    }
}