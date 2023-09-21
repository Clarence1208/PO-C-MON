#include "team.h"
#include "stdlib.h"

Team * initTeam(Pokemon * starter){
    Team * myTeam = malloc(sizeof(Team));
    short max;
    short currentNb;
    Pokemon * pokemons;
    short alivePokemons;

    myTeam->max = 6;
    myTeam->currentNb = 1;
    myTeam->alivePokemons = 1;
    myTeam->pokemons = malloc(sizeof(Pokemon *));
    myTeam->pokemons[0] = starter;

    return myTeam;
}
void addToTeam(Team *myTeam, Pokemon * newPokemon);
