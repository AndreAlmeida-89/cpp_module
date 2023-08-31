/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 21:26:40 by andde-so          #+#    #+#             */
/*   Updated: 2023/08/31 00:40:00 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "main.hpp"

class PhoneBook
{
private:
	static const size_t	_capacity= 8;
	Contact 			_contacts[_capacity];
	size_t				_size;
	void	print_table() const;

public:
	void	add();
	void	search() const;
};

#endif