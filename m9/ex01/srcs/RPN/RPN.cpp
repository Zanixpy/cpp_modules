#include "RPN.hpp"

// CTOR/DTOR

RPN::RPN() 
    :   _numbers(),
        _result(0),
        _isAdd(false), 
        _isSub(false), 
        _isDiv(false), 
        _isMul(false)  
        {}

RPN::RPN( RPN const & other ) 
    :   _numbers(other._numbers),
        _result(other._result),
        _isAdd(other._isAdd), 
        _isSub(other._isSub), 
        _isDiv(other._isDiv), 
        _isMul(other._isMul)  
        {}

RPN& RPN::operator=( RPN const & other )
{
    if (this != &other)
    {
        _numbers = other._numbers;
        _result = other._result;
        _isAdd = other._isAdd;
        _isSub = other._isSub;
        _isDiv = other._isDiv;
        _isMul = other._isMul;
    }
    return *this;
}

RPN::~RPN() {}

// MEMBER FUNCTS

bool RPN::calculation(const std::string &s)
{
    if (s.empty() || s.size() < 5)
    {
        std::cerr << "Error: empty string or not enough litterals\n";
        return false;
    }
    for (int i = 0; s[i]; i++) 
    {
        if (std::isdigit(s[i]))
        {
            if (std::isdigit(s[i + 1]))
            {
                std::cerr << "Error: numbers need to be strict integer in range 0-9\n";
                return false;
            }
            int figure = s[i] - '0';
            _numbers.push(figure);
        }
        else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
        {
            if (ExecuteOperation(s[i]) == false)
                return false;
        }
        else if (s[i] != ' ')
        {
            std::cerr << "Error: other char found than [0-9, *, /, +, -, space]\n";
            return false;
        }
    }
    if (_numbers.size() != 1)
    {
        std::cerr << "Error: too much numbers compared operations\n";
        return false;
    }
    _result = _numbers.top();
    return true;
}

bool RPN::ExecuteOperation(char c)
{
    if (_numbers.size() < 2)
    {
        std::cerr << "Error: lack of numbers for operation\n";
        return false;
    }
    int number1 = _numbers.top();
    _numbers.pop();
    int number2 = _numbers.top();
    _numbers.pop();

    if (c == '+')
        _numbers.push(number2 + number1);
    else if (c == '-')
        _numbers.push(number2 - number1);
    else if (c == '/')
    {
        if (number1 == 0)
        {
            std::cerr << "Error: division by zero\n";
            return false;
        }
        _numbers.push(number2 / number1);
    }
    else if (c == '*')
        _numbers.push(number2 * number1);

    return true;
}

int RPN::getResult() const {return _result;}

