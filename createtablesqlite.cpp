#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sqlite/sqlite3.h"

int main(int argc, char* argv[])
{
   sqlite3 *db;
   char *error = 0;
   int result;
   std::string query;


   /* Open database */
   result = sqlite3_open("test.db", &db);
   if (result)
     {
       fprintf(stderr, "No puedo abrir la base de datos: %s\n", sqlite3_errmsg(db));
       exit(0);
     }
   else
     {
       fprintf(stderr, "Base de datos OK\n");
     }

    /* Create SQL statement */
    query = "CREATE TABLE register2 ("
     "`name` TEXT, "
     "`surname` TEXT, "
     "`age` NUMBER, "
     "`message` TEXT)";
     
     /*
     Convert string to char pointer.
     Because the function sqlite3_exec just accept char pointer
     */
    const char *sql = query.c_str();

   /* Execute SQL statement */
   result = sqlite3_exec(db, sql, NULL, 0, &error);
    if (result != SQLITE_OK)
     {
       fprintf(stderr, "Error: %s\n", error);
       sqlite3_free(error);
     }
    else
     {
       fprintf(stdout, "Tabla creada!\n");
     }

   sqlite3_close(db);

   return 0;
}