#include "print.h"
#include "../TEAM/team.h"
#include "../PLAYER/player.h"
#include <stdio.h>
#include <stdlib.h>

void welcomeToPoCmon(){
    printf("                        ##########################\n");
    printf("                        ##       Po-C-mon       ##\n");
    printf("                        ##########################\n\n\n");
}

Player * firstGame(){

    char starter ;
    Team * myTeam;
    char * name;
    int done= 0;

    Pokemon ** starters = malloc(sizeof(Pokemon *));

    starters[0] =  newPokemon("Bulbizarre", 90,49, 24, 45,0, "Plante");
    starters[1] = newPokemon("Salamèche", 78,52, 21, 65,0, "Feu");
    starters[2] = newPokemon("Carapuce", 88,48, 32, 43,0, "Eau");

    printf(">>??? : ...\n");
    printf(">>??? :........\n");
    printf(">>??? : OH !\n");
    printf(">>??? : Welcome ! I see you are new here !\n");
    printf(">>Pr Shen : What's your name ?\n");
    name = getName();
    printf(">>Pr Shen : Nice to meet you, %s. I am Pr Shen and I have a mission for you.\n", name);
    printf(">>Pr Shen : I\'d like you to explore the world of Unys and catch all the Pokemon you see.\n");
    printf(">>Pr Shen : I already know you are gonna accept your mission.\n");
    printf(">>Pr Shen : To get started, why don\'t you choose one of three specimens i have here ?\n");


    do {
        printf("1 : Bulbizarre ");
        printf("2 : Salamèche ");
        printf("3 : Carapuce\n");

        scanf("%c", &starter);

        switch (starter) {
            case '1':
                //add the pokemon to your team
                myTeam = initTeam(starters[0]);
                done = 1;
                break;
            case '2':
                myTeam = initTeam(starters[1]);
                done = 1;
                break;
            case '3':
                myTeam = initTeam(starters[2]);
                done = 1;
                break;
            default:
                printf("You can only choose 1, 2, 3\n");
                break;
        }

    } while (starter != '1' && starter != '2' && starter != '3');

    if(myTeam != NULL){
        printf("%s has been added to your team !\n", myTeam->pokemons[0]->name);
        Player * player = newPlayer(name, myTeam);
        return player;
    }else{
      return NULL;
    }
}