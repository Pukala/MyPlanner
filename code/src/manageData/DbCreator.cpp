#include <iostream>
#include <experimental/filesystem>
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

void DbCreator::setNameOfDatabase(const std::string &name)
{
    nameOfDatabase = name + ".db";
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
    sqlite3_close(dbInfo.db);
    sqlite3_free(zErrMsg);
}

void DbCreator::showDatabases()
{
    std::string path = "/home/pukala/MyPlanner";
    int index{1};
    for (const auto &entry : std::experimental::filesystem::directory_iterator(path))
    {
        std::string file = entry.path();
        if (file.length() > 0)
        {
            std::string::size_type n;

            n = file.find(".db");

            if (n != std::string::npos)
            {
                file.erase(file.begin(), file.begin() + 23);
                std::cout << index++ << "." << file << std::endl;
            }
        }
    }
}

std::vector<std::string> DbCreator::getNamesDatabases()
{
    std::vector<std::string> names{};
    std::string path = "/home/pukala/MyPlanner";
    for (const auto &entry : std::experimental::filesystem::directory_iterator(path))
    {
        std::string file = entry.path();
        if (file.length() > 0)
        {
            std::string::size_type n;

            n = file.find(".db");

            if (n != std::string::npos)
            {
                file.erase(file.begin(), file.begin() + 23);
                names.push_back(file);
            }
        }
    }
    return names;
}

bool DbCreator::isDatabaseExist() const
{
    return std::experimental::filesystem::exists(nameOfDatabase);
}

bool DbCreator::isOpenedSuccessfully()
{
    return (not sqlite3_open(nameOfDatabase.c_str(), &dbInfo.db));
}

void DbCreator::openTheExistingDatabase()
{
    if (isOpenedSuccessfully())
    {
        std::cout << "I have opened existing Database\n";
        dbInfo.isOpenedExistDb = true;
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