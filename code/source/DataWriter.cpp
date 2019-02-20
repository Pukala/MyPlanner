#include "../include/DataWriter.hpp"
#include <sstream>
#include <iostream>

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

void DataWriter::createTable(const std::string &nameOfTable_)
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

void DataWriter::insertData(const Event &event)
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

void DataWriter::checkResult(const std::string &name)
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