/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:01:04 by omawele           #+#    #+#             */
/*   Updated: 2026/09/01 19:53:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <exception>
# include <iostream>
#include <ostream>
# include <string>

class Bureaucrat 
{
    private:
        std::string const m_name;
        short int m_grade;
    
    public:
        Bureaucrat(std::string const & name, short int grade);
        Bureaucrat( Bureaucrat const & other );
        Bureaucrat& operator=( Bureaucrat const & other );
        ~Bureaucrat();
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
        std::string const &getName() const;
        short int const &getGrade() const;
        void incrementGrade();
        void decrementGrade();      
};


std::ostream& operator<<( std::ostream &o, Bureaucrat const &other);


#endif