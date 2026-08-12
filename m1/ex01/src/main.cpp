/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 08:20:22 by omawele           #+#    #+#             */
/*   Updated: 2026/08/02 13:23:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
    Zombie *test = zombieHorde( 12, "Zan");
    if (!test)
        return 1;
    for (int i = 0; i < 12; i++)
    {
        test[i].announce();   
    }
    delete[] test;
    return 0;
}