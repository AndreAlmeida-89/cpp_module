/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:32:03 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/01 20:19:39 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string ft_set_width(std::string str, size_t width)
{
	std::string cpy = str;

	if (str.length() > width)
	{
		cpy.resize(width - 1);
		cpy.append(".");
	}
	else
		while (cpy.length() < width)
			cpy.insert(0, " ");
	return (cpy);
}