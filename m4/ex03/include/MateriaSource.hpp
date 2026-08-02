/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 10:13:41 by omawele           #+#    #+#             */
/*   Updated: 2026/07/31 05:59:30 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        AMateria*   m_storage[4];
    public:
        MateriaSource();
        MateriaSource( MateriaSource const & other );
        MateriaSource& operator=( MateriaSource const & other );
        ~MateriaSource();
        virtual void learnMateria(AMateria* m);
        virtual AMateria* createMateria(std::string const & type);
};




#endif