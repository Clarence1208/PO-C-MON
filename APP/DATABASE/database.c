#include "database.h"

void createDatabase(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    rc = sqlite3_open("database/diabetic.db", &db);

    if( rc )
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    } else
    {
        printf("\n");
    }
}