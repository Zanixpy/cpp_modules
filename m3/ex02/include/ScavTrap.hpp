/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 05:51:17 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 06:13:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap( std::string const name );
        ~ScavTrap();
        ScavTrap( ScavTrap const &other );
        ScavTrap& operator=( ScavTrap const &other );
        void attack(const std::string &target);
        void guardGate();
};

#endif

