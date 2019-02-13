#include <iostream>
#include <experimental/filesystem>
#include <cstdlib>

#include "../include/DbCreator.hpp"

namespace
{

static int notUsedParametr(void *NotUsed, int argc, char **argv, char **azColName)
{
    return 0;
}

template <typename T>
std::string toStr(T tmp)
{
    std::ostringstream out;
    out << tmp;
    return out.str();
}

} // namespace

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
        exit(0);
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
        exit(0);
    }
}

void DbCreator::createTable(const std::string &nameOfTable_)
{
    nameOfTable = nameOfTable_;
    // clang-format off
    sqlCommand = "CREATE TABLE " + nameOfTable + "("  \
                 "ID INT           PRIMARY KEY     NOT NULL," \
                 "NAME             TEXT            NOT NULL," \
                 "DESCRIPTION      TEXT);";
    // clang-format on
    checkResult(std::string{"Table created"});
}

void DbCreator::insertData(const Event &event)
{
    // clang-format off
    sqlCommand = 
                 "INSERT INTO " + nameOfTable + 
                 "(ID,NAME,DESCRIPTION) " \
                 "VALUES (" + toStr(event.getId()) + ", '"
                            + event.getNameOfAction() + "', '"
                            + event.getDescription() + "'); ";
    // clang-format on
    checkResult(std::string{"Data inserted"});
}

void DbCreator::checkResult(const std::string &name)
{
    const auto rc = sqlite3_exec(db, sqlCommand.c_str(), notUsedParametr, 0, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        std::cerr << "SQL error: " << zErrMsg << "\n";
        sqlite3_free(zErrMsg);
    }
    else
    {
        std::cout << name << " successfully\n";
    }
}
