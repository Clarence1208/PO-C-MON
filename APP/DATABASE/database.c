#include "database.h"
#include <stdlib.h>
#include <stdio.h>

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
void createTableUsers(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    sql = "CREATE TABLE IF NOT EXISTS USERS("  \
            "ID                INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
            "USERNAME          VARCHAR(30)    NOT NULL," \
            "AGE               INTEGER     NOT NULL," \
            "PASSWORD          VARCHAR(30)," \
            "TARGETED_GLYCEMIA FLOAT     NOT NULL," \
            "HYPERGLYCEMIA     INTEGER     NOT NULL," \
            "HYPOGLYCEMIA      INTEGER     NOT NULL," \
            "CREATED_AT        DATETIME);";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

void printTableUsers(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    sql = "SELECT * FROM USERS";

    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}
