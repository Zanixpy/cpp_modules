/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:55:21 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 11:53:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon &weapon ) : m_name(name), m_weapon(weapon) {}

HumanA::~HumanA( void ) {}

const std::string& HumanA::getWeaponType( void ) 
{
    return this->m_weapon.getType();
}

void HumanA::attack( void )
{
    std::cout << "attacks with their " << this->getWeaponType() << '\n';
}