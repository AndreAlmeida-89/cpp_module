/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andde-so <andde-so@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:19:50 by andde-so          #+#    #+#             */
/*   Updated: 2023/09/01 20:20:41 by andde-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include "Contact.hpp"
# include "PhoneBook.hpp"

std::string	ft_set_width(std::string str, size_t width = 10);
bool		ft_stoi(std::string &str, int *n);

#endif