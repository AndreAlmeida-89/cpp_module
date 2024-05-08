#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
public:
	// Constructors
	Character();
	Character(const Character &copy);
	Character(std::string name);

	// Destructor
	~Character();

	// Operators
	Character &operator=(const Character &assign);

	// Member functions
	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	std::string _name;
	AMateria *_inventory[4];
	int _count;
};

#endif