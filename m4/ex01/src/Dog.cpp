/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:52:00 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 06:46:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog constructor called\n";
    this->m_brain = new Brain();
}

Dog::Dog( const Dog& other ) : Animal(other) 
{
    std::cout << "Dog copy constructor called\n";
    this->m_brain = new Brain(*other.m_brain);
}

Dog& Dog::operator=( const Dog& other )
{
    std::cout << "Dog copy assignment operator called\n";
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->m_brain && other.m_brain)
            *this->m_brain = *other.m_brain;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
    delete this->m_brain;
}

void Dog::makeSound() const
{
    std::cout << "WOOF WOOF\n";
}

void Dog::setIdea(int index, std::string const& idea)
{
    this->m_brain->setIdea(index, idea);
}

std::string const& Dog::getIdea(int index) const
{
    return this->m_brain->getIdea(index);
}