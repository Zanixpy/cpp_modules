// main.cpp
#include "class_bitcoin/BitcoinExchange.hpp"
#include <exception>


int main(int ac, char ** av) 
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./btc av[1]\n";
        return 1;
    }
    try 
    {
        BitcoinExchange test;
        test.BitcoinEvaluation(av[1]);
    
    } catch (std::exception const &e) 
    {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}
