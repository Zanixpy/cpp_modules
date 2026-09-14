/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 17:26:23 by omawele           #+#    #+#             */
/*   Updated: 2026/09/02 10:32:04 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat a("Zan", 1);
    Form b("Document", 20, 20);
    Form c(b);
    Form d("Essay", 68, 92);

    d = c;

    std::cout << "\n===Operator << overload===\n";
    std::cout << b;
    std::cout << c;
    std::cout << d;
    
    std::cout << "\n===Sign Form===\n";
    a.signForm(b);

    std::cout << "\n===Instance of a wrong Form===\n";
    try 
    {
        Form("Essay 2", 0, 29);
    } 
    catch (Form::GradeTooHighException &e) 
    {
        std::cout << e.what();        
    }
    try 
    {
        Form("Essay 2", 81, 281);
    } 
    catch (Form::GradeTooLowException &e)
    {
        std::cout << e.what();
    }
    std::cout << "\n===Sign Form wit low bureaucrat===\n";
    try 
    {
        Bureaucrat e("Dummy", 90);
        e.signForm(b);
    } 
    catch (Form::GradeTooLowException &e) 
    {
        std::cout << e.what();
    }
    return 0;
}