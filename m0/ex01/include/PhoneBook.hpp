/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:22:42 by omawele           #+#    #+#             */
/*   Updated: 2026/07/24 12:00:31 by omawele          ###   ########.fr       */
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
        int getSlotIndex(void);
        bool isEmpty(int index);
        void resetContact(int index);
        int displayContacts(void);
        void displayContact(std::string &input);
        int setContact(int index);
    public:
        void add(void);
        void search(void);
};


#endif