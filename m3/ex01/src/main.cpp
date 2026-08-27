/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/08/27 06:24:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
    std::cout << " Constructors" << std::endl;
    ClapTrap   clap("Clappy");
    ScavTrap   scav("Scavy");
    ScavTrap   scave("Us");
    scave = scav;

    std::cout << "\n Attack" << std::endl;
    clap.attack("Us");
    scav.attack("Clappy");
    scave.attack("Scavy");

    std::cout << "\n Damage and repaired" << std::endl;
    clap.takeDamage(5);
    clap.beRepaired(3);

    scav.takeDamage(20);
    scav.beRepaired(10);

    scave.takeDamage(12);
    scave.beRepaired(71);

    std::cout << "\n ScavTrap's skill" << std::endl;
    scav.guardGate();

    std::cout << "\n Energy and life test" << std::endl;
    for (int i = 0; i < 50; ++i) {
        scav.attack("dummy");
    }
    return 0;
}
