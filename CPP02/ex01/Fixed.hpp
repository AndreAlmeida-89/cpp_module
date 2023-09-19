#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
public:
	// Constructors
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int rawBits);
	Fixed(const float rawBits);

	// Destructor
	~Fixed();

	// Operators
	Fixed &operator=(const Fixed &assign);

	// Getters / Setters
	int getRawBits() const;
	void setRawBits(int const raw);

	//Member Functions
	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int _rawBits;
	static const int _fracBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif