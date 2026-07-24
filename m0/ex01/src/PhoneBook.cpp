/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:26:59 by omawele           #+#    #+#             */
/*   Updated: 2026/07/24 12:02:29 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// UTILS

static bool checkInput(std::string &input)
{
    if (input.empty())
        return (true);
    for (size_t i = 0, len = input.length(); i < len; i++)
    {
        if (!isspace(input[i]))
            return (false);
    }
    return (false);
}

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

bool PhoneBook::isEmpty(int index)
{
    if (checkInput(this->mContacts[index].first_name) or checkInput(this->mContacts[index].last_name) or
        checkInput(this->mContacts[index].nickname) or checkInput(this->mContacts[index].phone_number) or
        checkInput(this->mContacts[index].darkest_secret))
            return (true);
    return (false);
}

int PhoneBook::displayContacts(void)
{ 
    if (this->isEmpty(0))
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
        if (this->isEmpty(index))
            return (0);
        printCharN(9,' ');
        std::cout << index << '|';
        print_str(this->mContacts[index].first_name, 0, 0);
        print_str(this->mContacts[index].last_name, 0, 0);
        print_str(this->mContacts[index].nickname, 0, 1);    
        std::cout << std::endl;
    }   
    return (0);
}

void PhoneBook::displayContact(std::string &input)
{
    int nb = atoi(input.c_str());
    if (this->isEmpty(nb))
    {
        std::cout << "Type a number associated to a saved contact !" << std::endl;
        return;
    }
    std::cout << std::endl << "Contact " << nb << std::endl;
    std::cout << "First name: " << this->mContacts[nb].first_name << std::endl;
    std::cout << "Last name: " << this->mContacts[nb].last_name << std::endl;
    std::cout << "Nickname: " << this->mContacts[nb].nickname << std::endl;
    std::cout << "Phone number: " << this->mContacts[nb].phone_number << std::endl;
    std::cout << "Darkest secret: " << this->mContacts[nb].darkest_secret << std::endl << std::endl;
}

int PhoneBook::getSlotIndex(void)
{
    for (int index = 0; index < 8; index++)
    {
        if (this->isEmpty(index))
            return (index);
    }
    return (0);
}

void PhoneBook::resetContact(int index)
{
    this->mContacts[index].first_name.clear();
    this->mContacts[index].last_name.clear();
    this->mContacts[index].nickname.clear();
    this->mContacts[index].phone_number.clear();
    this->mContacts[index].darkest_secret.clear();
}


// MAIN FUNCTION

void PhoneBook::add(void)
{
    int index = this->getSlotIndex();
    
    if (this->setContact(index))
    {
        this->resetContact(index);
        std::cout << "Error: can't have empty fields." << std::endl;     
    }
    else
        std::cout << "New contact created !" << std::endl;
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

int PhoneBook::setContact(int index)
{
    std::string input;

    std::cout << "Enter the first name: ";
    std::getline(std::cin, input);
    this->mContacts[index].first_name = input;

    std::cout << "Enter the last name: ";
    std::getline(std::cin, input);
    this->mContacts[index].last_name = input;

    std::cout << "Enter the nickname: ";
    std::getline(std::cin, input);
    this->mContacts[index].nickname = input;

    std::cout << "Enter the phone number: ";
    std::getline(std::cin, input);
    this->mContacts[index].phone_number = input;

    std::cout << "Enter the darkest secret: ";
    std::getline(std::cin, input);
    this->mContacts[index].darkest_secret = input;

    if (this->isEmpty(index))
        return (1);
    return (0);  
}



