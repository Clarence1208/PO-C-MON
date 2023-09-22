#include "database.h"
#include <stdlib.h>
#include <stdio.h>

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    int i;
    for(i = 0; i<argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

void createDatabase(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    rc = sqlite3_open("DATABASE/poCmon.db", &db);

    if( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else
    {
        printf("\n");
    }
}
void createTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    sql = "CREATE TABLE IF NOT EXISTS PLAYERS("  \
            "ID                INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
            "NAME          VARCHAR(30)    NOT NULL,"\
            "FIRSTGAME      INTEGER DEFAULT 0"\
            "TEAM_ID        INTEGER NOT NULL"\
            "FOREIGN KEY (TEAM_ID) REFERENCES TEAM (ID));";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void printTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    sql = "SELECT * FROM PLAYERS";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}
