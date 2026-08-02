/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:20:43 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 06:30:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    private:
        Brain* m_brain;
    public:
        Dog();
        Dog( const Dog& other );
        Dog& operator=( const Dog& other );
        ~Dog();
        void setIdea(int index, std::string const& idea);
        std::string const& getIdea(int index) const;
        virtual void makeSound() const;
};


#endif