#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "sqlite/sqlite3.h"

int main(int argc, char* argv[])
{
    printf ("SQLITE LIB Version: %s\n", sqlite3_libversion());
    printf ("SQLITE LIB Version (int): %d\n", sqlite3_libversion_number());

    if (sqlite3_libversion_number()<3001008)
    {
        printf ("Lo siento, tu versión de SQLite es muy antigua\n");
        std::cout << "Lo siento, tu versión de SQLite es muy antigua" << '\n';
    }
    else
    {
        printf("Felicitaciones! Tu version es actualizada\n");
        std::cout << "Felicitaciones! Tu version es actualizada" << '\n';
    }

    return 0;
}