#include <stdio.h>
#include <iostream>

#include "code/src/manageData/DbCreator.hpp"
#include "code/src/Planner.hpp"

int main()
{
    DbCreator db(std::string{"test"});

    Planner planner(db.getSqlite3());

    planner.createTable(std::string{"TODO"});

    for (auto i = 0; i < 6; i++)
    {
        planner.insertData(Event(i, "Sprzatanie2", "Posprzatac mieszkanie"));
    }

    //planner.updateData();

    for (auto i : planner.getDataFromDatabase())
    {
        std::cout << i << std::endl;
    }
}