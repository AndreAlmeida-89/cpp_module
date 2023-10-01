/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 23:07:45 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/22 23:07:46 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <string>
#include "Fixed.hpp"

class Point
{
public:
	// Constructors
	Point();
	Point(const Point &copy);
	Point(const Fixed x, const Fixed y);

	// Destructor
	~Point();

	// Operators
	Point &operator=(const Point &assign);

	// Getters / Setters
	Fixed getX() const;
	Fixed getY() const;

	// Member Functions
	static Fixed triangleArea(Point const a, Point const b, Point const c);

private:
	// Attributes
	Fixed _x;
	Fixed _y;
};

// << Operator overload
std::ostream &operator<<(std::ostream &os, const Point &point);

//Binary space partitioning
bool bsb(Point const a, Point const b, Point const c, Point const point);

#endif