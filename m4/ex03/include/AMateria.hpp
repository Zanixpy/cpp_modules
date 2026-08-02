/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 07:29:14 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 06:47:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <iostream>


class ICharacter;

class AMateria
{
    protected:
        std::string type;
    public:
        AMateria( std::string const & type );
        AMateria( AMateria const & other );
        AMateria& operator=( AMateria const & other );
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};


#endif