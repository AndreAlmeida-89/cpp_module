/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:32:03 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 00:21:39 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string	ft_resize(std::string str, size_t len)
{
	std::string cpy = str;

	if (str.length() > len)
	{
		cpy.resize(len - 1);
		cpy.append(".");
	}
	else
		while (cpy.length() < len)
			cpy.insert(0, " ");
	return (cpy);
}