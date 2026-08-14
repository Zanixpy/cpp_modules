/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 18:13:55 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 07:53:53 by omawele          ###   ########.fr       */
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
        Zombie( std::string const &name );
        ~Zombie( void );
        void announce( void );
        void setName( std::string const str );
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );



#endif 