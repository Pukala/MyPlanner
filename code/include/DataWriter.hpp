#pragma once
#include "Event.hpp"
#include <sqlite3.h>
#include <string>

class DataWriter
{
public:
  DataWriter(sqlite3 *db) : db(db)
  {
  }

  void createTable(const std::string &nameOfTable_);
  void insertData(const Event &event);

private:
  void checkResult(const std::string &name);

  sqlite3 *db;
  char *zErrMsg{nullptr};
  std::string sqlCommand{};
  std::string nameOfTable{};
};