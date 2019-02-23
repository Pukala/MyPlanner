#pragma once
#include <string>
#include <sqlite3.h>

#include "DbInfo.hpp"

class DbCreator
{
public:
  DbCreator(const std::string &nameOfDatabase);
  ~DbCreator();

  DbInfo &getdbInfoemation() { return dbInfo; }

private:
  bool isDatabaseExist() const;
  bool isOpenedSuccessfully();

  void openTheExistingDatabase();
  void createNewDatabase();

  void checkResult(const std::string &name);

  std::string nameOfDatabase{};
  DbInfo dbInfo{};
  char *zErrMsg{nullptr};
};