#ifndef PO_C_MON_TEAM_H
#define PO_C_MON_TEAM_H
#include "../POKEMON/pokemon.h"

typedef struct Team{
    short max;
    short currentNb;
    Pokemon ** pokemons;
    short alivePokemons;
} Team;

Team * initTeam(Pokemon *starter);
void printTeam(Team *team);
void addToTeam(Team *myTeam, Pokemon *newPokemon);
int removeFromTeam(Team * myteam);

#endif //PO_C_MON_TEAM_H
