/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:31:36 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/09 22:21:16 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout
		<< "The memory address of the string variable is: " << &str << std::endl
		<< "The memory address held by stringPTR is: " << stringPTR << std::endl
		<< "The memory address held by stringREF is: " << &stringREF << std::endl
		<< "The value of the string variable is: " << str << std::endl
		<< "The value pointed to by stringPTR is: " << *stringPTR << std::endl
		<< "The value pointed to by stringREF is: " << stringREF << std::endl;

	return (0);
}