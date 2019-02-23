#pragma once
#include <vector>

#include "manageData/DataWriter.hpp"
#include "manageData/DataReader.hpp"
#include "manageData/DbInfo.hpp"

class Planner
{
public:
  Planner(DbInfo &dbInfo) : dbInfo(dbInfo), dataWriter(dbInfo), dataReader(dbInfo.db)
  {
    if (dbInfo.isOpenedExistDb)
    {
      lastElementId = dataReader.getDataFromDatabase().size();
    }
  }

  void createTable()
  {
    dataWriter.createTable();
  }

  void insertData(Event event)
  {
    dataWriter.insertData(event, lastElementId);
  }

  Event takeElementById(const int id)
  {
    return dataReader.takeElementById(id);
  }

  const std::vector<Event> getDataFromDatabase()
  {
    return dataReader.getDataFromDatabase();
  }

private:
  DataWriter dataWriter;
  DataReader dataReader;
  DbInfo dbInfo{};
  uint16_t lastElementId{};
};