/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:23:23 by andde-so          #+#    #+#             */
/*   Updated: 2023/11/25 23:28:03 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
public:
	// Constructors
	Cat();
	Cat(const Cat &copy);

	// Destructor
	~Cat();

	// Operators
	Cat &operator=(const Cat &assign);

	// Member functions
	void makeSound() const;

private:
	Brain *_brain;
};

#endif