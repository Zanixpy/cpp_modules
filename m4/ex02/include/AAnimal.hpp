/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 08:56:18 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 07:14:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

#include <iostream>

class AAnimal
{
    protected:
        std::string m_type;
    public:
        AAnimal();
        AAnimal( const std::string type );
        AAnimal( const AAnimal& other);
        AAnimal& operator=( const AAnimal& other);
        virtual ~AAnimal();
        const std::string& getType() const;
        void setType(const std::string type);
        virtual void makeSound() const = 0;
};


#endif