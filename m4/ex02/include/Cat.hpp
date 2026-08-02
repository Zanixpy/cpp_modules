/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 09:27:00 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 07:14:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
    private:
        Brain* m_brain;
    public:
        Cat();
        Cat( const Cat& other );
        Cat& operator=( const Cat& other );
        ~Cat();
        void setIdea(int index, std::string const& idea);
        std::string const& getIdea(int index) const;
        virtual void makeSound() const;
};


#endif