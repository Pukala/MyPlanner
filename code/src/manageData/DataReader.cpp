#include "DataReader.hpp"
#include "../tools/Converter.hpp"

namespace
{
std::vector<std::string> events{};
int id;

static int callbackForData(void *NotUsed, int argc, char **argv, char **azColName)
{
    events.reserve(10);
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

std::vector<Event> DataReader::getDataFromDatabase()
{
    const auto rc = sqlite3_exec(dbParameters.db, dbParameters.sqlCommand.c_str(),
                                 callbackForData, dbParameters.notUsedParametr, &dbParameters.zErrMsg);
    sqlite3_free(dbParameters.zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "It was some problem with geting data\n";
        assert(false);
    }
    return Converter::convert(events);
}