#include "database.h"
#include <stdlib.h>
#include <stdio.h>
#include "string.h"


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

//void createDatabase(sqlite3 *db, char *sql, char *zErrMsg, int rc)
//{
//    rc = sqlite3_open("DATABASE/poCmon.db", &db);
//
//    if( rc )
//    {
//        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//        exit(0);
//    } else
//    {
//        printf("OK\n");
//    }
//}
void createTableTeams(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{
    sql = "CREATE TABLE IF NOT EXISTS TEAMS("  \
            "ID                INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
            "FIRST_POKEMON  VARCHAR(30) NOT NULL,"\
            "SECOND_POKEMON  VARCHAR(30) ,"\
            "THIRD_POKEMON  VARCHAR(30) ,"\
            "FOURTH_POKEMON  VARCHAR(30) ,"\
            "FIFTH_POKEMON  VARCHAR(30) ,"\
            "SIXTH_POKEMON  VARCHAR(30) ,"\
            "PLAYER_ID       INTEGER NOT NULL,"\
            "FOREIGN KEY (PLAYER_ID) REFERENCES PLAYERS (ID));";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if( rc != SQLITE_OK )
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
}

//int saveTeamToDatabase(Team *team){
//
//char successfullySaved[] = "\nYour team has been saved into the database.\n\n";
//
//sqlite3 *db;
//char *err_msg = 0;
//sqlite3_stmt *res;
//
//int rc = sqlite3_open("DATABASE/pocmon.db", &db);
//
//if (rc != SQLITE_OK) {
//fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
//sqlite3_close(db);
//return 1;
//}
//
//char *sql = "INSERT INTO TEAMS(VALUE, COMMENT, PLAYER_ID) VALUES (:value, :comment, :player_id)";
////we are not using the _v3 version cuz we don't need the special prepflags argumentw
//rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);
//
////Replacing the named parameters with the value we want
//if (rc == SQLITE_OK) {
//int parameter = sqlite3_bind_parameter_index(res, ":value");
//sqlite3_bind_double(res, parameter, glycemia->value);
//
//parameter =  sqlite3_bind_parameter_index(res, ":comment");
//sqlite3_bind_text(res, parameter, glycemia->comment, strlen(glycemia->comment), NULL);
//
//parameter =  sqlite3_bind_parameter_index(res, ":user_id");
//sqlite3_bind_int(res, parameter, glycemia->user_id);
//
//} else {
////Error handling
//fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
//}
//
//rc = sqlite3_step(res);
//
////Error handling
//if (rc != SQLITE_DONE) {
//printf("execution failed: %s", sqlite3_errmsg(db));
//}
//
////Finishes the request, returns SQLITE_OK if all good if we don't do it can lead to segfaults
//sqlite3_finalize(res);
//
//printf("%s", successfullySaved);
//}
int getFirstGame(){

    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    sqlite3_stmt *res;

    int value;

    rc = sqlite3_open("DATABASE/pocmon.db", &db);

    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
    }


    char *sql = "SELECT FIRST_GAME FROM PLAYERS WHERE ID = 1";
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

    if (sqlite3_step(res) != SQLITE_ROW){
        return 1;
    }
    else
    {
        value =  sqlite3_column_int(res, 1);
    }

    sqlite3_finalize(res);
    return value;

}

int savePlayer(Player *player){

    int parameter;
    sqlite3 *db;
    char *err_msg = 0;
    sqlite3_stmt *res;

int rc = sqlite3_open("DATABASE/pocmon.db", &db);

if (rc != SQLITE_OK) {
fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
sqlite3_close(db);
return 1;
}

char *sql = "INSERT INTO PLAYERS(NAME, FIRST_GAME) VALUES (:name, :first_game)";
//we are not using the _v3 version cuz we don't need the special prepflags argumentw
rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);

//Replacing the named parameters with the value we want
if (rc == SQLITE_OK) {
    parameter =  sqlite3_bind_parameter_index(res, ":name");
    sqlite3_bind_text(res, parameter, player->name, strlen(player->name), NULL);

    parameter =  sqlite3_bind_parameter_index(res, ":first_game");
    sqlite3_bind_int(res, parameter, 0);

} else {
//Error handling
fprintf(stderr, "Failed to execute statement: %s\n", sqlite3_errmsg(db));
}

rc = sqlite3_step(res);

//Error handling
if (rc != SQLITE_DONE) {
printf("execution failed: %s", sqlite3_errmsg(db));
}

//Finishes the request, returns SQLITE_OK if all good if we don't do it can lead to segfaults
sqlite3_finalize(res);

    return 0;
}
void createTablePlayers(sqlite3 *db, char *sql, char *zErrMsg, int rc)
{

    sql = "CREATE TABLE IF NOT EXISTS PLAYERS (" \
      "ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL," \
      "NAME VARCHAR(30) NOT NULL," \
      "FIRST_GAME INTEGER DEFAULT 0" \
      ");";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);

    if (db == NULL) {
        fprintf(stderr, "Database connection is not open.\n");
        // Handle the error or return as appropriate.
    }
    if( rc != SQLITE_OK )
    {
        printf("%d\n",rc);
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
