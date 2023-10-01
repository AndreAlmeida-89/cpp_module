/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:07:28 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/22 23:07:29 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors
Fixed::Fixed()
{
	_rawBits = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int i)
{
	this->_rawBits = i << _fracBits;
}

Fixed::Fixed(const float f)
{
	this->_rawBits = roundf(f * (1 << _fracBits));
}

// Destructor
Fixed::~Fixed()
{
}

// Operators
Fixed &Fixed::operator=(const Fixed &assign)
{
	_rawBits = assign.getRawBits();
	return *this;
}

// Comparison Operators
bool Fixed::operator>(const Fixed &rhs) const
{
	return _rawBits > rhs.getRawBits();
}

bool Fixed::operator<(const Fixed &rhs) const
{
	return _rawBits < rhs.getRawBits();
}

bool Fixed::operator>=(const Fixed &rhs) const
{
	return _rawBits >= rhs.getRawBits();
}

bool Fixed::operator<=(const Fixed &rhs) const
{
	return _rawBits <= rhs.getRawBits();
}

bool Fixed::operator==(const Fixed &rhs) const
{
	return _rawBits == rhs.getRawBits();
}

bool Fixed::operator!=(const Fixed &rhs) const
{
	return _rawBits != rhs.getRawBits();
}

// Arithmetic Operators
Fixed Fixed::operator+(const Fixed &rhs) const
{
	return Fixed(toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(const Fixed &rhs) const
{
	return Fixed(toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(const Fixed &rhs) const
{
	return Fixed(toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(const Fixed &rhs) const
{
	return Fixed(toFloat() / rhs.toFloat());
}

// Increment / Decrement Operators
Fixed &Fixed::operator++()
{
	_rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--()
{
	_rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
	os << fixed.toFloat();
	return (os);
}

// Getters / Setters

int Fixed::getRawBits() const
{
	return (_rawBits);
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

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return (a < b ? a : b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a < b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return (a > b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}