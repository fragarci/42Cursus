/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:43:48 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 13:18:48 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H

#include <limits>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int	_ft_readIndex(void) const;

	public:
		void	ft_addContact(void);
		void	ft_printContacts(void) const;
		void	ft_search(void) const;
		void	ft_welcome(void) const;
};
#endif
