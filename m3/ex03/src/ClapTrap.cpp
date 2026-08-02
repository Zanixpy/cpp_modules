/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:00 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 06:50:30 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( const std::string name )
{
    std::cout << "Construtor called\n";
    this->m_name = name;
    this->m_attack_damage = 0;
    this->m_energy_points = 10;
    this->m_hit_points = 10;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destrutor called\n";
}

ClapTrap::ClapTrap( const ClapTrap &other )
{
    std::cout << "Copy constructor called\n";
    *this = other;
}

ClapTrap& ClapTrap::operator=( const ClapTrap &other )
{
    std::cout << "Copy assignment operator called\n";
    if (this != &other)
    {
        this->m_name = other.m_name;
        this->m_attack_damage = other.m_attack_damage;
        this->m_energy_points = other.m_energy_points;
        this->m_hit_points = other.m_hit_points;
    }
    return *this;
}

void ClapTrap::attack( const std::string& target )
{
    if (checkEnergyPoints() || checkHitPoints())
        return;
    this->m_energy_points--;
    std::cout << "ClapTrap " << this->m_name << " attacks " << target 
    << ", causing " << this->m_attack_damage << " points of damage!\n";  
}

void ClapTrap::beRepaired( unsigned int amount)
{
    if (checkEnergyPoints() || checkHitPoints())
        return;
    this->m_hit_points += amount;
    std::cout << "ClapTrap " << this->m_name << " repaired " 
    << amount << " points of hit points!\n"; 
}

void ClapTrap::takeDamage( unsigned int amount )
{
    if (checkHitPoints())
        return;
    this->m_hit_points -= amount;
    if (amount > this->m_hit_points)
        this->m_hit_points = 0;
    std::cout << "ClapTrap " << this->m_name << " took " 
    << amount << " points of damage, only " << this->m_hit_points << " left !\n" ; 
}

bool ClapTrap::checkEnergyPoints()
{
    if (this->m_energy_points == 0)
    {
        std::cout << "ClapTrap " << this->m_name << " has not energy points left !\n";
        return true;      
    }
    return false;
}

bool ClapTrap::checkHitPoints()
{
    if (this->m_hit_points == 0)
    {
        std::cout << "ClapTrap " << this->m_name << " has not hit points left !\n";
        return true;
    }
    return false;
}


