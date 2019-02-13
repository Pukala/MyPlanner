#pragma once
#include <vector>
#include "Event.hpp"
#include "DataWriter.hpp"
#include "DataReader.hpp"

class Planner
{
public:
    Planner() : dataWriter(events), dataReader(events)
    {
    }

    void addEvents(const Event& event)
    {
        dataWriter.write();
    }


private:
    DataWriter dataWriter;
    DataReader dataReader;
    
    std::vector<Event> events;
};