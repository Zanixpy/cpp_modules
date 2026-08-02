/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 07:00:00 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 07:24:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( std::string const name ) : ClapTrap(name)
{
    std::cout << "FragTrap construtor called\n";
    this->m_attack_damage = 30;
    this->m_energy_points = 100;
    this->m_hit_points = 100;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap(other)
{
    std::cout << "FragTrap copy construtor called\n";    
}

FragTrap& FragTrap::operator=( const FragTrap& other )
{
    std::cout << "FragTrap copy assignment operator called\n";
    if (this != &other)
        ClapTrap::operator=(other);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap destructor called\n";
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->m_name << " is inviting you to a high fives!\n";
}