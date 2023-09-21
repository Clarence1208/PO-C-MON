#include "print.h"
#include "pokemon.h"
#include <stdio.h>
#include <stdlib.h>

void welcomeToPoCmon(){
    printf("                        ##########################\n");
    printf("                        ##       Po-C-mon       ##\n");
    printf("                        ##########################\n\n\n");
}

void firstGame(){

    char starter ;

    Pokemon * starters = malloc(sizeof(Pokemon));
    newPokemon("Carapuce", int hpMax, int attack, int defense, int speed,  char*type);

    printf(">>???: ...\n");
    printf("........\n");
    printf(">>???: OH !\n");
    printf(">>???: Welcome ! I see you are new here !\n");
    printf(">>???: I am Pr Shen and I have a mission for you.\n");
    printf(">>Pr Shen : I\'d like you to explore the world of Unys and catch all the Pokemon you see.\n");
    printf(">>Pr Shen : I already know you are gonna accept your mission.\n");
    printf(">>Pr Shen : To get started, why don\'t you choose one of three specimens i have here ?\n");


    do {
        printf("1 : Bulbizarre ");
        printf("2 : Salamèche ");
        printf("3 : Carapuce ");

        scanf("%c ", &starter);

        switch (starter) {
            case '1':
                //add the pokemon to your team

                break;
            case '2':
                break;
            case '3':
                break;
            default:
                printf("You can only choose 1, 2, 3\n");
                break;
        }

    } while (starter != '1' && starter != '2' && starter != '3');


}