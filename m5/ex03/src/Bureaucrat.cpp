/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:15:03 by omawele           #+#    #+#             */
/*   Updated: 2026/09/03 10:39:25 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <ostream>

Bureaucrat::Bureaucrat(std::string const & name, short int grade) 
    : m_name(name), 
      m_grade(grade)
{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & other ) : m_name(other.getName()), m_grade(other.m_grade) {}

Bureaucrat& Bureaucrat::operator=( Bureaucrat const & other )
{
    if (this != &other)
        this->m_grade = other.m_grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const char * Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high\n";
} 

const char * Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low\n";
} 

std::string const & Bureaucrat::getName() const {return this->m_name;}

short int const & Bureaucrat::getGrade() const {return this->m_grade;}

void Bureaucrat::incrementGrade()
{   
    m_grade--;
    if (m_grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    m_grade++;
    if (m_grade > 150)
        throw Bureaucrat::GradeTooLowException();   
}

void Bureaucrat::signForm( AForm &other ) const
{
    if (other.beSigned(*this))
        std::cout << m_name << " signed " << other.getName() << "\n";
    else
    {
        std::cout << m_name << " couldn't sign " << other.getName() << " because "
                  << m_name << "'s grade is low.\n";
    }
}

void Bureaucrat::executeForm(AForm const &form) const 
{
    if (form.execute(*this))
        std::cout << m_name << " executed " << form.getName() << "\n";
    else
    {
        std::cout << m_name << " couldn't sign " << form.getName() << " because "
                  << m_name << "'s grades don't meet requirements.\n";       
    }
}

std::ostream& operator<<( std::ostream&o, Bureaucrat const &other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade() << ".\n";
    return o;
}

