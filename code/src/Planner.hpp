#pragma once
#include <vector>
#include "../manageData/DataWriter.hpp"
#include "../manageData/DataReader.hpp"

class Planner
{
public:
  Planner(sqlite3 *db) : dataWriter(db), dataReader(db)
  {
  }

  void createTable(const std::string &name)
  {
    dataWriter.createTable(name);
  }

  void insertData(Event event)
  {
    dataWriter.insertData(event);
  }

  const std::vector<Event> getDataFromDatabase()
  {
    return dataReader.getDataFromDatabase();
  }

private:
  DataWriter dataWriter;
  DataReader dataReader;
};