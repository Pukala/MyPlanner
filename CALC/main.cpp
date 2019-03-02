#include <iostream>

#include "RpnCalculator.hpp"

int main()
{
    RpnCalculator rpnCalculator{};
    std::cout << rpnCalculator.compute("3 1 2 + * 2 /") << std::endl;
}

/*
312+*2/ -> 3 * (1 + 2) / 2

3 1 2 +
3 3 *
9 2 /
4.5
return 4.5
*/