/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:33:03 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:52:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor called\n";
}

Cure::Cure( Cure const & other ) : AMateria(other)
{
    std::cout << "Cure copy constructor called\n";
}

Cure& Cure::operator=( Cure const & other )
{
    std::cout << "Cure copy assignment operator called\n";
    if (this != &other)
        AMateria::operator=(other);
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called\n";
}

AMateria* Cure::clone() const 
{
    return new Cure;
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() <<"'s wounds *\n";
}