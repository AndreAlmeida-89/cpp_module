/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoi.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:48:00 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/09 23:38:06 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool ft_stoi(std::string &str, int *n)
{
	int i;
	int sign;

	*n = 0;
	sign = 1;
	i = 0;
	while (std::isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (false);
		*n = (*n * 10) + (str[i] - '0');
		i++;
	}
	*n *= sign;
	return (true);
}