/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:26:40 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/01 19:44:10 by andde-so         ###   ########.fr       */
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

	void	_display_phone_book() const;
	void	_print_line(Contact contact, size_t index) const;

public:
	void	add();
	void	search() const;
};

#endif