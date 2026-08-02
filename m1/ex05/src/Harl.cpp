/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:19:16 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 15:52:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void ) {}

Harl::~Harl( void ) {}

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my cheese burger !\n";
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money.\n"; 
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. \n";
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now.\n";  
}

void Harl::complain(std::string level) 
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*f[4])( void ) = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error };

    for (int i = 0; i < 4; i++) 
    {
        if (level == levels[i]) 
        {
            (this->*f[i])();
            return;
        }
    }
}

