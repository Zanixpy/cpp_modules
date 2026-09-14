/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:26:23 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 10:22:32 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Intern.hpp"

int main() 
{
    Intern      someRandomIntern;
    AForm*      form;

    std::cout << "=== Test 1 : robotomy request ===" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << std::endl << "=== Test 2 : shrubbery creation ===" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "home");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << std::endl << "=== Test 3 : presidential pardon ===" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Zaphod");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    std::cout << std::endl << "=== Test 4 : mauvais nom de formulaire ===" << std::endl;
    form = someRandomIntern.makeForm("wrong form name", "TargetInutile");
    if (form) {
        std::cout << *form << std::endl;
        delete form;
    }

    return 0;
}
