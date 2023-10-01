/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:49:10 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/22 22:54:08 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

bool bsb(Point const a, Point const b, Point const c, Point const point)
{
	Fixed area = Point::triangleArea(a, b, c);
	Fixed area1 = Point::triangleArea(point, b, c);
	Fixed area2 = Point::triangleArea(a, point, c);
	Fixed area3 = Point::triangleArea(a, b, point);
	if (area == 0 || area1 == 0 || area2 == 0 || area3 == 0)
		return false;
	return (area == area1 + area2 + area3);
}