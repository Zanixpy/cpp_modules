/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 08:18:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/28 11:11:16 by omawele          ###   ########.fr       */
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
        Fixed( const Fixed& other );
        Fixed&  operator=( const Fixed& other );

        bool    operator>( const Fixed& other ) const;
        bool    operator<( const Fixed& other ) const;
        bool    operator>=( const Fixed& other ) const;
        bool    operator<=( const Fixed& other ) const;
        bool    operator==( const Fixed& other ) const;
        bool    operator!=( const Fixed& other ) const;

        Fixed   operator+( const Fixed& other ) const;
        Fixed   operator-( const Fixed& other ) const;
        Fixed   operator*( const Fixed& other ) const;
        Fixed   operator/( const Fixed& other ) const;

        Fixed&   operator++();
        Fixed    operator++(int);
        Fixed&   operator--();
        Fixed    operator--(int);

        static Fixed const &max( Fixed const &a, Fixed const &b );
        static Fixed &  max( Fixed  &a, Fixed  &b );
        static Fixed const &  min( Fixed const &a, Fixed const &b );
        static Fixed &  min( Fixed  &a, Fixed  &b );

  

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float   toFloat( void ) const;
        int     toInt(void) const;
};

std::ostream& operator<<( std::ostream & o, Fixed const &other);


#endif