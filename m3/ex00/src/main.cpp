/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/08/27 06:32:51 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("A");
    ClapTrap b("B");
    ClapTrap c("C");
    c = b;

    for( int i = 0; i < 11; i++)
    {
        a.attack("B");         
    }
    a.takeDamage(3);
    a.beRepaired(3);         
    b.takeDamage(5);
    b.beRepaired(5);
    c.takeDamage(9);
    c.attack("A");
    c.takeDamage(9);
    c.attack("S");
    b.takeDamage(5);
    b.attack("E");
    return 0;
}