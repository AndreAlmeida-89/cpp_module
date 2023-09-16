/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:31:36 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/11 21:31:34 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

class StringReplacer
{
private:
	static std::string replaceStr(const std::string str,
								  const std::string s1,
								  const std::string s2);

public:
	static bool readFile(const std::string fileName,
						 std::string &result);
};

std::string StringReplacer::replaceStr(const std::string str,
									   const std::string s1,
									   const std::string s2)
{

	return std::string();
}

bool StringReplacer::readFile(const std::string fileName,
							  std::string &result)
{
	std::string line;
	std::ifstream file(fileName);

	if (!file.is_open())
	{
		std::cerr << "(!) File can not be open." << std::endl;
		return (false);
	}
	while (getline(file, line))
		result += line + '\n';
	file.close();
	return (true);
}

int main(const int argc, const char **argv)
{
	if (argc != 4)
	{
		std::cerr << "(!) Invalid number of arguments" << std::endl;
		return (1);
	}
	std::string res;

	if (StringReplacer::readFile(argv[1], res))
		std::cout << res;
	return (0);
}