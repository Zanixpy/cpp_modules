/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:04:45 by omawele           #+#    #+#             */
/*   Updated: 2026/08/28 17:04:09 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain( const Brain& other )
{
    std::cout << "Brain copy constructor called\n";
    *this = other;
}

Brain& Brain::operator=( const Brain& other )
{
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}

void Brain::setIdea(int index, std::string const& idea)
{
    if (index < 0 || index > 99)
        return;
    this->ideas[index] = idea;
}

std::string const Brain::getIdea(int index) const
{  
    if (index < 0 || index > 99)
        return std::string();
    if (this->ideas[index].empty())
        return std::string();
    return this->ideas[index];
}
