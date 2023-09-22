#ifndef PO_C_MON_DATABASE_H
#define PO_C_MON_DATABASE_H
#include "../sqlite3.h"
#include "../TEAM/team.h"
#include "../PLAYER/player.h"
//void createDatabase(sqlite3 *db, char *sql, char *zErrMsg, int rc);
void createTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc);
void printTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc);
void createTableTeams(sqlite3 *db, char *sql, char *zErrMsg, int rc);
Team * getTeamFromDB();
int savePlayer(Player *player);
int getFirstGame();


#endif //PO_C_MON_DATABASE_H
