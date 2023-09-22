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
    Pokedex * pokedex;

    welcomeToPoCmon();

    if (isFirstGame == 1) {
        //start the game
        player = firstGame();
        pokedex = newPokedexFromCsv("FILES/pokedex.csv", player);
        if (player == NULL){
            printf("ERROR");
            return 0;
        }
        //launchBattle(player, pokedex);

    } else{
        //TODO: Get data from the saved file.
    }

    createMap(player, pokedex);
    free(player);
    free(pokedex);

   /* Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, 0, "Electric");
    printPokemon(p);

    printPokedex(pokedex);*/

    return 0;
}