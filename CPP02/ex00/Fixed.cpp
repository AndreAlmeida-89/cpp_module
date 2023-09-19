#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_rawBits = 0;
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed(int rawBits)
{
	this->_rawBits = rawBits;
	std::cout << "\e[0;33mFields Constructor called of Fixed\e[0m" << std::endl;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	std::cout << "\e[0;32mCopy Assignment Operator called of Fixed\e[0m" << std::endl;
	_rawBits = assign.getRawBits();
	return *this;
}

// Getters / Setters

int Fixed::getRawBits() const
{
	std::cout << "\e[1;34mgetRawBits Member Function called of Fixed\e[0m" << std::endl;
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "\e[1;34msetRawBits Member Function called of Fixed\e[0m" << std::endl;
	_rawBits = raw;
}
