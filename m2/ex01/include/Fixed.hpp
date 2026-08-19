/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 08:18:41 by omawele           #+#    #+#             */
/*   Updated: 2026/08/14 12:19:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{  
    private:
        int                 m_fixed_point_nb;
        static int const    m_frac_bits = 8;
        
    public:
        Fixed();
        Fixed( int const nb );
        Fixed( float const nb );
        ~Fixed();
        Fixed( const Fixed& other);
        Fixed&  operator=( const Fixed& other );
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt(void) const;
};

std::ostream& operator<<( std::ostream & o, Fixed const &other);

#endif