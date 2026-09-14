/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:26:23 by omawele           #+#    #+#             */
/*   Updated: 2026/09/02 09:43:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

int main()
{
    std::cout << "===Instance of a correct bureaucrat===\n";
    Bureaucrat test("Zan", 1);
    Bureaucrat other(test);
    Bureaucrat yo("None", 4);

    yo = test;
        
    std::cout << "Name " << test.getName() << "\n";
    std::cout << "Grade " << test.getGrade() << "\n";
    
    std::cout << "Name " << other.getName() << "\n";
    std::cout << "Grade " << other.getGrade() << "\n";
    
    std::cout << "Name " << yo.getName() << "\n";
    std::cout << "Grade " << yo.getGrade() << "\n";

    std::cout << "\n===Operator << overload===\n";
    std::cout << test;
    std::cout << yo;

    std::cout << "\n===Increment/Decrement===\n";
    test.decrementGrade();
    std::cout << "After decrementing Zan, grade " << test.getGrade() << "\n";
    test.incrementGrade();
    std::cout << "After incrementing Zan, grade " << test.getGrade() << "\n";

    std::cout << "\n===Instance of a wrong bureaucrat===\n";
    try 
    {
        Bureaucrat high("Dummy", 0);
    } 
    catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cout << e.what();        
    }
    try 
    {
        Bureaucrat low("Trai", 151);
    } 
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what();
    }
    std::cout << "\n===Increment/Decrement out of range===\n";
    try 
    {
        test.incrementGrade();
    } 
    catch (Bureaucrat::GradeTooHighException &e) 
    {
        std::cout << e.what();
    }
    try
    {
        Bureaucrat outof("Lomqe", 150);
        outof.decrementGrade();
    }
    catch (Bureaucrat::GradeTooLowException &e)
    {
        std::cout << e.what();
    }
    return 0;
}