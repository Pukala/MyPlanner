#pragma once
#include <sqlite3.h>
#include <string>
#include "../include/Event.hpp"

#include <vector> // to delete

class DbCreator
{
public:
  DbCreator(const std::string &nameOfDatabase);
  ~DbCreator();

  void createTable(const std::string &nameOfTable_);
  void insertData(const Event &event);
  void takeDataFromDatabase();

  sqlite3 *getSqlite3() { return db; }

private:
  bool isDatabaseExist() const;
  bool isOpenedSuccessfully();

  void openTheExistingDatabase();
  void createNewDatabase();

  void checkResult(const std::string &name);

  std::string nameOfDatabase{};
  std::string nameOfTable{};

  sqlite3 *db;
  char *zErrMsg{nullptr};
  std::string sqlCommand{};
};