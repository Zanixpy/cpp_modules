/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 08:19:13 by omawele           #+#    #+#             */
/*   Updated: 2026/08/17 07:18:41 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : m_fixed_point_nb(0)
{
    std::cout << "Default constructor called\n";
}

Fixed::Fixed( int const nb )
{
    std::cout << "Int constructor called\n";
    this->m_fixed_point_nb = nb << this->m_frac_bits;
}

Fixed::Fixed( float const nb )
{
    std::cout << "Float constructor called\n";
    this->m_fixed_point_nb = static_cast<int>(roundf(nb * (1 << this->m_frac_bits)));
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

int  Fixed::toInt( void ) const 
{
    return this->m_fixed_point_nb >> this->m_frac_bits;
}


float Fixed::toFloat( void ) const
{
    float tmp;
    tmp = this->m_fixed_point_nb / this->m_frac_bits;
    return tmp / (1 << this->m_frac_bits);
}

std::ostream& operator<<( std::ostream & o, Fixed const &other)
{
    o << other.toFloat();
    return o;
}
