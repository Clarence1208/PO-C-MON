#ifndef PO_C_MON_DATABASE_H
#define PO_C_MON_DATABASE_H

#endif //PO_C_MON_DATABASE_H

void createDatabase(sqlite3 *db, char *sql, char *zErrMsg, int rc);
Team * getTeamFromDB();

