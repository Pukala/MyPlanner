#pragma once
#include <sqlite3.h>
#include <string>

struct DbParameters
{
    DbParameters() : db(nullptr), notUsedParametr(nullptr),
                     zErrMsg(nullptr), sqlCommand("SELECT * from TODO")
    {
    }

    DbParameters(sqlite3 *db) : db(db), notUsedParametr(nullptr),
                                zErrMsg(nullptr), sqlCommand("SELECT * from TODO")
    {
    }

    sqlite3 *db{nullptr};
    void *notUsedParametr{};
    char *zErrMsg{};
    std::string sqlCommand{};
};