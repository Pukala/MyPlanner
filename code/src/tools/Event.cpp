#include "Event.hpp"

std::ostream &operator<<(std::ostream &os, const Event &obj)
{
    std::cout << "ID = " << obj.id << '\n';
    std::cout << "nameOfAction = " << obj.nameOfAction << '\n';
    std::cout << "description = " << obj.description << '\n';

    return os;
}