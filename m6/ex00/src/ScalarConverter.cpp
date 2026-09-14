/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:22:47 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 09:34:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

// === CONSTRUCTORS/DTOR ===
ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( ScalarConverter const &){}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const &){return *this;}

ScalarConverter::~ScalarConverter(){}


// === MEMBER FUNCTION ===

// === CONVERT FUNCTION ===

void printAll(char c, int n, float f, double d)
{
    std::cout << "char: '" << c << "'\n";
    std::cout << "int: " << n << '\n';
    std::cout << "float: " << f << '\n';
    std::cout << "double: " << d << '\n';    
}

int strToInt(std::string &str)
{
    int n = std::atoi(str.c_str());
    return n;
}

char strToChar(std::string &str)
{
    char c = str[0];
    return c;
}

int charToInt(char c)
{
    int n = c;
    return n;
}

char intToChar(int n)
{
    char c = n;
    return c;
}

bool isInteger(std::string &str)
{
    int i = 0, j = str.length();

    while (i < j && str[i] == ' ')
        i++;
    while (j >= 0 && str[j - 1] == ' ')
        j--;

    if (i >= j || (isdigit(str[i]) == 0 && str[i] != '-' &&  str[i] != '+'))
        return false;        
    if (str[i] == '-' ||  str[i] == '+')
        i++;
    for (int k = i; k < j; k++) 
    {
        if (isdigit(str[k]) == 0)
            return false;
    }
    return true;
}

bool isChar(std::string &str)
{
    if (str.length() != 1 || isInteger(str) == true)
        return false;
    return true;
}

bool isFloat(std::string &str)
{
    int i = 0, j = str.length() - 1;

    while (i < (int)str.length() && str[i] == ' ')
        i++;
    while (j >= 0 && str[j] == ' ')
        j--;

    if (i > j)
        return 0;

    std::string sub = str.substr(i, j);
    if (sub == "-inff" || sub == "+inff")
        return true;
    bool hasFSuffix = false;
    if (str[j] == 'f' || str[j] == 'F') 
    {
        hasFSuffix = true;
        j--; 
        if (i > j)    
            return false;
    }
    if (i == j && !isdigit(str[i]))
        return false;

    if (str[i] != '.' && str[i] != '+'
        && str[i] != '-' && !isdigit(str[i]))
        return false;

    bool flagDotOrE = false;
    for (int k = i; k <= j; k++) {
        if (str[k] != '.' && str[k] != '+' 
            && str[k] != '-' && !isdigit(str[k]))
            return false;

        if (str[k] == '.') 
        {
            if (flagDotOrE)
                return false;
            flagDotOrE = true;
            if (k + 1 > j)
                return 0;
            if (!isdigit(str[k + 1]))
                return 0;
        } 
    }
    return true;    
}

void printFloat(std::string &str)
{
    
    if (str.find("-inff") || str.find("+inff"))
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
        if (str.find("-inff"))
            std::cout << "float: -inff\n";
        else
            std::cout << "float: +inff\n";
        return;
    }
    char *end;
    double d = strtod(str.c_str(), &end);
    float f = static_cast<float>(d);
    int n = static_cast<int>(f);
    char c = intToChar(n);
    
}



void printChar(std::string &str)
{
    char c;
    int n;
    float f;
    double d;
    
    c = strToChar(str);
    n = c;
    f = static_cast<float>(c);
    d = static_cast<double>(c);
    printAll(c,  n,  f,  d);
}

void printInteger(std::string &str)
{
    if (str.find("2147483647") || str.find("-2147483648"))
    {
        std::cout << "char: Impossible\n";
        std::cout << "int: Impossible\n";
        return;
    }
    int n = strToInt(str); 
    char c = intToChar(n);
    std::cout << "char: ";
    if (c < 32 || c > 127)
        std::cout << "Non displayable" << '\n';
    else
        std::cout << "'" << c << "'\n";
    std::cout << "int: " << n << '\n';
}

void ScalarConverter::convert(std::string &str)
{
    std::cout << "str: " << str << '\n';
    if (isInteger(str))
    {
        std::cout << "In integer\n";
        printInteger(str);        
    }
    else if (isChar(str))
    {
        std::cout << "In char\n";
        printChar(str);  
    }
    else
        return;
}