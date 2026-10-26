/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 14:22:47 by omawele           #+#    #+#             */
/*   Updated: 2026/09/21 10:04:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter( ScalarConverter const &){}

ScalarConverter& ScalarConverter::operator=( ScalarConverter const &){return *this;}

ScalarConverter::~ScalarConverter(){}

// === CONVERT FUNCTION ===

static void printImpossible()
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

static bool strToDouble(std::string const &s, double &out) 
{
    std::stringstream ss(s);
    if (isPseudoDouble(s) || isPseudoFloat(s))
    {
        if (s == "nan" || s == "nanf")
            out = NAN;
        else if (s == "+inf" || s == "+inff")
            out = std::numeric_limits<double>::infinity();
        else if (s == "-inf" || s == "-inff")
            out = -std::numeric_limits<double>::infinity();
        return true;
    }
    ss >> out;
    if (ss.fail())
        return false;
    return true;
}

void ScalarConverter::convert(std::string &s)
{
    if (isCharLiteral(s) || isDoubleLiteral(s) || isFloatLiteral(s) || isIntLiteral(s))
    {
        double d;
        
        if (isCharLiteral(s))
            d = static_cast<double>(static_cast<unsigned char>(s[0]));
        else if (!strToDouble(s, d))
        {
            printImpossible();
            return;
        }
        printAll(d);
    }
    else
        printImpossible();
}

