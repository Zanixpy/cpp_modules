/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:00:01 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 11:47:39 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
    private:
        std::string m_name;
        Weapon *m_weapon;
    public:
        HumanB( std::string const name );
        ~HumanB( void );
        void attack( void );
        const std::string& getWeaponType( void ) const;
        void setWeapon( Weapon &weapon );
};

#endif