/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 13:06:14 by omawele           #+#    #+#             */
/*   Updated: 2026/07/28 14:46:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap a("A");
    ClapTrap b("B");
    ClapTrap c = b;

    a.attack("B");         
    b.takeDamage(5);
    c.takeDamage(9);
    return 0;
}