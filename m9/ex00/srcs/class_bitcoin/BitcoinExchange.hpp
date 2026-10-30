#ifndef  BTC_HPP
# define BTC_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <ostream>
#include <sstream>
#include <cstring>
#include <string>
#include <exception>
#include <stdexcept>
#include <cctype>
#include <cstdio>
#include <cstdlib>


class BitcoinExchange
{
private:
    std::map<std::string, double> _data_er;
    int                           _min_year;
    int                           _max_year;

public:
    BitcoinExchange();
    BitcoinExchange ( BitcoinExchange const & other );
    BitcoinExchange& operator=( BitcoinExchange const & other );
    ~BitcoinExchange();
    std::map<std::string, double>::iterator findExchangeRate(std::string const &s);
    void BitcoinEvaluation(std::string const &s);

};



#endif
