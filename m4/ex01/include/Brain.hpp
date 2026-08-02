/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:02:40 by omawele           #+#    #+#             */
/*   Updated: 2026/07/30 06:29:04 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain( const Brain& other );
        Brain& operator=( const Brain& other );
        ~Brain();
        void setIdea(int index, std::string const& idea);
        std::string const& getIdea(int index) const;

 
};





#endif