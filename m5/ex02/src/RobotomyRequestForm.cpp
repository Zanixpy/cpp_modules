/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:40:31 by omawele           #+#    #+#             */
/*   Updated: 2026/09/05 13:07:05 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm( std::string const &target) 
    : AForm("RobotomyRequestForm", 72, 45),
      m_target(target){}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &other ) 
    : AForm(other) {m_target = other.m_target;}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

std::string const & RobotomyRequestForm::getTarget() const {return m_target;}

bool RobotomyRequestForm::executeAction() const
{
    srand(time(0));
    int random = rand() % 2;
    if (random)
        std::cout << m_target << " has been robotomized.\n";
    else
        std::cout << "Robotomy has failed.\n";
    return true;
}
