/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:50:12 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 14:26:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PhoneBook.hpp"

void PhoneBook::ft_welcome(void) const
{
	std::cout	<< std::endl;
	std::cout << "Welcome to your AWESOME PhoneBook!" << std::endl;
	std::cout << std::endl;
	std::cout << "============== USAGE ==============" << std::endl;
	std::cout << "ADD\t: To add a contact." << std::endl;
	std::cout << "SEARCH\t: To search for a contact" << std::endl;
	std::cout << "EXIT\t: To quit the PhoneBook" << std::endl;
	std::cout << std::endl;
}

int	PhoneBook::_ft_readIndex() const
{
	int		input;
	bool	valid_input;

	input = -1;
	valid_input = false;
	while (!valid_input)
	{
		std::cout << "Enter the contact index: " << std::flush;
		std::cin >> input;
		if (std::cin.good() && (input >= 1 && input<= 8))
			valid_input = true;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			std::cout << "Invalid index, please write it again." << std::endl;
		}
	}
	return (input - 1);
}

void	PhoneBook::ft_addContact(void)
{
	static int	i = 0;

	this->_contacts[i % 8].ft_init();
	i++;
}

void	PhoneBook::ft_printContacts(void) const
{
	std::cout << "============== CONTACTS ==============" << std::endl;
	for (size_t i = 0; i < 8; i++)
	{
		this->_contacts[i % 8].ft_print_table();
	}
	std::cout << std::endl;
}

void	PhoneBook::ft_search(void) const
{
	int		i;
	bool 	valid_index;

	valid_index = false;
	while (!valid_index)
	{
		i = _ft_readIndex();
		valid_index = this->_contacts[i % 8].ft_show_contact();
	}
}
