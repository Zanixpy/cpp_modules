/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/08/27 06:33:54 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test ClapTrap ===" << std::endl;
    ClapTrap a("Clappy");

    a.attack("dummy");
    a.takeDamage(5);
    a.beRepaired(3);
    a.takeDamage(20);
    a.attack("dummy"); 
    a.beRepaired(5);          

    std::cout << std::endl << "=== Test ScavTrap ===" << std::endl;
    ScavTrap b("Scavy");

    b.attack("dummy");
    b.takeDamage(30);
    b.beRepaired(10);
    b.guardGate();

    for (int i = 0; i < 55; ++i) {
        b.attack("bot");
    }
    b.beRepaired(5);

    std::cout << std::endl << "=== Test FragTrap ===" << std::endl;
    FragTrap c("Fraggy");

    c.attack("dummy");
    c.takeDamage(50);
    c.beRepaired(25);
    c.highFivesGuys();

    for (int i = 0; i < 105; ++i) {
        c.attack("dummy");
    }
    c.beRepaired(10);
    return 0;
}

