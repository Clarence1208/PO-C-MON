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

    printPokemon(p);

    Pokedex *pokedex = newPokedexFromCsv("FILES/pokedex.csv");

    printPokedex(pokedex);

    return 0;
}