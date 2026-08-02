/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 08:18:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/28 09:26:51 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int m_fixed_point_nb;
    static int const frac_bits = 8;
public:
    Fixed( void );
    ~Fixed();
    Fixed( const Fixed& other);
    Fixed& operator=( const Fixed& other);
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};




#endif