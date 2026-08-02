/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:29:51 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:44:55 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "Character.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure( Cure const & other);
        Cure& operator=( Cure const & other);
        ~Cure();
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif