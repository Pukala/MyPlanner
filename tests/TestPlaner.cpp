#include "gtest/gtest.h"
#include <memory>
#include <iostream>

#include "../code/src/Planner.hpp"
#include "../code/src/manageData/DbCreator.hpp"

TEST(TestPlaner, TestInsertData)
{
    DbCreator db(std::string{"test"});
    Planner planner(db.getdbInfoemation());
    planner.createTable();

    for (auto i = 0; i < 6; i++)
    {
        planner.insertData(Event{"Sprzatanie2", "Posprzatac mieszkanie"});
    }

    EXPECT_EQ(planner.getDataFromDatabase().size(), 6);
}

TEST(TestPlaner, TestInsertDataForExistingDb)
{
    DbCreator db(std::string{"test"});
    Planner planner(db.getdbInfoemation());

    for (auto i = 0; i < 6; i++)
    {
        planner.insertData(Event{"Sprzatanie2", "Posprzatac mieszkanie"});
    }
    EXPECT_EQ(planner.getDataFromDatabase().size(), 12);
}

TEST(TestPlaner, TestTakeElementById)
{
    DbCreator db(std::string{"test"});
    Planner planner(db.getdbInfoemation());

    EXPECT_EQ(planner.takeElementById(2), planner.getDataFromDatabase()[2]);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
