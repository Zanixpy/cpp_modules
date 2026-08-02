/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:57:03 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 10:23:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() 
{
    std::cout << "AAnimal constructor called\n";
}

AAnimal::AAnimal( const std::string type ) : m_type(type) 
{
    std::cout << "AAnimal constructor with string arg called\n";
}

AAnimal::AAnimal ( const AAnimal& other )
{
    std::cout << "AAnimal copy constructor called\n";
    *this = other;
}

AAnimal& AAnimal::operator=( const AAnimal& other )
{
    if (this != &other)
        this->m_type = other.m_type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called\n";
}

const std::string& AAnimal::getType() const 
{
    return this->m_type;
}

void AAnimal::setType( const std::string type )
{
    this->m_type = type;
}

void AAnimal::makeSound() const
{
    std::cout << "ANIMAAAA\n";
}