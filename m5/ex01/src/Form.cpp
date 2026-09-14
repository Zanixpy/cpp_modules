/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:08:04 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 09:44:22 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include <string>

Form::Form( std::string const &name, short int gradeToSign, short int gradeToExec ) 
    :   m_name(name), 
        m_signed(false),
        m_gradeToSign(gradeToSign),
        m_gradeToExec(gradeToExec)
{
    
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();  
}

Form::Form ( Form const &other ) 
    :   m_name(other.m_name),
        m_gradeToSign(other.m_gradeToSign), 
        m_gradeToExec(other.m_gradeToExec)
{
    m_signed = other.m_signed;
}

Form& Form::operator=(const Form &other) 
{
    if (this != &other)
        m_signed = other.m_signed;
    return *this;
}

Form::~Form(){}

const char * Form::GradeTooHighException::what() const throw()
{
    return "Form: grade is too high\n";
} 

const char * Form::GradeTooLowException::what() const throw()
{
    return "Form: grade is too low\n";
} 

std::string const &Form::getName() const {return m_name;}
bool const &Form::getIsSignedGrade() const {return m_signed;}
short int const &Form::getGradeToExec() const {return m_gradeToExec;}
short int const &Form::getGradeToSign() const {return m_gradeToSign;}


bool Form::beSigned( Bureaucrat const &other )
{
    if (other.getGrade() > m_gradeToSign)
    {
        throw Form::GradeTooLowException();
        return false;
    }
    m_signed = true;
    return true; 
}


std::ostream& operator<<( std::ostream &o, Form const &other)
{
    o << "Name: " << other.getName() 
      << "\nSigned: " << other.getIsSignedGrade()
      << "\nGrade to exec: " << other.getGradeToExec()
      << "\nGrade to sign: " << other.getGradeToSign()
      << "\n";
    return o;
}