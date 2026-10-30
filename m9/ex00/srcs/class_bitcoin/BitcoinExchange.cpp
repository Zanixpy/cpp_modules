#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

// Static functs

bool isIntLiteral(std::string const &s) 
{
    if (s.empty())
        return false; 
    std::size_t i = 0;

    if (s[i] == '+' || s[i] == '-')
        ++i;
    if (i == s.length())
        return false;
       
    for (; i < s.length(); ++i) 
    {
        if (!std::isdigit(static_cast<unsigned char>(s[i])))
            return false;
    }
    return true;
}

bool isDoubleLiteral(std::string const &s) 
{
    if (s.empty() || s.length() < 2)
        return false;
    
    std::size_t i = 0;
    
    if (s[i] == '+' || s[i] == '-')
        ++i;
    if (i == s.length())
        return false;

    bool hasDot = false;
    bool hasDigit = false;

    for (; i < s.length(); ++i) 
    {
        if (s[i] == '.') 
        {
            if (hasDot)
                return false;
            hasDot = true;
        } 
        else if (std::isdigit(static_cast<unsigned char>(s[i])))
            hasDigit = true;
        else
            return false;
    }
    return hasDot && hasDigit;
}

static double strToDouble(const std::string &s)
{
    double tmp;
    std::stringstream str(s);
    str >> tmp;
    return tmp;
}

static int getYear(const std::string &s)
{
    std::stringstream ss(s);
    std::string year;
    std::getline(ss, year, '-');
    return atoi(year.c_str());
}

static int getMonth(const std::string &s)
{
    std::stringstream ss(s);
    std::string month;
    for (int i = 0; i < 2; i++) 
        std::getline(ss, month, '-');
    return atoi(month.c_str());
}

static int getDay(const std::string &s)
{
    std::stringstream ss(s);
    std::string day;
    for (int i = 0; i < 3; i++) 
        std::getline(ss, day, '-');
    return atoi(day.c_str());
}

static bool isLeap(int year) 
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    return (year % 4 == 0);
}


static std::string const createDate(int year, int month, int day)
{
        std::stringstream date;
        if (day < 10 && month < 10)
            date << year << "-0" << month << "-0" << day;
        else if (day < 10)
            date << year << '-' << month << "-0" << day;
        else if (month < 10)
            date << year << "-0" << month << '-' << day;
        else
            date << year << '-' << month << '-' << day;
        return date.str();
}

static bool verifDateFormat(std::string const &s)
{
        std::stringstream ss(s);
        std::string date;
        int count = 0;
        std::getline(ss, date, '|');
        if (date[date.size() - 1] == ' ')
            date.erase(date.size() - 1, 1);
        for (int i = 0; date[i]; i++) 
        {
            while (std::isdigit(date[i]))
                i++;
            if (date[i] == '-')
                count++;
            else if (date[i] == 0)
                break;
            else
                return false;
        }
        if (count != 2)
            return false;
        return true;
}

static bool isValidDate(std::string const &s)
{
    if (verifDateFormat(s) == false)
        return false;

    int year = getYear(s);
    int month = getMonth(s);
    int day = getDay(s);

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31)
        return false;
    if ((month == 2 && isLeap(year) && day > 29) || (month == 2 && isLeap(year) == false && day > 28))
        return false;
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
        return false;
    return true;
}

static bool isValidValue(std::string const &s)
{
        std::stringstream ss(s);
        std::string value;
        for (int i = 0 ; i < 2 ; i++) 
            std::getline(ss, value, '|');
        value.erase(0, 1);
        if (isDoubleLiteral(value) == false && isIntLiteral(value) == false)
            return false;
        double d = strToDouble(value);
        if (d < 0 || d > 1000)
            return false;      
    return true;
}

static std::string const getDate(std::string const &s)
{
    std::stringstream ss(s);
    std::string date;
    std::getline(ss, date, '|');
    if (date[date.size() - 1] == ' ')
        date.erase(date.size() - 1, 1);
    return date;
}

static double getValue(std::string const &s)
{
    std::stringstream ss(s);
    std::string value;
    for (int i = 0 ; i < 2 ; i++) 
        std::getline(ss, value, '|');
    if (!ss.eof())
    {
        ss.clear();
        throw std::runtime_error("Error in getValue");
    }
    double d = strToDouble(value);
    return d;
}

// CTOR/DTOR

BitcoinExchange::BitcoinExchange() 
{
    _min_year = 10000;
    std::ifstream data("external/data.csv");
    if (!data.is_open())
        throw std::runtime_error("Unable to open file!");
    std::string buffer;
    std::getline(data, buffer);
    while (std::getline(data, buffer)) 
    {
        int tmp = getYear(buffer);
        if (tmp < _min_year)
            _min_year = tmp;
        std::string key =  buffer.substr(0, buffer.find(","));
        double value = strToDouble(buffer.substr(buffer.find(",") + 1));
        _data_er[key] = value;
    }
    if (!data.eof())
    {
        data.close();
        throw std::runtime_error("Error while reading file");
    }
    data.close();
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const & other )
{
    _data_er.insert(other._data_er.begin(), other._data_er.end());
}

BitcoinExchange& BitcoinExchange::operator=( BitcoinExchange const & other )
{
    if (this != &other)
    {
        _data_er.clear();
        _data_er.insert(other._data_er.begin(), other._data_er.end());
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// MEMBER FUNCTS

std::map<std::string, double>::iterator BitcoinExchange::findExchangeRate(const std::string &s)
{
    std::map<std::string, double>::iterator it;
    int year = getYear(s);
    int month = getMonth(s);
    int day = getDay(s);
    while (year >= _min_year) 
    {
        it = _data_er.find(createDate(year, month, day));
        if (it != _data_er.end())
            return it;
        day--;
        if (day == 0)
        {
            day = 31;
            month--;
        }
        if (month == 0)
        {
            month = 12;
            year--;
        }
    }
    return _data_er.end();
}

void BitcoinExchange::BitcoinEvaluation(const std::string &s)
{
    std::ifstream data(s.c_str());
    if (!data.is_open())
        throw std::runtime_error("Unable to open file (av[1])");

    std::string buffer;
    while (std::getline(data, buffer)) 
    {
        if (isValidDate(buffer) == false)
            std::cout << "Error: date invalid, range: [0 : +inf[\n";
        else
        {
            if (isValidValue(buffer) == false)
                std::cout << "Error: value invalid, range [0 : 1000]\n";
            else
            {
                std::string date = getDate(buffer);
                double value = getValue(buffer);
                std::map<std::string, double>::iterator it = findExchangeRate(date);
                if (it == _data_er.end())
                    std::cout << "Can't find a correct exchange rate\n";
                else
                    std::cout << date << " => " << value << " = " << value * it->second << '\n'; 
            }
        }
    }
    if (!data.eof())
    {
        data.close();
        throw std::runtime_error("Error while reading file");
    }
    data.close();
}

