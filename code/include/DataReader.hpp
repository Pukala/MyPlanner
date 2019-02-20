#pragma once
#include <vector>
#include <string>
#include <sqlite3.h>

class DataReader
{
public:
  DataReader(sqlite3 *db) : db(db)
  {
    myEvents.reserve(10);
  }

  const std::vector<std::string> &getMyEvents()
  {
    return myEvents;
  }

  void takeDataFromDatabase();

private:
  sqlite3 *db;
  std::vector<std::string> myEvents{};
};