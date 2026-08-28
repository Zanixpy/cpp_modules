/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:55:38 by omawele           #+#    #+#             */
/*   Updated: 2026/08/28 16:58:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Array init ===" << std::endl;

    const int arraySize = 4;
    const AAnimal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i) 
    {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== makeSound() ===" << std::endl;
    for (int i = 0; i < arraySize; ++i) 
    {
        std::cout << "animals[" << i << "] type = " << animals[i]->getType() << " : ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== deep copy sur Dog ===" << std::endl;
    {
        Dog basic;
        basic.setIdea(0, "Manger");

        Dog copyDog(basic);
        Dog assignDog;
        assignDog = basic;
          
        copyDog.setIdea(0, "Dormir");
        copyDog.setIdea(100, "Yap");
        assignDog.setIdea(0, "Jouer");
 
        std::cout << "copyDog[0] idea : " << copyDog.getIdea(0)<< "\n";
        std::cout << "assignDog[0] idea : " << assignDog.getIdea(0)<< "\n";
        std::cout << "basic[0] idea : " << basic.getIdea(0)<< "\n";  
    }

    std::cout << "\n=== Free tab ===" << std::endl;
    for (int i = 0; i < arraySize; ++i)
        delete animals[i];
    return 0;
}
