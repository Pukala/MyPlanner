#pragma once
#include <vector>
#include <iostream>
#include "Event.hpp"

class DataWriter
{
public:
    DataWriter(std::vector<Event>& events)
    : events(events)
    {
    }

    void write()
    {
        

    }
private:
    std::vector<Event>& events;
};