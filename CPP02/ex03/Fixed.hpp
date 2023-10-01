/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:07:33 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/22 23:07:34 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	// Assignment Operator
	Fixed &operator=(const Fixed &assign);
	// Comparison Operators
	bool operator>(const Fixed &rhs) const;
	bool operator<(const Fixed &rhs) const;
	bool operator>=(const Fixed &rhs) const;
	bool operator<=(const Fixed &rhs) const;
	bool operator==(const Fixed &rhs) const;
	bool operator!=(const Fixed &rhs) const;
	// Arithmetic Operators
	Fixed operator+(const Fixed &rhs) const;
	Fixed operator-(const Fixed &rhs) const;
	Fixed operator*(const Fixed &rhs) const;
	Fixed operator/(const Fixed &rhs) const;
	// Increment / Decrement Operators
	Fixed &operator++();
	Fixed operator++(int);
	Fixed &operator--();
	Fixed operator--(int);

	// Getters / Setters
	int getRawBits() const;
	void setRawBits(int const raw);

	// Member Functions
	float toFloat(void) const;
	int toInt(void) const;
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

private:
	int _rawBits;
	static const int _fracBits = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &fixed);

#endif