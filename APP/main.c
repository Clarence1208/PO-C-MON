#include <stdio.h>
#include <stdlib.h>
#include "PRINTS/print.h"
#include "POKEMON/pokemon.h"
#include "POKEDEX/pokedex.h"

int main(int argc, char ** argv) {
    //Get data from the saved file.
    int isFirstGame = 1; //testing
    welcomeToPoCmon();
    if (isFirstGame == 1) {
        //start the game
        firstGame();
    }

    Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, "Electric");

    Pokedex *pokedex = newPokedexFromCsv("FILES/pokedex.csv");
    return 0;
}