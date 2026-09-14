/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/02 10:41:53 by omawele           #+#    #+#             */
/*   Updated: 2026/09/03 13:19:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_HPP
# define PRESIDENTIAL_HPP

# include "../include/AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string m_target;
    public:
        PresidentialPardonForm( std::string const &target );
        PresidentialPardonForm( PresidentialPardonForm const &other );
        PresidentialPardonForm& operator=( PresidentialPardonForm const &other );
        ~PresidentialPardonForm();

        virtual bool executeAction() const;
        std::string const &getTarget() const;
};


#endif