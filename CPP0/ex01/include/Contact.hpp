/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:26:32 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 00:38:43 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "main.hpp"

class Contact
{
private:
	int			_index;
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
	std::string	resize(std::string str) const;

public:
	Contact();
	Contact(int	index);
	void	printContactInfo() const;
	void	printLine() const;
};

#endif