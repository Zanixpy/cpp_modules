// main.cpp
#include "RPN/RPN.hpp"


int main(int ac, char ** av) 
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./RPN [RPN expression]\n";
        return 1;
    }
    RPN test;
    if (test.calculation(av[1]) == false)
        return 1;
    else
        std::cout << test.getResult() << '\n';
    return 0;
}
