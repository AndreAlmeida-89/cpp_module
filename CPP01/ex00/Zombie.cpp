

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
}

Zombie::Zombie(std::string name)
{
	this->name = name;
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

Zombie &Zombie::operator=(const Zombie &rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.getName();
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &stream, const Zombie &zombie)
{
	stream << zombie.getName();
	return (stream);
}
