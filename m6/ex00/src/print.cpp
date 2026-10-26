/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:17:25 by omawele           #+#    #+#             */
/*   Updated: 2026/09/21 09:21:39 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../include/print.hpp"

static void printCharFromDouble(double d) 
{
    std::cout << "char: ";

    if (std::isnan(d)) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (d < static_cast<double>(std::numeric_limits<char>::min()) ||
        d > static_cast<double>(std::numeric_limits<char>::max())) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    char c = static_cast<char>(d);

    if (!std::isprint(static_cast<unsigned char>(c))) 
    {
        std::cout << "Non displayable" << std::endl;
        return;
    }

    std::cout << "'" << c << "'" << std::endl;
}

static void printIntFromDouble(double d) 
{
    std::cout << "int: ";

    if (std::isnan(d) || std::isinf(d)) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    if (d < static_cast<double>(std::numeric_limits<int>::min()) ||
        d > static_cast<double>(std::numeric_limits<int>::max())) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    int i = static_cast<int>(d);
    std::cout << i << std::endl;
}

static void printFloatFromDouble(double d) 
{
    std::cout << "float: ";

    if (std::isnan(d)) {
        std::cout << "nanf" << std::endl;
        return;
    }

    if (std::isinf(d)) {
        if (d > 0)
            std::cout << "+inff" << std::endl;
        else
            std::cout << "-inff" << std::endl;
        return;
    }

    if (d < -static_cast<double>(std::numeric_limits<float>::max()) ||
        d >  static_cast<double>(std::numeric_limits<float>::max())) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    float f = static_cast<float>(d);

    std::cout << f;
    if (f - static_cast<int>(f) == 0)
        std::cout << ".0f";
    else
        std::cout << "f";
    std::cout << std::endl;
}

static void printDoubleFromDouble(double d) 
{
    std::cout << "double: ";

    if (std::isnan(d)) 
    {
        std::cout << "nan" << std::endl;
        return;
    }

    if (std::isinf(d)) 
    {
        if (d > 0)
            std::cout << "+inf" << std::endl;
        else
            std::cout << "-inf" << std::endl;
        return;
    }

    if (d < -std::numeric_limits<double>::max() ||
        d >  std::numeric_limits<double>::max()) 
    {
        std::cout << "impossible" << std::endl;
        return;
    }

    std::cout << d;
    if (d - static_cast<int>(d) == 0)
        std::cout << ".0";
    std::cout << std::endl;
}

void printAll(double d)
{
    printCharFromDouble(d);
    printIntFromDouble(d);
    printFloatFromDouble(d);
    printDoubleFromDouble(d);
}
