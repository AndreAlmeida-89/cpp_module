/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:20:43 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 15:24:02 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
	this->operator=(copy);
}

// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}

// Operators
Brain &Brain::operator=(const Brain &assign)
{
	for (int i = 0; i < NB_OF_IDEAS; i++)
		ideas[i] = assign.getIdea(i);
	return *this;
}

// Getters
std::string Brain::getIdea(int i) const
{
	return ideas[i];
}