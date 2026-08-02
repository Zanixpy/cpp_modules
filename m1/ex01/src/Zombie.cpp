/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 18:18:44 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 08:46:15 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) {}

Zombie::~Zombie( void ) {}

void Zombie::announce( void )
{
    if (this->name.empty())
        return;
    std::cout << this->name << ": BraiiiiiiinnnzzzZ...\n";
}

void Zombie::setName( std::string str )
{
    if (str.empty())
        return;
    this->name = str;      
}
