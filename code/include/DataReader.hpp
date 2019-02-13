#pragma once
#include <vector>
#include "Event.hpp"

class DataReader
{
public:
    DataReader(std::vector<Event>& events)
    : events(events)
    {
    }

    static int callback(void *NotUsed, int argc, char **argv, char **azColName) 
    {
        for(auto i = 0; i<argc; i++)
        {
            printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        }
        printf("\n");
    return 0;
}
private:
    std::vector<Event>& events;
};