#ifndef  BTC_HPP
# define BTC_HPP

#include <iostream>
#include <map>

class BitcoinExchange
{
private:
    std::map<std::string, double> m_storage;
public:
    BitcoinExchange();
    BitcoinExchange ( BitcoinExchange const & other );
    BitcoinExchange& operator=( BitcoinExchange const & other );
    ~BitcoinExchange();
};





#endif
