/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/05 13:47:06 by omawele           #+#    #+#             */
/*   Updated: 2026/09/05 15:06:55 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "../include/RobotomyRequestForm.hpp"
# include "../include/ShrubberyCreationForm.hpp"
# include "../include/PresidentialPardonForm.hpp"


class Intern
{
    public:
        Intern();
        Intern( Intern const &other );
        Intern& operator=( Intern const &other );
        ~Intern();
        AForm* makeForm( std::string const &formName, std::string const &formTarget );
};


#endif