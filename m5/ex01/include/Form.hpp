/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 21:09:27 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 09:40:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include "../include/Bureaucrat.hpp"
#include <iostream>
#include <string>

class Form 
{
    private:
        std::string const m_name;
        bool m_signed;
        short int const m_gradeToSign;
        short int const m_gradeToExec;

    public:
        Form( std::string const &name, short int gradeToSign, short int gradeToExec );
        Form( Form const &other );
        Form& operator=( Form const &other );
        ~Form();
        
        std::string const &getName() const;
        bool const &getIsSignedGrade() const;
        short int const &getGradeToSign() const;
        short int const &getGradeToExec() const;
        
        bool beSigned( Bureaucrat const &other );
                
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
};

std::ostream& operator<<( std::ostream &o, Form const &other);


#endif