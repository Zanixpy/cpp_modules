/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:31:05 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:45:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice( Ice const & other);
        Ice& operator=( Ice const & other);
        ~Ice();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};




#endif