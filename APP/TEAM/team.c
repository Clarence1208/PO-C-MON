#include "team.h"
#include "stdlib.h"

Team * initTeam(Pokemon * starter){
    Team * myTeam = malloc(sizeof(Team));
    short max;
    short currentNb;
    Pokemon ** pokemons;
    short alivePokemons;

    myTeam->max = 6;
    myTeam->currentNb = 1;
    myTeam->alivePokemons = 1;
    myTeam->pokemons = malloc(sizeof(Pokemon *));
    myTeam->pokemons[0] = starter;

    return myTeam;
}
void addToTeam(Team *myTeam, Pokemon * newPokemon){
    myTeam->pokemons[myTeam->currentNb] = newPokemon;
    myTeam->currentNb += 1;
    myTeam->alivePokemons += 1;
}

void removeFromTeam(Team * myteam, Pokemon *pokeToRemove){
//    pokemons = myTeam->pokemons;
//    for (int i = 0; i < myTeam->currentNb; ++i) {
//
    }
    
    
    myTeam->currentNb -= 1;
    myTeam->alivePokemons -= 1;
}
