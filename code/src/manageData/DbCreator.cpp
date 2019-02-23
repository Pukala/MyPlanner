#include <iostream>
#include <experimental/filesystem>
#include <cstdlib>
#include <cassert>
#include "DbCreator.hpp"

DbCreator::DbCreator(const std::string &nameOfDatabase) : nameOfDatabase(nameOfDatabase + ".db")
{
    if (isDatabaseExist())
    {
        openTheExistingDatabase();
    }
    else
    {
        createNewDatabase();
    }
}

DbCreator::~DbCreator()
{
    std::cout << "I have closed Database\n";
    sqlite3_close(db);
    sqlite3_free(zErrMsg);
}

bool DbCreator::isDatabaseExist() const
{
    return std::experimental::filesystem::exists(nameOfDatabase);
}

bool DbCreator::isOpenedSuccessfully()
{
    return (not sqlite3_open(nameOfDatabase.c_str(), &db));
}

void DbCreator::openTheExistingDatabase()
{
    if (isOpenedSuccessfully())
    {
        std::cout << "I have opened existing Database\n";
    }
    else
    {
        std::cerr << "Can not open Database\n";
        assert(false);
    }
}

void DbCreator::createNewDatabase()
{
    if (isOpenedSuccessfully())
    {
        std::cout << "I have created new Database\n";
    }
    else
    {
        std::cerr << "Can not create new Database\n";
        assert(false);
    }
}