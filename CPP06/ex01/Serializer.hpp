#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include "Data.hpp"

typedef unsigned long int uintptr_t;

class Serializer
{
public:
	// Destructor
	~Serializer();

	// Member functions
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);

private:
	// Constructors
	Serializer();
	Serializer(const Serializer &copy);

	// Operators
	Serializer &operator=(const Serializer &assign);
};

#endif