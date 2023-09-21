#include "pokedex.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Pokedex * newPokedexFromCsv(char *filename){
    Pokedex * pokedex = malloc(sizeof(Pokedex));

    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error while opening the file.\n");
        exit(1);
    }

    char buffer[500];

    int i = 0;
    while (fgets(buffer, 500, file)) {
        char *name = malloc(sizeof(char) * 50);
        int hpMax;
        int attack;
        int defense;
        int speed;
        int isSeen = 0;
        char *type = malloc(sizeof(char) * 50);

        char *token = strtok(buffer, ";");
        while (token != NULL) {
            if (i == 0) {
                name = token;
            } else if (i == 1) {
                hpMax = atoi(token);
            } else if (i == 2) {
                attack = atoi(token);
            } else if (i == 3) {
                defense = atoi(token);
            } else if (i == 4) {
                speed = atoi(token);
            } else if (i == 5) {
                type = token;
            }
            token = strtok(NULL, ";");
            i++;
        }
        i = 0;
        pokedex->pokemons[pokedex->nbPokemons] = newPokemon(name, hpMax, attack, defense, speed, isSeen, type);
        pokedex->nbPokemons++;
    }

}