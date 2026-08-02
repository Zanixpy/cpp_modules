/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:33:13 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:52:58 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called\n";
}

Ice::Ice( Ice const & other ) : AMateria(other)
{
    std::cout << "Ice copy constructor called\n";
}

Ice& Ice::operator=( Ice const & other )
{
    std::cout << "Ice copy assignment operator called\n";
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called\n";
}

AMateria* Ice::clone() const 
{
    return new Ice;
}


void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}