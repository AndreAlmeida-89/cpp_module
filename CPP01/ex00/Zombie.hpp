/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:36:40 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/04 12:32:31 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>

class Zombie
{
private:
	std::string name;

public:
	Zombie();
	Zombie(std::string name);
	Zombie(const Zombie &zombie);
	Zombie &operator=(const Zombie &rhs);
	~Zombie();

	void announce(void);
	std::string getName() const;
};

std::ostream &operator<<(std::ostream &stream, const Zombie &zombie);
Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif