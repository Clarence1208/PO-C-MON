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
    if (myTeam->currentNb + 1 > myTeam->max){
        removeFromTeam(Team *myteam);
    }
    myTeam->pokemons[myTeam->currentNb] = newPokemon;
    myTeam->currentNb += 1;
    myTeam->alivePokemons += 1;
}

void removeFromTeam(Team * myteam){
    Pokemon * pokemons = myteam->pokemons;
    printf("Oh-ho ! You already have %d pokemons in your team. Which one should you replace with this new one ?", myteam->max);
    for (int i = 0; i < myteam->currentNb; ++i) {
        printf("d : %s\n", i, myteam->pokemons[i]->name);
    }
    scanf("%c", &choice);

    switch (expression) {
        
    }
    
    
    myTeam->currentNb -= 1;
    myTeam->alivePokemons -= 1;*/
}
