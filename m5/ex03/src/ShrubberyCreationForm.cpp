/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:40:34 by omawele           #+#    #+#             */
/*   Updated: 2026/09/05 15:31:04 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) 
    : AForm("ShrubberyCreationForm", 145, 137),
      m_target(target){}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &other ) 
    : AForm(other) {m_target = other.m_target;}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &other ) 
{
    if (this != &other)
    {
        AForm::operator=(other);
        m_target = other.m_target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

std::string const & ShrubberyCreationForm::getTarget() const {return m_target;}


bool ShrubberyCreationForm::executeAction() const
{
    std::string filename = m_target + "_shrubbery";
    std::fstream file(filename.c_str(), std::ios::out);
    if (!file.is_open())
    {
        std::cout << "Can't create file.\n";
        return false;
    }
    file << "  /\\\n" << " /**\\\n" << "/****\\\n" << "  ||\n" << "  ||\n";
    file.close();
    return true;
}

