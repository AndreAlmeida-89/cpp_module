/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StringReplacer.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 12:43:37 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 13:09:41 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGREPLACER_H
#define STRINGREPLACER_H

#include <iostream>
#include <fstream>

class StringReplacer
{
private:
	static bool _openFiles(const std::string &fileName,
						   std::ifstream &inFile,
						   std::ofstream &outFile);
public:
	static bool replaceWordsInFile(const std::string &fileName,
						 		   const std::string &s1,
						           const std::string &s2);
};

#endif
