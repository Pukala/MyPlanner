#pragma once
#include <string>
#include <sqlite3.h>

class DbCreator
{
public:
  DbCreator(const std::string &nameOfDatabase);
  ~DbCreator();

  sqlite3 *getSqlite3() { return db; }

private:
  bool isDatabaseExist() const;
  bool isOpenedSuccessfully();

  void openTheExistingDatabase();
  void createNewDatabase();

  void checkResult(const std::string &name);

  std::string nameOfDatabase{};

  sqlite3 *db;
  char *zErrMsg{nullptr};
};