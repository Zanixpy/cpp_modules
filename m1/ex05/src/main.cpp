/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:15:05 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 15:55:34 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int ac, char **av)
{
    Harl harl;
    
    if (ac != 2)
        return 1;  
    std::string input = av[1];
    harl.complain(input);
    return 0;
}