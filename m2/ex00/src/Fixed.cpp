/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 08:19:13 by omawele           #+#    #+#             */
/*   Updated: 2026/07/28 09:32:27 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed( void ) : m_fixed_point_nb(0) 
{
    std::cout << "Default constructor called\n";
}

Fixed::~Fixed( void )
{
    std::cout << "Destructor called\n";    
}

Fixed::Fixed( const Fixed& other)
{
    std::cout << "Copy constructor called\n";    
    *this = other;
}

Fixed& Fixed::operator=( const Fixed& other)
{
    std::cout << "Copy assignment operator called\n";    
    if (this != &other)
        this->m_fixed_point_nb = other.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const 
{
    std::cout << "getRawBits member function called\n";    
    return this->m_fixed_point_nb;
}

void Fixed::setRawBits( int const raw )
{
    this->m_fixed_point_nb = raw; 
}