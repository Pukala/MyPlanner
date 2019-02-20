#pragma once
#include <vector>
#include "DataWriter.hpp"
#include "DataReader.hpp"

#include <iostream>

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

    void insertData(const Event &event)
    {
        dataWriter.insertData(event);
    }

    const auto &getMyEvents()
    {
        return dataReader.getMyEvents();
    }

    void updateData()
    {
        dataReader.takeDataFromDatabase();
    }

  private:
    DataWriter dataWriter;
    DataReader dataReader;
};