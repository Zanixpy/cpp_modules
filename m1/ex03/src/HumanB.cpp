/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:00:48 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 11:54:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <cstddef>

HumanB::HumanB( std::string name ) : m_name(name), m_weapon(NULL) {}

HumanB::~HumanB( void ) {}

const std::string& HumanB::getWeaponType( void ) const 
{
    return this->m_weapon->getType();
}

void HumanB::attack( void )
{
    if (this->m_weapon)
        std::cout << "attacks with their " << this->getWeaponType() << '\n';
    else
        std::cout << "No weapon !\n";
}

void HumanB::setWeapon( Weapon  &weapon)
{
    this->m_weapon = &weapon;
}