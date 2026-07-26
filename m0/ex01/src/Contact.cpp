/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 18:26:47 by omawele           #+#    #+#             */
/*   Updated: 2026/07/26 17:54:59 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// STATIC FUNCTIONS

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

// CONSTRUCTOR

Contact::Contact(void){}

Contact::~Contact(void)
{
    this->clearContact();
}

// SETTER

void Contact::setFirstName(std::string input)
{
    this->mfirst_name = input;
}

void Contact::setLastName(std::string input)
{
    this->mlast_name = input;
}

void Contact::setNickname(std::string input)
{
    this->mnickname = input;
}

void Contact::setPhoneNumber(std::string input)
{
    this->mphone_number = input;
}

void Contact::setDarkestSecret(std::string input)
{
    this->mdarkest_secret = input;
}

// GETTER

std::string Contact::getFirstName(void)
{
    return this->mfirst_name;
}

std::string Contact::getLastName(void)
{
    return this->mlast_name;
}

std::string Contact::getNickname(void)
{
    return this->mnickname;
}

std::string Contact::getPhoneNumber(void)
{
    return this->mphone_number;
}

std::string Contact::getDarkestSecret(void)
{
    return this->mdarkest_secret;
}

// UTILS

void Contact::clearContact(void)
{
    this->mfirst_name.clear();
    this->mlast_name.clear();
    this->mnickname.clear();
    this->mphone_number.clear();
    this->mdarkest_secret.clear();
}

bool Contact::isContactValid(void)
{
    std::string str;
    
    str = this->getFirstName();
    if (checkInput(str))
        return false;
    str = this->getLastName();
    if (checkInput(str))
        return false;
    str = this->getNickname();
    if (checkInput(str))
        return false;
    str = this->getPhoneNumber();
    if (checkInput(str))
        return false;
    str = this->getDarkestSecret();
    if (checkInput(str))
        return false;
    return true;
}

