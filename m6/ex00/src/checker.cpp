/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:29:20 by omawele           #+#    #+#             */
/*   Updated: 2026/09/21 10:02:42 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.hpp"

bool isPseudoFloat(std::string const &s) {return s == "-inff" || s == "+inff" || s == "nanf";}

bool isPseudoDouble(std::string const &s) {return s == "-inf" || s == "+inf" || s == "nan";}

bool isCharLiteral(std::string const &s) {return s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));}

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

bool isFloatLiteral(std::string const &s) 
{
    if (s.empty() || s.length() < 2)
        return false;
    if (s[s.length() - 1] != 'f')
        return false;
    if (isPseudoFloat(s))
        return true;

    std::size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        ++i;
    if (i >= s.length() - 1)
        return false;

    bool hasDot = false;
    bool hasDigit = false;

    for (; i < s.length() - 1; ++i) 
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

bool isDoubleLiteral(std::string const &s) 
{
    if (s.empty() || s.length() < 2)
        return false;
    if (isPseudoDouble(s))
        return true;
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
