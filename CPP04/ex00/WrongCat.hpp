/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:23:23 by andde-so          #+#    #+#             */
/*   Updated: 2023/10/21 11:51:59 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	// Constructors
	WrongCat();
	WrongCat(const WrongCat &copy);

	// Destructor
	~WrongCat();

	// Operators
	WrongCat &operator=(const WrongCat &assign);

	// Member functions
	void makeSound() const;

private:
};

#endif