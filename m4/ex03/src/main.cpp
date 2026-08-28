/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:32:14 by omawele           #+#    #+#             */
/*   Updated: 2026/08/28 18:04:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp – ex03

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "=== create materiaSource ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== create character ===" << std::endl;
    ICharacter* me = new Character("Zan");

    std::cout << "\n=== createMateria and equip ===" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== create other character ===" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "\n=== use of materias ===" << std::endl;
    me->use(0, *bob);   
    me->use(1, *bob);   

    std::cout << "\n=== Tests supplémentaires ===" << std::endl;

    std::cout << "use an empty slot" << std::endl;
    me->use(2, *bob);   
    me->use(42, *bob); 

    std::cout << "unequip " << std::endl;
    AMateria* dropped = src->createMateria("ice");
    me->equip(dropped);
    me->use(2, *bob);
    me->unequip(2);
    delete dropped;

    std::cout << "\n=== Free ===" << std::endl;
    delete bob;
    delete me;
    delete src;

    return 0;
}
