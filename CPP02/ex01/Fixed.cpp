#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int i)
{
	std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m" << std::endl;
	this->_rawBits = i << _fracBits;
}

Fixed::Fixed(const float f)
{
	std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m" << std::endl;
	this->_rawBits = roundf(f * (1 << _fracBits));
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

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

// Getters / Setters

int Fixed::getRawBits() const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

// Member Functions
float Fixed::toFloat(void) const
{
	return (float)_rawBits / (1 << _fracBits);
}

int Fixed::toInt(void) const
{
	return _rawBits / (1 << _fracBits);
}