#include "../include/BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other )
{
    m_storage.insert(other.m_storage.begin(), other.m_storage.end());
}

BitcoinExchange& BitcoinExchange::operator=( BitcoinExchange const & other )
{
    if (this != &other)
    {

    }
    return *this;
}

BitcoinExchange::~BitcoinExchange()
{
    while (!m_storage.empty())
        m_storage.erase(m_storage.begin());
}