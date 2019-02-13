#pragma once
#include <sqlite3.h> 
#include <iostream>
#include <experimental/filesystem>
#include <string>

class DbCreator
{
public:
    DbCreator(const std::string& name); 
    ~DbCreator();

private:
    bool isDatabaseExist() const;
    bool isOpenedSuccessfully();

    void openTheExistingDatabase();
    void createNewDatabase();

    std::string name;
    sqlite3 *db;
};