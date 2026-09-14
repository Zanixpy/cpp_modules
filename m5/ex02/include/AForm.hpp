/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:09:27 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 09:58:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

class AForm 
{
    private:
        std::string const m_name;
        bool m_signed;
        short int const m_gradeToSign;
        short int const m_gradeToExec;

    public:
        AForm( std::string const &name, short int gradeToSign, short int gradeToExec );
        AForm( AForm const &other );
        AForm& operator=( AForm const &other );
        virtual ~AForm();
        
        std::string const &getName() const;
        bool const &getIsSignedGrade() const;
        short int const &getGradeToSign() const;
        short int const &getGradeToExec() const;
        
        bool beSigned( Bureaucrat const &other );
        bool execute( Bureaucrat const &executor ) const;
        virtual bool executeAction() const = 0;
                
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };
        class GradeNotSignedException : public std::exception
        {
            public:
                virtual const char * what() const throw();
        };  
};

std::ostream& operator<<( std::ostream &o, AForm const &other);


#endif