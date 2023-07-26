/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:24:56 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 13:30:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

int	main(void)
{
	PhoneBook		phone_book;
	std::string	input;

	input = "";
	phone_book.ft_welcome();
	while (input.compare("EXIT"))
	{
		if (input.compare("ADD") == 0)
			phone_book.ft_addContact();
		else if (input.compare("SEARCH") == 0)
		{
			phone_book.ft_printContacts();
			phone_book.ft_search();
		}
		std::cout << "> " << std::flush;
		std::cin >> input;
	}
	return (0);
}
