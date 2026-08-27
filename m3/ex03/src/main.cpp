/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/08/27 14:41:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    
    std::cout << "==Basic tests==\n";
    DiamondTrap d1("Diamondy");
    d1.attack("dummy");   
    d1.takeDamage(30);    
    d1.beRepaired(20);    
    d1.whoAmI();                 

    std::cout << "\n==Energy tests==\n";
    for (int i = 0; i < 50; ++i) {
        d1.attack("dummy");       
    }

    std::cout << "\n==Copy, constructors, destructors==\n";
    DiamondTrap d2("Shiny");
    DiamondTrap d3(d2);       
    d3.whoAmI();

    DiamondTrap d4("Temp");
    d4 = d1;                  
    d4.whoAmI();
    return 0;
}

