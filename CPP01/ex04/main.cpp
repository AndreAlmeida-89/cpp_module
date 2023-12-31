/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:31:36 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 13:10:17 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"

int main(const int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "(!) Invalid number of arguments" << std::endl;
		return (1);
	}
	if (!StringReplacer::replaceWordsInFile(std::string(argv[1]),
										    std::string(argv[2]),
										    std::string(argv[3])))
		return (2);
	return (0);
}
