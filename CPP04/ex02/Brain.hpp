/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:16:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 14:32:23 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#define NB_OF_IDEAS 100

#include <iostream>

class Brain
{
public:
	// Constructors
	Brain();
	Brain(const Brain &copy);

	// Destructor
	~Brain();

	// Operators
	Brain &operator=(const Brain &assign);

	// Getters / Setters
	std::string getIdea(int index) const;

private:
	std::string ideas[NB_OF_IDEAS];
};

// Stream operators
std::ostream &operator<<(std::ostream &stream, const Brain &object);

#endif