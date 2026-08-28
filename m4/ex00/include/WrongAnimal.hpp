/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:56:18 by omawele           #+#    #+#             */
/*   Updated: 2026/08/27 14:58:08 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected:
        std::string m_type;
    public:
        WrongAnimal();
        WrongAnimal( const std::string &type );
        WrongAnimal( const WrongAnimal& other);
        WrongAnimal& operator=( const WrongAnimal& other);
        ~WrongAnimal();
        const std::string& getType() const;
        void setType(const std::string type);
        virtual void makeSound() const;
};


#endif