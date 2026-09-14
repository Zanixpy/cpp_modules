/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:08:04 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 10:23:51 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include <cstdio>
#include <string>

AForm::AForm( std::string const &name, short int gradeToSign, short int gradeToExec ) 
    :   m_name(name), 
        m_signed(false),
        m_gradeToSign(gradeToSign),
        m_gradeToExec(gradeToExec)
{
    
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();  
}

AForm::AForm ( AForm const &other ) 
    :   m_name(other.m_name),
        m_gradeToSign(other.m_gradeToSign), 
        m_gradeToExec(other.m_gradeToExec)
{
    m_signed = other.m_signed;
}

AForm& AForm::operator=(const AForm &other) 
{
    if (this != &other)
        m_signed = other.m_signed;
    return *this;
}

AForm::~AForm(){}

const char * AForm::GradeTooHighException::what() const throw()
{
    return "AForm: grade is too high\n";
} 

const char * AForm::GradeTooLowException::what() const throw()
{
    return "AForm: grade is too low\n";
} 

const char * AForm::GradeNotSignedException::what() const throw()
{
    return "AForm: grade is not signed\n";
} 

std::string const &AForm::getName() const {return m_name;}
bool const &AForm::getIsSignedGrade() const {return m_signed;}
short int const &AForm::getGradeToExec() const {return m_gradeToExec;}
short int const &AForm::getGradeToSign() const {return m_gradeToSign;}


bool AForm::beSigned( Bureaucrat const &other )
{
    if (other.getGrade() > m_gradeToSign)
    {
        throw AForm::GradeTooLowException();
        return false;
    }
    m_signed = true;
    return true; 
}

bool AForm::execute(const Bureaucrat &executor) const
{
    if (m_signed == false)
    {
        throw AForm::GradeNotSignedException();
        return m_signed;
    }
    short int grade = executor.getGrade();
    if (grade <= m_gradeToExec)
        this->executeAction();
    else
        throw AForm::GradeTooLowException();
    return true;  
}

std::ostream& operator<<( std::ostream &o, AForm const &other)
{
    o << "Name: " << other.getName() 
      << "\nSigned: " << other.getIsSignedGrade()
      << "\nGrade to exec: " << other.getGradeToExec()
      << "\nGrade to sign: " << other.getGradeToSign()
      << "\n";
    return o;
}