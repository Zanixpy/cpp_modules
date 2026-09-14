/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:42:40 by omawele           #+#    #+#             */
/*   Updated: 2026/09/05 15:30:49 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_HPP
# define ROBOTOMY_HPP

#include "../include/AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm : public AForm
{
    private:
        std::string m_target;
    public:
        RobotomyRequestForm( std::string const &target );
        RobotomyRequestForm( RobotomyRequestForm const &other );
        RobotomyRequestForm& operator=( RobotomyRequestForm const &other );
        ~RobotomyRequestForm();
        
        virtual bool executeAction() const;
        std::string const &getTarget() const;


};

#endif