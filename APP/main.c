#include <stdio.h>
#include <stdlib.h>
#include "PRINTS/print.h"
#include "POKEMON/pokemon.h"
#include "POKEDEX/pokedex.h"

int main(int argc, char ** argv) {

    int isFirstGame = 1; //testing
    Player * player;

    welcomeToPoCmon();

    if (isFirstGame == 1) {
        //start the game
        //player = firstGame(); WIP LORIANE
        if (player == NULL){
            printf("ERROR");
            return 0;
        }
    } else{
        //TODO: Get data from the saved file.
    }

//Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, "Electric");

//    Pokedex *pokedex = newPokedexFromCsv("FILES/pokedex.csv");
    return 0;
}