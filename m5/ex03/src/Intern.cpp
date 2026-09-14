/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:53:11 by omawele           #+#    #+#             */
/*   Updated: 2026/09/05 16:06:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include <cstddef>
#include <string>

Intern::Intern(){}

Intern::Intern( Intern const &){}

Intern&  Intern::operator=(const Intern &) {return *this;}

Intern::~Intern(){}

static AForm* makeRobotomy(const std::string &target) {return new RobotomyRequestForm(target);}
static AForm* makeShrubbery(const std::string &target) {return new ShrubberyCreationForm(target);}
static AForm* makePresidential(const std::string &target) {return new PresidentialPardonForm(target);}

AForm* Intern::makeForm( std::string const &formName, std::string const &formTarget )
{
    std::string typeform[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    AForm* (*f[3])( const std::string &target ) = {&makeRobotomy, &makeShrubbery, &makePresidential};
    for (int i = 0; i < 3; i++)
    {
        if (typeform[i] == formName)
        {
            std::cout << "Intern creates " << formName << "\n";
            return f[i](formTarget);
        }
    }
    std::cout << "Intern couldn't create a unknown form\n";
    return NULL;
}