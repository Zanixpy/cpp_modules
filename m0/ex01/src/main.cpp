/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 09:23:29 by omawele           #+#    #+#             */
/*   Updated: 2026/08/02 12:28:33 by omawele          ###   ########.fr       */
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
        if (std::cin.eof() == 1)
            return (1);
        std::cout << "Enter a command: ";
    }
    if (std::cin.eof() == 1)
    {
        std::cout << '\n';
        return (1);
    }
    return (0);
}
