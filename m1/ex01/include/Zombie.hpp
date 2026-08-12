/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 08:19:43 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 08:20:11 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    private:
        std::string m_name;
    public:
        Zombie( void );
        Zombie( std::string name );
        ~Zombie( void );
        void announce( void );
        void setName( std::string str );
};

Zombie* zombieHorde( int N, std::string name);

#endif 