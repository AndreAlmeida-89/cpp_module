/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:26:40 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 23:17:49 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "main.hpp"

class PhoneBook
{
private:
	static const	size_t	_capacity= 8;
	Contact 		_contacts[_capacity];
	size_t			_size;

	void		printTable() const;
	void		printLine(Contact contact, size_t index) const;
	bool		read_contact_info(const std::string &label, std::string &str);
	bool		create_contact(Contact *contact);

public:
	void	add();
	void	search() const;
};

#endif