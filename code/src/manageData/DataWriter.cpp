#include "DataWriter.hpp"
#include <sstream>
#include <iostream>
#include <cassert>

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
    dbParameters.sqlCommand = "CREATE TABLE " + nameOfTable + "("  \
                 "ID INT           PRIMARY KEY     NOT NULL," \
                 "NAME             TEXT            NOT NULL," \
                 "DESCRIPTION      TEXT);";
    // clang-format on
    checkResult(std::string{"Table created"});
}

void DataWriter::insertData(const Event &event)
{
    // clang-format off
    dbParameters.sqlCommand = 
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
    const auto rc = sqlite3_exec(dbParameters.db, dbParameters.sqlCommand.c_str(),
                                 notUsedParametr, 0, &dbParameters.zErrMsg);

    if (rc != SQLITE_OK)
    {
        sqlite3_free(dbParameters.zErrMsg);
        std::cerr << "SQL error: " << dbParameters.zErrMsg << "\n";
        assert(false);
    }
    else
    {
        std::cout << name << " successfully\n";
    }
}