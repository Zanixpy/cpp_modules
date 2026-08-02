/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:12:42 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:53:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource constructor called\n";
    for (int i = 0; i < 4; i++)
        this->m_storage[i] = NULL;
}

MateriaSource::MateriaSource( MateriaSource const & other)
{
    std::cout << "MateriaSource copy constructor called\n";
    for (int i = 0; i < 3; i++)
    {
        if (other.m_storage[i])
            this->m_storage[i] = other.m_storage[i]->clone();
        else
            this->m_storage[i] = NULL;
    } 
}

MateriaSource& MateriaSource::operator=( MateriaSource const & other)
{
    std::cout << "Character copy assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            if (this->m_storage[i])
                delete this->m_storage[i];
            this->m_storage[i] = other.m_storage[i]->clone();
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called\n";
    for (int i = 0; i < 4; i++)
    {
        if (this->m_storage[i])
            delete this->m_storage[i];
    }  
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (!this->m_storage[i])
        {
            this->m_storage[i] = m;
            break;
        }            
    }  
}

AMateria* MateriaSource::createMateria( std::string const & type )
{
    for (int i = 0; i < 4; i++)
    {
        if (this->m_storage[i])
        {
            if (this->m_storage[i]->getType() == type)
                return this->m_storage[i]->clone();
        }
    }
    return 0;
}