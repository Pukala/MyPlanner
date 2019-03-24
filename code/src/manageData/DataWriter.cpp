#include <sstream>
#include <iostream>
#include <cassert>

#include "DataWriter.hpp"

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

void DataWriter::createTable()
{
    if (dbInfo.isOpenedExistDb and dbInfo.isCreatedTable)
    {
        return;
    }
    // clang-format off
    dbParameters.sqlCommand = "CREATE TABLE TODO("  \
                 "ID INT           PRIMARY KEY     NOT NULL," \
                 "NAME             TEXT            NOT NULL," \
                 "DESCRIPTION      TEXT);";
    // clang-format on
    dbInfo.isCreatedTable = true;
    checkResult();
}

void DataWriter::insertData(const Event &event, uint16_t &lastElementId)
{
    // clang-format off
    dbParameters.sqlCommand = 
                 "INSERT INTO TODO(ID,NAME,DESCRIPTION) " \
                 "VALUES (" + toStr(lastElementId++) + ", '"
                            + event.getNameOfAction() + "', '"
                            + event.getDescription() + "'); ";
    // clang-format on
    dbInfo.isEmpty = false;
    checkResult();
}

void DataWriter::checkResult()
{
    const auto rc = sqlite3_exec(dbParameters.db, dbParameters.sqlCommand.c_str(),
                                 notUsedParametr, 0, &dbParameters.zErrMsg);

    if (rc != SQLITE_OK)
    {
        sqlite3_free(dbParameters.zErrMsg);
        std::cerr << "SQL error: " << dbParameters.zErrMsg << "\n";
        assert(false);
    }
}