/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:32:14 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 07:53:13 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp – ex03

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
    std::cout << "=== Création de la source de Materia ===" << std::endl;
    IMateriaSource* src = new MateriaSource();

    std::cout << "\n=== learnMateria(Ice, Cure) ===" << std::endl;
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    std::cout << "\n=== Création d'un personnage 'me' ===" << std::endl;
    ICharacter* me = new Character("me");

    std::cout << "\n=== createMateria(\"ice\") puis equip ===" << std::endl;
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);

    std::cout << "\n=== createMateria(\"cure\") puis equip ===" << std::endl;
    tmp = src->createMateria("cure");
    me->equip(tmp);

    std::cout << "\n=== Création d'un autre personnage 'bob' ===" << std::endl;
    ICharacter* bob = new Character("bob");

    std::cout << "\n=== Utilisation des Materias sur bob ===" << std::endl;
    me->use(0, *bob);   
    me->use(1, *bob);   

    std::cout << "\n=== Tests supplémentaires ===" << std::endl;

    std::cout << "- use sur un slot vide (ne doit rien faire / pas de crash)" << std::endl;
    me->use(2, *bob);   
    me->use(42, *bob); 

    std::cout << "- unequip sans delete (vérifie que ça ne crash pas)" << std::endl;
    AMateria* dropped = src->createMateria("ice");
    me->equip(dropped);
    me->use(2, *bob);
    me->unequip(2);
    delete dropped;

    std::cout << "\n=== Test de copie de Character (deep copy) ===" << std::endl;
    {
        Character original("original");
        AMateria* m1 = src->createMateria("ice");
        AMateria* m2 = src->createMateria("cure");
        original.equip(m1);
        original.equip(m2);

        std::cout << "\n--- Construction par copie ---" << std::endl;
        Character copy(original);
        copy.use(0, *bob);
        copy.use(1, *bob);

        std::cout << "\n--- Affectation ---" << std::endl;
        Character assigned("assigned");
        assigned = original;
        assigned.use(0, *bob);
        assigned.use(1, *bob);
    }

    std::cout << "\n=== Nettoyage ===" << std::endl;
    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== Fin du main ex03 (check leaks) ===" << std::endl;
    return 0;
}
