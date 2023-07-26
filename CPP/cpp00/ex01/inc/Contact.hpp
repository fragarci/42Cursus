/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 10:59:47 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 14:19:33 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACH_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string		_first_name;
		std::string		_last_name;
		std::string		_nickname;
		std::string		_phone_number;
		std::string		_darkest_secret;
		unsigned int	_index;

		std::string	_ft_getInput(std::string str) const;
		std::string	_ft_printStr(std::string std) const;

	public:
		void	ft_init(void);
		void	ft_print_table(void) const;
		bool	ft_show_contact(void) const;
};
#endif
