/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:43:08 by omawele           #+#    #+#             */
/*   Updated: 2026/09/03 13:20:48 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_HPP
# define SHRUBBERY_HPP

#include "../include/AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string m_target;
    public:
        ShrubberyCreationForm( std::string const &target );
        ShrubberyCreationForm( ShrubberyCreationForm const &other );
        ShrubberyCreationForm& operator=( ShrubberyCreationForm const &other );
        ~ShrubberyCreationForm();

        virtual bool executeAction() const ;
        std::string const &getTarget() const;

};

#endif