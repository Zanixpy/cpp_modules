/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 08:51:17 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 07:51:27 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( std::string const name ) : m_name(name)
{
    std::cout << "Character constructor called\n";
    for (int i = 0; i < 4; i++)
        this->m_inventory[i] = NULL;
}

Character::Character( Character const & other )
{
    std::cout << "Character copy constructor called\n";
    this->m_name = other.m_name;
    for (int i = 0; i < 3; i++)
    {
        if (other.m_inventory[i])
            this->m_inventory[i] = other.m_inventory[i]->clone();
        else
            this->m_inventory[i] = NULL;
    }   
}

Character& Character::operator=( Character const & other )
{
    std::cout << "Character copy assignment operator called\n";
    if (this != &other)
    {
        this->m_name = other.m_name;
        for (int i = 0; i < 3; i++)
        {
            if (this->m_inventory[i])
                delete this->m_inventory[i];
            if (other.m_inventory[i])
                this->m_inventory[i] = other.m_inventory[i]->clone();
        }
    }
    return *this;
}

Character::~Character()
{
    std::cout << "Character destructor called\n";
    for (int i = 0; i < 3; i++)
    {
        if (this->m_inventory[i])
            delete this->m_inventory[i];
    }
}

std::string const & Character::getName() const
{
    return this->m_name;
}

void Character::equip( AMateria* m )
{
    for (int i = 0; i < 3; i++)
    {
        if (!this->m_inventory[i])
        {
            this->m_inventory[i] = m;
            return;
        }
    }    
}

void Character::unequip( int idx )
{
    if (idx < 0 || idx > 3)
        return;
    if (!this->m_inventory[idx])
        return;
    this->m_inventory[idx] = NULL;
}

void Character::use( int idx, ICharacter& target )
{
    if (idx < 0 || idx > 3)
        return;
    if (!this->m_inventory[idx])
        return;    
    this->m_inventory[idx]->use(target);
}








