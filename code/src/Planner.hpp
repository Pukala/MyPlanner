#pragma once
#include <vector>

#include "manageData/DataWriter.hpp"
#include "manageData/DataReader.hpp"
#include "manageData/DbInfo.hpp"

class Planner
{
public:
  Planner(DbInfo &dbInfo) : dataWriter(dbInfo), dataReader(dbInfo.db), dbInfo(dbInfo)
  {
    if (dbInfo.isOpenedExistDb and dbInfo.isEmpty == false)
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

  void menu();

private:
  DataWriter dataWriter;
  DataReader dataReader;
  DbInfo dbInfo{};
  uint16_t lastElementId{};
};