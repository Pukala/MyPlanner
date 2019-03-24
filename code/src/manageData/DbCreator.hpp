#pragma once
#include <string>
#include <sqlite3.h>
#include <vector>

#include "DbInfo.hpp"

class DbCreator
{
public:
  DbCreator(const std::string &nameOfDatabase);
  DbCreator() = default;
  ~DbCreator();

  DbInfo &getdbInfoemation() { return dbInfo; }
  static void showDatabases();
  static std::vector<std::string> getNamesDatabases();
  void setNameOfDatabase(const std::string &name);

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