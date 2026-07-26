/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:23:29 by omawele           #+#    #+#             */
/*   Updated: 2026/07/26 17:34:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
    PhoneBook phone_book;
    std::string input;

    std::cout << "Enter a command: ";
    while (std::getline(std::cin, input))
    {
        if (input == "ADD")
            phone_book.add();
        else if (input == "SEARCH")
            phone_book.search();
        else if (input == "EXIT")
            break;
        std::cout << "Enter a command: ";
    } 
    return (0);
}
