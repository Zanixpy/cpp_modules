/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 05:53:45 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 06:49:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( std::string const name ) : ClapTrap(name)
{
    std::cout << "ScavTrap construtor called\n";
    this->m_attack_damage = 20;
    this->m_energy_points = 50;
    this->m_hit_points = 100;
}


ScavTrap::ScavTrap( ScavTrap const &other ) : ClapTrap(other)
{
    std::cout << "ScavTrap copy construtor called\n";
}

ScavTrap&  ScavTrap::operator=( ScavTrap const &other )
{
    std::cout << "ScavTrap copy assignment operator called\n";
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_attack_damage = other.m_attack_damage;
        this->m_energy_points = other.m_energy_points;
        this->m_hit_points = other.m_hit_points;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called\n";
}

void ScavTrap::attack( const std::string& target )
{
    if (checkEnergyPoints() || checkHitPoints())
        return;
    this->m_energy_points--;
    std::cout << "ScavTrap " << this->m_name << " attacks " << target 
    << ", causing " << this->m_attack_damage << " points of damage!\n";  
}

void ScavTrap::guardGate()
{
    if (checkHitPoints())
        return;
    std::cout << "ScavTrap " << this->m_name << " is in Gate keeper mode!\n";
}



