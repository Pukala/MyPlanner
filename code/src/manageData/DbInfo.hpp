#pragma once
#include <sqlite3.h>

struct DbInfo
{
    sqlite3 *db{nullptr};
    bool isOpenedExistDb{false};
    bool isEmpty{true};
    bool isCreatedTable{false};
};