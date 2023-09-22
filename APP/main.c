#include "POKEMON/pokemon.h"
#include "POKEDEX/pokedex.h"
#include "PLAYER/player.h"
#include "PRINTS/print.h"
#include "DATABASE/database.h"
#include "stdio.h"
#include "stdlib.h"
#include "sqlite3.h"

int main(int argc, char ** argv) {

    int isFirstGame = 1; //testing
    Player * player;

    //DB VARIABLES
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc =  sqlite3_open("DATABASE/pocmon.db", &db);;
    char *sql;

    createTablePlayers(db, sql, zErrMsg, rc);
    createTableTeams(db, sql, zErrMsg, rc);
    isFirstGame = getFirstGame();

    welcomeToPoCmon();

    if (isFirstGame == 1) {
        //start the game
        player = firstGame();
        if (player == NULL){
            printf("ERROR");
            return 0;
        }
    } else{
        printf("You already played.\n");
    }

    savePlayer(player);

    //printTablePlayers(db, sql, zErrMsg, rc);
    sqlite3_close(db);
    if (player != NULL){
        free(player->team);
        free(player);
    }
//    printTeam(player->team);
//    Pokemon *p = newPokemon("Pikachu", 100, 100, 100, 100, 0, "Electric");
//    printPokemon(p);
//    addToTeam(player->team, p);
//
//    Pokedex *pokedex = newPokedexFromCsv("FILES/pokedex.csv");
//
//    printPokedex(pokedex);

    return 0;
}