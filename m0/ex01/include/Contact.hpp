/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:23:56 by omawele           #+#    #+#             */
/*   Updated: 2026/07/26 17:53:09 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

class Contact
{
    private:
        std::string mfirst_name;
        std::string mlast_name;
        std::string mnickname;
        std::string mphone_number;
        std::string mdarkest_secret;
    public:
        Contact(void);
        ~Contact(void);
        void setFirstName(std::string input);
        void setLastName(std::string input);
        void setNickname(std::string input);
        void setPhoneNumber(std::string input);
        void setDarkestSecret(std::string input);
        std::string getFirstName(void);
        std::string getLastName(void);
        std::string getNickname(void);
        std::string getPhoneNumber(void);
        std::string getDarkestSecret(void);    
        void clearContact(void);
        bool isContactValid(void);
};

#endif