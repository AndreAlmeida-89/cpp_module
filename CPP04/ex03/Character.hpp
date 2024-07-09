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
	AMateria *getMateria(size_t index) const;
	AMateria *getUnusedMateria(size_t index) const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	static const size_t _inventoryCapacity = 4;
	static const size_t _unequipedInventoryCapacity = 2 << 10;

	std::string _name;
	AMateria *_inventory[_inventoryCapacity];
	AMateria *_unequipedInventory[_unequipedInventoryCapacity];
	size_t _inventoryCount;
	size_t _unequipedInventoryCount;
};

#endif