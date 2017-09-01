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
  std::string name;
  std::string surname;
  std::string age;
  std::string message;

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
  /* STRFTIME('%s','now') - Unix timestamp
        DATETIME(STRFTIME('%s','now')) = DATETIME('now') but we can operate with
        the timestamp
  */
  std::cout << "Inserte los datos:" << "\n";
  printf("Inserta los datos\n");

  std::cout << "Name: " << "\n";
  std::cin >> name;
  std::cout << "Surname: " << std::endl;
  std::cin >> surname;
  std::cout << "Age: " << std::endl;
  std::cin >> age;
  std::cout << "Message: " << std::endl;
  std::cin >> message;

  query = "insert into register2 (name, surname,age,message)values("
  "'" + name + "'" + "," +
  "'" + surname + "'" + "," + 
  "'" + age + "'" + "," +
  "'" + message + "'"
  ");"
  ;

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
    fprintf(stdout, "Insercion correcta!\n");
  }

  sqlite3_close(db);

  return 0;
}