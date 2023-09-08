/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 23:32:03 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/08 16:46:53 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

std::string ft_set_width(std::string str, size_t width)
{
	if (width < 1)
		return (str);
	if (str.length() > width)
		return (str.substr(0, width - 1) + '.');
	return (std::string(width - str.length(), ' ') + str);
}