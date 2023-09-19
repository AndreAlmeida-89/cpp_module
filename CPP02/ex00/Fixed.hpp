#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(int rawBits);

	// Destructor
	~Fixed();

	// Operators
	Fixed &operator=(const Fixed &assign);

	// Getters / Setters
	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int _rawBits;
	static const int _fracBits = 8;
};

#endif