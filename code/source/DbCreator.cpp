#include "../include/DbCreator.hpp"

DbCreator::DbCreator(const std::string& name) : name(name + ".db")
{
    if (isDatabaseExist())
    {
        openTheExistingDatabase();     
    }
    else
    {
        createNewDatabase();
    }   
}
    
DbCreator::~DbCreator()
{
    std::cout << "I have closed Database\n";
    sqlite3_close(db);
}


bool DbCreator::isDatabaseExist() const 
{
    return std::experimental::filesystem::exists(name);
}

bool DbCreator::isOpenedSuccessfully()
{
    return (not sqlite3_open(name.c_str(), &db));
}

void DbCreator::openTheExistingDatabase()
{
    if (isOpenedSuccessfully())
    {
        std::cout << "I have opened existing Database\n";
    }
    else
    {
        std::cerr << "Can not open Database\n";
        exit(0);
    }           
}

void DbCreator::createNewDatabase()
{
    if (isOpenedSuccessfully())
    {
        std::cout << "I have created new Database\n";
    }
    else
    {
        std::cerr << "Can not create new Database\n";
        exit(0);
    }
}