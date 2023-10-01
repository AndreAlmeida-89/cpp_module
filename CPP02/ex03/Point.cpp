/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:07:42 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/22 23:07:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructors
Point::Point()
{
	_x = 0;
	_y = 0;
}

Point::Point(const Point &copy)
{
	_x = copy.getX();
	_y = copy.getY();
}

Point::Point(const Fixed x, const Fixed y)
{
	_x = x;
	_y = y;
}

// Destructor
Point::~Point()
{
}

// Operators
Point &Point::operator=(const Point &assign)
{
	_x = assign.getX();
	_y = assign.getY();
	return *this;
}

std::ostream &operator<<(std::ostream &os, const Point &point)
{
	os << "Point(" << point.getX() << ", " << point.getY() << ")";
	return os;
}

// Getters / Setters
Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

// Member Functions
Fixed Point::triangleArea(Point const a, Point const b, Point const c)
{
	return (a.getX() * (b.getY() - c.getY()) +
			b.getX() * (c.getY() - a.getY()) +
			c.getX() * (a.getY() - b.getY())) /
		   2;
}