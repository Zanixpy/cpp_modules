/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 17:27:03 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 13:51:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
#define SCALAR_HPP

#include "print.hpp"
#include "checker.hpp"

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter (ScalarConverter const &other);
        ScalarConverter& operator=(ScalarConverter const &other);
        ~ScalarConverter();
    public:
        static void convert(std::string &s);        
};


#endif