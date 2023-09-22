#include "POKEMON/pokemon.h"
#include "POKEDEX/pokedex.h"
#include "PLAYER/player.h"
#include "PRINTS/print.h"
#include "DATABASE/database.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char ** argv) {

    int isFirstGame = 1; //testing
    Player * player;

    welcomeToPoCmon();

    if (isFirstGame == 1) {
        //start the game
        player = firstGame();
        if (player == NULL){
            printf("ERROR");
            return 0;
        }
    } else{
        //TODO: Get data from the saved file.
    }
    //printTeam(player->team);
    Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, 0, "Electric");
    //printPokemon(p);
    addToTeam(player->team, p);
//
//    Pokedex *pokedex = newPokedexFromCsv("FILES/pokedex.csv");
//
//    printPokedex(pokedex);

    return 0;
}