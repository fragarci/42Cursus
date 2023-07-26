/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:17:48 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 14:19:24 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Contact.hpp"

std::string	Contact::_ft_getInput(std::string str) const
{
	std::string	user_input;
	bool		valid_input;

	user_input = "";
	valid_input = false;
	while (!valid_input)
	{
		std::cout << str << std::flush;
		std::getline(std::cin, user_input);
		if (std::cin.good() && !user_input.empty())
			valid_input = true;
		else
		{
			std::cin.clear();
			std::cout << "Invalid input, please try again." << std::endl;
		}
	}
	return (user_input);
}

std::string	Contact::_ft_printStr(std::string str) const
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	Contact::ft_init(void)
{
	static unsigned int	index = 1;

	if (index >= 9)
		index = 1;
	this->_index = index++;
	std::cin.ignore();
	this->_first_name = this->_ft_getInput("First Name: ");
	this->_last_name = this->_ft_getInput("Last Name: ");
	this->_nickname = this->_ft_getInput("Nickname: ");
	this->_phone_number = this->_ft_getInput("Phone Number: ");
	this->_darkest_secret = this->_ft_getInput("Darkest Secret: ");
	std::cout << std::endl;
}

void	Contact::ft_print_table(void) const
{
	if (this->_first_name.empty())
		return ;
	std::cout	<< "|" << std::setw(10) << _index << std::flush;
	std::cout << "|" << std::setw(10) << this->_ft_printStr(this->_first_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_ft_printStr(this->_last_name) << std::flush;
	std::cout << "|" << std::setw(10) << this->_ft_printStr(this->_nickname) << std::flush;
	std::cout << "|" << std::endl;
}

bool	Contact::ft_show_contact(void) const
{
	if (this->_first_name.empty())
		return (false);
	std::cout << "----> CONTACT #" << this->_index << " <----" << std::endl;
	std::cout << "First Name:\t" << this->_first_name << std::endl;
	std::cout << "Last Name:\t" << this->_last_name << std::endl;
	std::cout << "Nickname:\t" << this->_nickname << std::endl;
	std::cout << "Phone Number:\t" << this->_phone_number << std::endl;
	std::cout << "Darkest Secret:\t" << this->_darkest_secret << std::endl;
	std::cout << std::endl;
	return (true);
}
