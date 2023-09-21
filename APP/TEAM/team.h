#ifndef PO_C_MON_TEAM_H
#define PO_C_MON_TEAM_H

typedef struc Team{
    short max;
    short currentNb;
    Pokemon * pokemons;
    short alivePokemons;
} Team;

Team initTeam();
void addToTeam(Team myTeam, Pokemon newPokemon);

#endif //PO_C_MON_TEAM_H
