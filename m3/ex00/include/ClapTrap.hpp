/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:24 by omawele           #+#    #+#             */
/*   Updated: 2026/07/28 14:31:43 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string         m_name;
        unsigned int        m_hit_points;
        unsigned int        m_energy_points;
        unsigned int        m_attack_damage;   
    public:
        ClapTrap( const std::string name );
        ClapTrap( const ClapTrap &other );
        ClapTrap& operator=( const ClapTrap &other );
        ~ClapTrap();
        void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        bool  checkEnergyPoints();
        bool  checkHitPoints();
    };





#endif