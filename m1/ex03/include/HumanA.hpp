/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:54:40 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 11:50:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string m_name;
        Weapon &m_weapon;
    public:
        HumanA( std::string name, Weapon &weapon );
        ~HumanA( void );
        void attack( void );
        const std::string& getWeaponType( void );
};

#endif