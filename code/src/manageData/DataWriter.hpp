#pragma once
#include "Event.hpp"
#include "DbParameters.hpp"
#include "DbInfo.hpp"

class DataWriter
{
public:
  DataWriter(DbInfo &dbInfo) : dbParameters(dbInfo.db), dbInfo(dbInfo)
  {
  }

  void createTable();
  void insertData(const Event &event, uint16_t &lastElementId);

private:
  void checkResult();

  DbParameters dbParameters{};
  DbInfo &dbInfo;
};