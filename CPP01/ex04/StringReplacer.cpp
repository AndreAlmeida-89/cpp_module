/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:45:14 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 13:11:38 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "StringReplacer.hpp"

bool StringReplacer::_openFiles(const std::string &fileName,
								std::ifstream &inFile,
								std::ofstream &outFile)
{
	inFile.open(fileName.c_str());
	if (!inFile.is_open())
	{
		std::cerr << "(!) File" << fileName << " can not be open." << std::endl;
		return (false);
	}
	outFile.open((fileName + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cerr << "(!) File" << fileName << ".replace can not be open." << std::endl;
		inFile.close();
		return (false);
	}
	return (true);
}

bool StringReplacer::replaceWordsInFile(const std::string &fileName,
							  		    const std::string &s1,
							  			const std::string &s2)
{
	std::string line;
	std::ifstream inFile;
	std::ofstream outFile;

	if(!_openFiles(fileName, inFile, outFile))
		return (false);
	while (getline(inFile, line))
	{
		size_t i = 0;
		while ((i = line.find(s1, i)) != std::string::npos)
		{
			line.erase(i, s1.length());
			line.insert(i, s2);
			i += s2.length();
		}
		outFile << line;
		if (line != "")
			outFile << std::endl;
	}
	outFile.close();
	inFile.close();
	return (true);
}
