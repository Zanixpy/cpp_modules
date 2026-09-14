/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 08:49:33 by omawele           #+#    #+#             */
/*   Updated: 2026/09/08 08:51:29 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        std::string str = av[1];
        ScalarConverter::convert(str);
    }
    return 0;
}