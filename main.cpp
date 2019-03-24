#include <stdio.h>
#include <iostream>

#include "code/src/manageData/DbCreator.hpp"
#include "code/src/Planner.hpp"
#include "code/src/tools/Menu.hpp"

void operationOnDatabase();
bool isCreatedTable = false;

DbCreator db{};

int main()
{
    std::cout << "WELCOME IN DATABASE CREATOR\n\n";
    while (true)
    {
        std::cout << "1.Show databases\n";
        std::cout << "2.Create new databases\n";
        std::cout << "3.Open database\n";
        std::cout << "4.Quit\n";

        std::cout << "Select option:";

        char option{};
        std::cin >> option;

        switch (option)
        {
        case '1':
        {
            DbCreator::showDatabases();
            break;
        }
        case '2':
        {
            std::string nameDb{};
            std::cout << "Name:";
            std::cin >> nameDb;
            DbCreator db3(std::string{nameDb});
            break;
        }
        case '3':
        {
            DbCreator::showDatabases();
            auto names = DbCreator::getNamesDatabases();
            std::cout << "Select database:";
            int chose;
            std::cin >> chose;
            if (chose > names.size())
            {
                std::cout << "Can not find this database\n";
                break;
            }
            auto name = names.at(chose - 1);
            name.erase(name.end() - 3, name.end());
            std::cout << name << std::endl;
            db.setNameOfDatabase(name);
            operationOnDatabase();
            break;
        }
        case '4':
        {
            std::cout << "Bye\n";
            exit(0);
        }
        }
        std::cout << "\n\n";
    }
}

void operationOnDatabase()
{
    std::cout << "This is your planner.\n\n";

    Planner planner(db.getdbInfoemation());
    planner.createTable();

    char option{};
    while (option != '4')
    {
        std::cout << "1.Show data in my planner\n";
        std::cout << "2.Find element by ID\n";
        std::cout << "3.Insert data\n";
        std::cout << "4.Quit\n";
        std::cout << "Select option:";

        std::cin >> option;

        switch (option)
        {
        case '1':
        {
            for (auto i : planner.getDataFromDatabase())
            {
                std::cout << i << std::endl;
            }
            break;
        }
        case '2':
        {
            int id{};
            std::cout << "Select ID:";
            std::cin >> id;
            std::cout << planner.takeElementById(id);
            break;
        }
        case '3':
        {
            std::string nameOfAction{};
            std::string description{};
            std::cout << "Put the name of action:\n";
            std::cin.ignore();
            std::getline(std::cin, nameOfAction);
            std::cout << "Put some descripsion:\n";
            std::cin.ignore();
            std::getline(std::cin, description);
            ;
            planner.insertData({nameOfAction, description});
            break;
        }
        }
        std::cin.clear();
    }
}