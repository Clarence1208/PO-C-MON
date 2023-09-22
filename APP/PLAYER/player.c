#include <stdlib.h>
#include <stdio.h>
#include "string.h"
#include "player.h"

Player * newPlayer(char * name, Team *myTeam){
    Player *player = malloc(sizeof(Player*));
    player->name = malloc(strlen(name));
    strcpy(player->name, name);
    player->team = malloc(sizeof(Team*));
    player->team = myTeam;
    player->positionX = 0;
    player->positionY = 0;
}

char * getName(){
    char * name = malloc(0);
    int size = 0;
    char c;
    while ((c=fgetc(stdin)) != '\n'){
        name = realloc(name, size+1);
        name[size] = c;
        size++;
    }
    name = realloc(name, size+1);
    name[size+1] = '\0';

    return name;
}
