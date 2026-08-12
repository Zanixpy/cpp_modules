/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 08:11:01 by omawele           #+#    #+#             */
/*   Updated: 2026/08/02 13:16:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
    Zombie *pTmp;

    if (N < 1)
        return NULL;
    pTmp = new Zombie[N];
    for (int i = 0; i < N; i++)
        pTmp[i].setName(name);
    return pTmp;
}
