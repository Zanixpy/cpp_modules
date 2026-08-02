/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 07:28:47 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 08:37:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( const std::string name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap construtor called\n";
    this->m_name = name;
    this->m_energy_points = 50;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy construtor called\n";
    this->m_name = other.m_name;
}

DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other )
{
    std::cout << "DiamondTrap copy assignment operator called\n";   
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->m_name = other.m_name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called\n";
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap name: " << this->m_name << ", ClapTrap name: " << ClapTrap::m_name << '\n';    
}


