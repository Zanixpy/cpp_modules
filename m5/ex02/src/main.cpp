/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:26:23 by omawele           #+#    #+#             */
/*   Updated: 2026/09/14 10:17:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp

#include "../include/Bureaucrat.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

static void sep(std::string const &title) {
    std::cout << "\n========== " << title << " ==========\n" << std::endl;
}

int main() 
{    
    sep("FORM CONSTRUCTION");
    try {
        ShrubberyCreationForm s("home");
        RobotomyRequestForm   r("Bender");
        PresidentialPardonForm p("Arthur Dent");

        std::cout << s << std::endl;
        std::cout << r << std::endl;
        std::cout << p << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    sep("SHRUBBERY FORM");
    try {
        Bureaucrat ok("OkShrub", 100);    
        Bureaucrat exec("ExecShrub", 130);
        ShrubberyCreationForm form("garden");

        std::cout << form << std::endl;

        ok.signForm(form);
        std::cout << form << std::endl;

        exec.executeForm(form);
    }
    catch (std::exception &e) {
        std::cout << "exception in Shrubbery test: " << e.what() << std::endl;
    }
    try {
        Bureaucrat low("LowShrub", 150);
        ShrubberyCreationForm form("garden");

        low.signForm(form);
        std::cout << form << std::endl;

        low.executeForm(form);
    }
    catch (std::exception &e) {
        std::cout << "exception in Shrubbery test: " << e.what() << std::endl;
    }

    sep("ROBOTOMY FORM");
    try {
        Bureaucrat signer("SignerRobot", 50);
        Bureaucrat execGood("ExecRobot", 40);
        RobotomyRequestForm form("Bender");

        signer.signForm(form);    

        for (int i = 0; i < 5; ++i) {
            execGood.executeForm(form);
        }
    }
    catch (std::exception &e) {
        std::cout << "exception in Robotomy test: " << e.what() << std::endl;
    }
    try {
        Bureaucrat execBad("ExecBad", 100); 
        RobotomyRequestForm form("Bender");

        execBad.executeForm(form);

        for (int i = 0; i < 5; ++i) {
            execBad.executeForm(form);
        }
    }
    catch (std::exception &e) {
        std::cout << "exception in Robotomy test: " << e.what() << std::endl;
    }

    sep("PRESIDENTIAL PARDON FORM");
    try {
        Bureaucrat signer("SignerPres", 20); 
        Bureaucrat execOk("ExecPres", 3);
        PresidentialPardonForm form("Ford Prefect");

        signer.signForm(form);
        execOk.executeForm(form);
    }
    catch (std::exception &e) {
        std::cout << "exception in Presidential test: " << e.what() << std::endl;
    }
    try {
        Bureaucrat weak("Weak", 50);     
        PresidentialPardonForm form("Ford Prefect");

        weak.signForm(form);    
        weak.executeForm(form); 
    }
    catch (std::exception &e) {
        std::cout << "exception in Presidential test: " << e.what() << std::endl;
    }

    sep("POLYMORPHISM VIA AForm*");
    try {
        Bureaucrat boss("Boss", 1);

        AForm *forms[3];
        forms[0] = new ShrubberyCreationForm("poly_home");
        forms[1] = new RobotomyRequestForm("poly_Bender");
        forms[2] = new PresidentialPardonForm("poly_Arthur");

        for (int i = 0; i < 3; ++i) {
            boss.signForm(*forms[i]);
        }

        for (int i = 0; i < 3; ++i) {
            boss.executeForm(*forms[i]);
        }

        for (int i = 0; i < 3; ++i) {
            delete forms[i];
        }
    }
    catch (std::exception &e) {
        std::cout << "exception in polymorphism test: " << e.what() << std::endl;
    }
    return 0;
}
