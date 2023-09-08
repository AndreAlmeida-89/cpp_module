/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 01:16:51 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/02 01:16:52 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

std::string ft_str_to_upper(const char *str)
{
	std::string	initial;
	std::string	result;
	size_t		len;

	initial = str;
	len = initial.length();
	for (size_t i = 0; i < len; i++)
		result += std::toupper(str[i]);
	return (result);
}

int main(int const argc, const char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
		for (int i = 1; i < argc; i++)
		{
			std::cout << ft_str_to_upper(argv[i]);
			if (i == argc - 1)
				std::cout << std::endl;
		}
	return 0;
}
