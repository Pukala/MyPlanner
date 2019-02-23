#include "Event.hpp"

std::ostream &operator<<(std::ostream &os, const Event &obj)
{
    std::cout << "ID = " << obj.id << '\n';
    std::cout << "nameOfAction = " << obj.nameOfAction << '\n';
    std::cout << "description = " << obj.description << '\n';

    return os;
}

bool operator==(const Event &lhs, const Event &rhs)
{
    return lhs.id == rhs.id and
           lhs.nameOfAction == rhs.nameOfAction and
           lhs.description == rhs.description;
}