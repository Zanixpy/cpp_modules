/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:22:42 by omawele           #+#    #+#             */
/*   Updated: 2026/08/02 12:40:01 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstdlib>

class PhoneBook
{
    private:
        Contact mContacts[8];
        int mOldest_one;
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        void add(void);
        void search(void);
        int getSlotIndex(void);
        int displayContacts(void);
        void displayContact(std::string &input);
        bool setContact(int index);

};


#endif