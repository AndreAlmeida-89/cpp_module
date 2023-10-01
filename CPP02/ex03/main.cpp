/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:49:08 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/22 23:02:33 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	{
		std::cout << "Test bsb, given a point inside the triangle" << std::endl;
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point p(1, 1);
		std::cout << "Point a: " << a << std::endl;
		std::cout << "Point b: " << b << std::endl;
		std::cout << "Point c: " << c << std::endl;
		std::cout << "Point p: " << p << std::endl;
		std::cout << "Is point p inside the triangle? " << bsb(a, b, c, p) << std::endl;
	}

	{
		std::cout << "Test bsb, given a point on the edge of the triangle" << std::endl;
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point p(0, 5);
		std::cout << "Point a: " << a << std::endl;
		std::cout << "Point b: " << b << std::endl;
		std::cout << "Point c: " << c << std::endl;
		std::cout << "Point p: " << p << std::endl;
		std::cout << "Is point p inside the triangle? " << bsb(a, b, c, p) << std::endl;
	}

	{
		std::cout << "Test bsb, given a point on a vertex of a triangle" << std::endl;
		Point a(0, 0);
		Point b(10, 0);
		Point c(0, 30);
		Point p(0, 30);
		std::cout << "Point a: " << a << std::endl;
		std::cout << "Point b: " << b << std::endl;
		std::cout << "Point c: " << c << std::endl;
		std::cout << "Point p: " << p << std::endl;
		std::cout << "Is point p inside the triangle? " << bsb(a, b, c, p) << std::endl;
	}

	return 0;
}
