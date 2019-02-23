#pragma once
#include <vector>

#include "DbParameters.hpp"
#include "Event.hpp"

class DataReader
{
public:
  DataReader(sqlite3 *db) : dbParameters(db)
  {
  }

  std::vector<Event> getDataFromDatabase();

  Event takeElementById(const int id);

private:
  DbParameters dbParameters{};
};