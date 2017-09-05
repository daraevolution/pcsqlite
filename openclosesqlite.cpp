#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sqlite/sqlite3.h"

int main(int argc, char* argv[])
{
    sqlite3 *db;
    int res;
    std::string dbname;

    std::cout << "Introduce el nombre de la db" << "\n";
    std::cin >> dbname;
    dbname.append(".db");

    std::cout << "Se creara la siguiente base de datos: " << dbname << "\n";
    const char *db_name = dbname.c_str();
    /* Open database */
    res = sqlite3_open(db_name , &db);
    if (res)
    {
        fprintf(stderr, "No puedo abrir la base de datos: %s\n", sqlite3_errmsg(db));
        std::cout << "No puedo abrir la base de datos:" << sqlite3_errmsg(db) << '\n';
        exit(0);
    }
    else
    {
        fprintf(stderr, "Base de datos OK\n");
        std::cout << "Base de datos OK" << '\n';
    }

    sqlite3_close(db);

    return 0;
}