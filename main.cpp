#include "code/include/Planner.hpp"
#include <stdio.h>
#include "code/include/DbCreator.hpp"
#include "code/include/DataReader.hpp"

int main()
{
    DbCreator db(std::string{"test"});
    db.createTable(std::string{"TODO"});

    Event firstTask{1, "Sprzatanie2", "Posprzatac mieszkanie"};
    Event secondTask{2, "Sprzatanie", "Posprzatac mieszkanie"};

    db.insertData(firstTask);
    db.insertData(secondTask);

    DataReader dataReader(db.getSqlite3());
    dataReader.takeDataFromDatabase();

    for (auto i : dataReader.getMyEvents())
    {
        std::cout << i << std::endl;
    }
}