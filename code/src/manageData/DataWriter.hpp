#pragma once
#include "Event.hpp"
#include "DbParameters.hpp"

class DataWriter
{
public:
  DataWriter(sqlite3 *db) : dbParameters(db)
  {
  }

  void createTable(const std::string &nameOfTable_);
  void insertData(const Event &event);

private:
  void checkResult(const std::string &name);

  DbParameters dbParameters{};
  std::string nameOfTable{};
};