#include "../include/DataReader.hpp"
#include <iostream>

namespace
{
std::vector<std::string> events{};

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (auto i = 0; i < argc; i++)
    {
        if (argv[i])
        {
            events.push_back(argv[i]);
        }
        else
        {
            events.push_back(argv[i]);
        }
    }
    return 0;
}
} // namespace

void DataReader::takeDataFromDatabase()
{
    void *notUsedParametr{};
    char *zErrMsg{nullptr};

    std::string sqlCommand{"SELECT * from TODO"};

    const auto rc = sqlite3_exec(db, sqlCommand.c_str(), callback, notUsedParametr, &zErrMsg);
    sqlite3_free(zErrMsg);
    myEvents = events;
}