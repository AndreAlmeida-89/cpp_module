/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 00:19:01 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 15:40:40 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(const int argc, const char **argv)
{
	Harl h = Harl();

	if (argc != 2)
	{
		std::cerr << "(!) Invalid argment number" << std::endl;
		return (1);
	}

	h.complain(argv[1]);
	return (0);
}
