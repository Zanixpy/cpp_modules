/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:57:03 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 10:23:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() 
{
    std::cout << "Animal constructor called\n";
}

Animal::Animal( const std::string type ) : m_type(type) 
{
    std::cout << "Animal constructor with string arg called\n";
}

Animal::Animal ( const Animal& other )
{
    std::cout << "Animal copy constructor called\n";
    *this = other;
}

Animal& Animal::operator=( const Animal& other )
{
    if (this != &other)
        this->m_type = other.m_type;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

const std::string& Animal::getType() const 
{
    return this->m_type;
}

void Animal::setType( const std::string type )
{
    this->m_type = type;
}

void Animal::makeSound() const
{
    std::cout << "ANIMAAAA\n";
}