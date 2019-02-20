#include <stdio.h>
#include <iostream>

#include "code/include/DbCreator.hpp"
#include "code/include/DataReader.hpp"
#include "code/include/DataWriter.hpp"
#include "code/include/Planner.hpp"

int main()
{
    DbCreator db(std::string{"test"});

    Planner planner(db.getSqlite3());

    planner.createTable(std::string{"TODO"});

    Event firstTask{1, "Sprzatanie2", "Posprzatac mieszkanie"};
    Event secondTask{2, "Sprzatanie", "Posprzatac mieszkanie"};

    planner.insertData(firstTask);
    planner.insertData(secondTask);
    planner.updateData();

    for (auto i : planner.getMyEvents())
    {
        std::cout << i << std::endl;
    }
}