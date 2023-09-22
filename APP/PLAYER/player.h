#include "../TEAM/team.h"
#ifndef PO_C_MON_PLAYER_H
#define PO_C_MON_PLAYER_H

typedef struct Player{
    char * name;
    Team * team;
    int x;
    int y;
} Player;

Player * newPlayer(char * name, Team *myTeam);
char * getName();
#endif //PO_C_MON_PLAYER_H
