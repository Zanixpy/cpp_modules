/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:56:18 by omawele           #+#    #+#             */
/*   Updated: 2026/07/29 12:52:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
    protected:
        std::string m_type;
    public:
        Animal();
        Animal( const std::string type );
        Animal( const Animal& other);
        Animal& operator=( const Animal& other);
        ~Animal();
        const std::string& getType() const;
        void setType(const std::string type);
        virtual void makeSound() const;
};


#endif