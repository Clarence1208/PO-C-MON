#include "team.h"
#include "stdlib.h"
#include "stdio.h"

Team * initTeam(Pokemon * starter){
    Team * myTeam = malloc(sizeof(Team));
    short max;
    short currentNb;
    Pokemon ** pokemons;
    short alivePokemons;

    myTeam->max = 6;
    myTeam->currentNb = 1;
    myTeam->alivePokemons = 1;
    myTeam->pokemons = malloc(sizeof(Pokemon *) * 6);
    myTeam->pokemons[0] = starter;

    return myTeam;
}

void printTeam(Team *team){
    for (int i = 0; i < team->currentNb; i++) {
        printPokemon(team->pokemons[i]);
    }
}
void addToTeam(Team *myTeam, Pokemon * newPokemon){
    int index = -1;

    if (myTeam->currentNb + 1 > myTeam->max){
        index = removeFromTeam(myTeam);
    }
    if(index != -1){
        myTeam->pokemons[index] = newPokemon;
    }else{
        myTeam->pokemons[myTeam->currentNb] = newPokemon;
    }

    myTeam->currentNb += 1;
    myTeam->alivePokemons += 1;

    printf("%s has been added to the team !\n", newPokemon->name);
}

int removeFromTeam(Team * myteam){
    int index = -1;
    char choice;
    printf("Oh-ho ! You already have %d pokemons in your team. Which one should you replace with this new one ?", myteam->max);

    do {
        for (int i = 0; i < myteam->currentNb; ++i) {
            printf("%d : %s\n", i, myteam->pokemons[i]->name);
        }
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                index = 1;
                break;
            case '2':
                index = 2;
                break;
            case '3':
                index = 3;
                break;
            case '4':
                index = 4;
                break;
            case '0':
                index = 3;
                break;
            case '5':
                index = 3;
                break;
            default:
                printf("You can only choose the digits above.\n");
                break;
        }
    } while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '0' && index <= myteam->currentNb);

    if (index != -1){
        printf("...%s has been removed from your team !\n", myteam->pokemons[index]->name);
        free(myteam->pokemons[index]);
        myteam->currentNb -= 1;
        myteam->alivePokemons -= 1;

        return index; //add new pokemon in add fonction at index returned here
    }
    return -1;
}
