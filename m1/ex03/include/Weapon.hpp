/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 09:39:19 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 11:18:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string m_type;
    public:
        Weapon( const std::string type );
        ~Weapon( void );
        const std::string& getType( void ) const;
        void setType( const std::string str );
};


#endif