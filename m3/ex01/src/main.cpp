/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 06:08:23 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << "=== Construction des objets ===" << std::endl;
    ClapTrap   clap("Clappy");
    ScavTrap   scav("Scavy");

    std::cout << "\n=== Test des attaques ===" << std::endl;
    clap.attack("un ennemi quelconque");
    scav.attack("un gros monstre");

    std::cout << "\n=== Test des dégâts et réparations ===" << std::endl;
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.takeDamage(20);
    scav.beRepaired(10);

    std::cout << "\n=== Test de la capacité spéciale de ScavTrap ===" << std::endl;
    scav.guardGate();

    std::cout << "\n=== Test énergie / points de vie à zéro ===" << std::endl;
    // On vide l’énergie de ScavTrap pour vérifier qu’il ne peut plus agir
    for (int i = 0; i < 55; ++i) {
        scav.attack("dummy");
    }

    std::cout << "\n=== Fin du main, destruction des objets ===" << std::endl;
    return 0;
}
