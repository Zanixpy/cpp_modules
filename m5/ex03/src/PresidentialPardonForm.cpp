/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:40:29 by omawele           #+#    #+#             */
/*   Updated: 2026/09/05 15:30:59 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( std::string const &target) 
    : AForm("PresidentialPardonForm", 25, 5),
      m_target(target){}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &other ) 
    : AForm(other) {m_target = other.m_target;}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){}

std::string const & PresidentialPardonForm::getTarget() const {return m_target;}

bool PresidentialPardonForm::executeAction() const
{
    std::cout << m_target << ", ya have been pardoned by Zaphod Beeblebrox.\n";
    return true;   
}


