/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:32:51 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:52:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( std::string const & type ) : type(type)
{
    std::cout << "AMateria constructor called\n";
}

AMateria::AMateria( AMateria const & other)
{
    std::cout << "AMateria copy constructor called\n";
    *this = other;    
}

AMateria& AMateria::operator=( AMateria const & other)
{
    std::cout << "AMateria copy assignment operator called\n";
    static_cast<void>(other);
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called\n";
}

std::string const & AMateria::getType() const
{
    return this->type;
}