/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/14 13:28:40 by omawele           #+#    #+#             */
/*   Updated: 2026/09/21 09:27:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_HPP
# define CHECKER_HPP

#include <iostream>

bool isCharLiteral(std::string const &s);
bool isIntLiteral(std::string const &s);
bool isFloatLiteral(std::string const &s);
bool isDoubleLiteral(std::string const &s);
bool isPseudoFloat(std::string const &s);
bool isPseudoDouble(std::string const &s);

#endif