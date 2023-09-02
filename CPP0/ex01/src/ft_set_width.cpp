/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:32:03 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/01 23:39:24 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string ft_set_width(std::string str, size_t width)
{
	if (str.length() > width)
		return (str.substr(0, 9) + '.');
	return (std::string(width - str.length(), ' ') + str);
}