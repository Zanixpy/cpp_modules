/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:27:51 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 06:46:04 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called\n";
    this->m_brain = new Brain();
}

Cat::Cat( const Cat& other ) : Animal(other) 
{
    std::cout << "Cat copy constructor called\n";
    this->m_brain = new Brain(*other.m_brain);
}

Cat& Cat::operator=( const Cat& other )
{
    std::cout << "Cat copy assignment operator called\n";
    if (this != &other)
    {
        Animal::operator=(other);
        if (this->m_brain && other.m_brain)
            *this->m_brain = *other.m_brain;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
    delete this->m_brain;
}

void Cat::makeSound() const
{
    std::cout << "MIAOUUU\n";
}

void Cat::setIdea(int index, std::string const& idea)
{
    this->m_brain->setIdea(index, idea);
}

std::string const& Cat::getIdea(int index) const
{
    return this->m_brain->getIdea(index);
}