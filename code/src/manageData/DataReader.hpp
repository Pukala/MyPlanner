#pragma once
#include <vector>
#include "DbParameters.hpp"
#include "Event.hpp"

class DataReader
{
public:
  DataReader(sqlite3 *db) : dbParameters(db)
  {
    myEvents.reserve(10);
  }

  std::vector<Event> getDataFromDatabase();

private:
  std::vector<Event> myEvents{};
  DbParameters dbParameters{};
};