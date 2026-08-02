/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 07:33:28 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 08:08:34 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie test;
    Zombie *pYo = newZombie("Lia");

    test.announce();
    randomChump("Heios");
    pYo->announce();
    delete pYo;
    pYo = NULL;
    return 0;
}