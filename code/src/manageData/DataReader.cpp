#include <sstream>

#include "DataReader.hpp"
#include "../tools/Converter.hpp"

namespace
{
std::vector<std::string> events{};
std::vector<std::string> oneEvent{};
static int callbackForData(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (auto i = 0; i < argc; i++)
    {
        if (argv[i])
        {
            events.push_back(argv[i]);
        }
    }
    return 0;
}

static int callbackForDataForOneEvent(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (auto i = 0; i < argc; i++)
    {
        if (argv[i])
        {
            oneEvent.push_back(argv[i]);
        }
    }
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

Event DataReader::takeElementById(const int id)
{
    std::string sql = "Select * from TODO where ID=" + toStr(id) + "; ";

    /* Execute SQL statement */
    const auto rc = sqlite3_exec(dbParameters.db, sql.c_str(), callbackForDataForOneEvent,
                                 dbParameters.notUsedParametr, &dbParameters.zErrMsg);

    sqlite3_free(dbParameters.zErrMsg);
    if (rc != SQLITE_OK)
    {
        std::cerr << "It was some problem with geting data by Id\n";
        assert(false);
    }

    return Converter::convert(oneEvent)[0];
}