/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 08:23:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test DiamondTrap basique ===" << std::endl;
    DiamondTrap d1("Diamondy");

    d1.attack("training dummy");   // doit utiliser l'attack de ScavTrap
    d1.takeDamage(30);             // hérité de ClapTrap
    d1.beRepaired(20);             // hérité de ClapTrap
    d1.whoAmI();                   // affiche son name + ClapTrap::name

    std::cout << std::endl << "=== Test points de vie / énergie ===" << std::endl;
    // On vérifie que HP = FragTrap, EP = ScavTrap, Damage = FragTrap
    for (int i = 0; i < 60; ++i) {
        d1.attack("dummy");        // devrait finir par ne plus pouvoir attaquer
    }
    d1.beRepaired(10);             // idem si plus d’énergie
    d1.whoAmI();

    std::cout << std::endl << "=== Test copies et destructions ===" << std::endl;
    {
        DiamondTrap d2("Shiny");
        DiamondTrap d3(d2);        // constructeur de copie
        d3.whoAmI();

        DiamondTrap d4("Temp");
        d4 = d1;                   // opérateur d’affectation
        d4.whoAmI();
    } // ici tu dois voir l’ordre de destruction DiamondTrap -> FragTrap/ScavTrap -> ClapTrap

    std::cout << std::endl << "=== Test scope DiamondTrap ===" << std::endl;
    {
        DiamondTrap scoped("Scoped");
        scoped.whoAmI();
        scoped.attack("boss");
    } // bien regarder la chaîne de destruction

    return 0;
}

