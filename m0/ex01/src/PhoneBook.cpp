/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:26:59 by omawele           #+#    #+#             */
/*   Updated: 2026/07/26 18:07:14 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// UTILS


static void printCharN(int n, char c)
{
    for (int i = 0; i < n; i++)
        std::cout << c;
}

static void print_str(std::string str, int mode, int last)
{
    int len = str.length();
    if (len < 10)
    {
        printCharN(10 - len, ' ');
        std::cout << str;
    }
    else if (mode == 0)
        std::cout << str.substr(0, 9) + '.';
    else if (mode == 1)
        std::cout << str;
    if (!last)
        std::cout << '|';
}

static bool isNumberValid(std::string &str)
{
    int nb;
    
    if (str.empty())
        return (false);
    for (size_t i = 0, len = str.length(); i < len; i++)
    {
        if (!isdigit(str[i]))
            return (false);
    }
    nb = atoi(str.c_str());
    if (nb < 0 || nb > 7)
        return (false);
    return (true);
    
}



int PhoneBook::displayContacts(void)
{ 
    if (this->mContacts[0].isContactValid() == false)
    {
        std::cout << "There's no contact !" << std::endl;
        return (1);
    }
    print_str("index", 0, 0);
    print_str("first name", 1, 0);
    print_str("last name", 1, 0);
    print_str("nickname", 1, 1);
    std::cout << std::endl;
    for (int index = 0; index < 8; index++)
    {
        if (this->mContacts[index].isContactValid() == false)
            return (0);
        printCharN(9,' ');
        std::cout << index << '|';
        print_str(this->mContacts[index].getFirstName(), 0, 0);
        print_str(this->mContacts[index].getLastName(), 0, 0);
        print_str(this->mContacts[index].getNickname(), 0, 1);    
        std::cout << std::endl;
    }   
    return (0);
}

void PhoneBook::displayContact(std::string &input)
{
    int nb = atoi(input.c_str());
    if (this->mContacts[nb].isContactValid() == false)
    {
        std::cout << "Type a number associated to a saved contact !" << std::endl;
        return;
    }
    std::cout << std::endl << "Contact " << nb << std::endl;
    std::cout << "First name: " << this->mContacts[nb].getFirstName() << std::endl;
    std::cout << "Last name: " << this->mContacts[nb].getLastName() << std::endl;
    std::cout << "Nickname: " << this->mContacts[nb].getNickname() << std::endl;
    std::cout << "Phone number: " << this->mContacts[nb].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << this->mContacts[nb].getDarkestSecret() << std::endl << std::endl;
}

int PhoneBook::getSlotIndex(void)
{
    for (int index = 0; index < 8; index++)
    {
        if (this->mContacts[index].isContactValid() == false)
            return (index);
    }
    return (this->mOldest_one);
}

// MAIN FUNCTION

void PhoneBook::add(void)
{
    int index = this->getSlotIndex();
    
    if (this->setContact(index))
    {
        std::cout << "Error: can't have empty fields." << std::endl;     
        return;   
    }
    else
        std::cout << "New contact created !" << std::endl;
    if (this->mContacts[7].isContactValid() && index == 7)
        this->mOldest_one =  0;
    else if (this->mContacts[7].isContactValid() && index != 7)
        this->mOldest_one =  index + 1;
}

void PhoneBook::search(void)
{
    if (this->displayContacts())
        return;
    std::string input;
    std::cout << "Select contact: ";
    std::getline(std::cin, input);
    if (isNumberValid(input))
        this->displayContact(input);
    else
        std::cout << "Type a number associated to a saved contact !" << std::endl;
}

// SETTER FUNCTIONS

bool PhoneBook::setContact(int index)
{
    std::string input;
    Contact contact;

    std::cout << "Enter the first name: ";
    std::getline(std::cin, input);
    contact.setFirstName(input);

    std::cout << "Enter the last name: ";
    std::getline(std::cin, input);
    contact.setLastName(input);

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, input);
    contact.setNickname(input);

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, input);
    contact.setPhoneNumber(input);

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, input);
    contact.setDarkestSecret(input);

    if (contact.isContactValid() == false)
        return (true);
    this->mContacts[index] = contact; 
    return (false);  
}



// Constructor

PhoneBook::PhoneBook(void) 
{
    this->mOldest_one = 0;
}

PhoneBook::~PhoneBook(void) {}



