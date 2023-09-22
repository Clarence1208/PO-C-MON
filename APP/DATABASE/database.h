#ifndef PO_C_MON_DATABASE_H
#define PO_C_MON_DATABASE_H
#include "../sqlite3.h"
#include "../TEAM/team.h"
void createDatabase(sqlite3 *db, char *sql, char *zErrMsg, int rc);
void createTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc);
void printTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc);

Team * getTeamFromDB();


#endif //PO_C_MON_DATABASE_H
