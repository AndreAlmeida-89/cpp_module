/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:08:04 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/17 20:04:16 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
private:
	enum Level
	{
		DEBUG = 0,
		INFO,
		WARNING,
		ERROR,
		NUMBER_OF_LEVELS
	};

	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	Level _getLevelType(std::string &level);

public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
