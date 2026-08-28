/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:57:03 by omawele           #+#    #+#             */
/*   Updated: 2026/08/27 14:59:52 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
{
    std::cout << "WrongAnimal constructor called\n";
}

WrongAnimal::WrongAnimal( const std::string &type ) : m_type(type) 
{
    std::cout << "WrongAnimal constructor with string arg called\n";
}

WrongAnimal::WrongAnimal ( const WrongAnimal& other )
{
    std::cout << "WrongAnimal copy constructor called\n";
    *this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other )
{
    if (this != &other)
        this->m_type = other.m_type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

const std::string& WrongAnimal::getType() const 
{
    return this->m_type;
}

void WrongAnimal::setType( const std::string type )
{
    this->m_type = type;
}

void WrongAnimal::makeSound() const
{
    std::cout << "MIAOUUU\n";
}