/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:55:38 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 06:49:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Construction tableau d'animaux ===" << std::endl;

    const int arraySize = 4;
    const Animal* animals[arraySize];

    for (int i = 0; i < arraySize; ++i) 
    {
        if (i < arraySize / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== makeSound() sur tout le tableau ===" << std::endl;
    for (int i = 0; i < arraySize; ++i) {
        std::cout << "animals[" << i << "] type = " << animals[i]->getType() << " : ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Test de deep copy sur Dog ===" << std::endl;
    {
        Dog basic;

        basic.setIdea(0, "Manger");

        std::cout << "\n--- Copie par constructeur ---" << std::endl;
        Dog copyDog(basic);

        std::cout << "\n--- Copie par opérateur d’affectation ---" << std::endl;
        Dog assignDog;
        assignDog = basic;

        
        copyDog.setIdea(0, "Dormir");
        assignDog.setIdea(0, "Jouer");
 
        std::cout << "copyDog[0] idea : " << copyDog.getIdea(0)<< "\n";
        std::cout << "assignDog[0] idea : " << assignDog.getIdea(0)<< "\n";
        std::cout << "basic[0] idea : " << basic.getIdea(0)<< "\n";
        
    }

    std::cout << "\n=== Destruction du tableau d'animaux ===" << std::endl;
    for (int i = 0; i < arraySize; ++i)
        delete animals[i];

    std::cout << "\n=== Test simple de création / destruction ===" << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        j->makeSound();
        i->makeSound();

        delete j; 
        delete i;
    }

    std::cout << "\n=== Fin du programme (vérifie les leaks avec valgrind / leaks) ===" << std::endl;
    return 0;
}
