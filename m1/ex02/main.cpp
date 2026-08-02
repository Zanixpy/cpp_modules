/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 09:28:32 by omawele           #+#    #+#             */
/*   Updated: 2026/07/27 09:33:17 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "str (memory address) : " << &str << '\n';
    std::cout << "stringPTR (memory address) : " << stringPTR << '\n';
    std::cout << "stringREF (memory address) : " << &stringREF << '\n';

    std::cout << "str (value) : " << str << '\n';
    std::cout << "stringPTR (value) : " << *stringPTR << '\n';
    std::cout << "stringREF (value) : " << stringREF << '\n';

    return 0;
}