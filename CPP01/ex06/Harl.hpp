/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 15:08:04 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/16 16:55:47 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

enum Level
{
	DEBUG = 0,
	INFO,
	WARNING,
	ERROR,
	NUMBER_OF_LEVELS,
	UNKNOWN
};

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	static Level getLevel(std::string &level);
	static const std::string _levels[NUMBER_OF_LEVELS];
	const void (Harl::*arr[NUMBER_OF_LEVELS])();

public:
	Harl();
	~Harl();
	void complain(std::string level);
};

#endif
