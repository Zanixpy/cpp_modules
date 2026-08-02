/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 09:40:55 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 11:02:34 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string type ) : m_type( type ) {}

Weapon::~Weapon( void ) {}

const std::string& Weapon::getType( void ) 
{
    return this->m_type;
}

void Weapon::setType( const std::string str )
{
    this->m_type = str; 
}