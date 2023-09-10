

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:33:02 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/04 11:33:08 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cerr
		<< "A zombie has been created"
		<< std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cerr
		<< name
		<< ": has been created"
		<< std::endl;
}

Zombie::~Zombie()
{
	std::cerr
		<< name
		<< ": has died"
		<< std::endl;
}

void Zombie::announce(void)
{
	std::cout
		<< name
		<< ": BraiiiiiiinnnzzzZ..."
		<< std::endl;
}

std::string Zombie::getName() const
{
	return (name);
}

void Zombie::setName(std::string name)
{
	this->name = name;
}