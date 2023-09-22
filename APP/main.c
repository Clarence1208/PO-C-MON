#include "POKEMON/pokemon.h"
#include "POKEDEX/pokedex.h"
#include "BATTLE/battle.h"
#include "MAP/map.h"
#include "PLAYER/player.h"
#include "PRINTS/print.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char ** argv) {

    int isFirstGame = 1; //testing
    Player * player;

    welcomeToPoCmon();

    if (isFirstGame == 1) {
        //start the game
        player = firstGame();
        Pokedex *pokedex = newPokedexFromCsv("FILES/pokedex.csv");
        if (player == NULL){
            printf("ERROR");
            return 0;
        }
        launchBattle(player, pokedex);
        free(player);
        free(pokedex);

        createMap(player);

    } else{
        //TODO: Get data from the saved file.
    }

   /* Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, 0, "Electric");
    printPokemon(p);

    printPokedex(pokedex);*/

    return 0;
}