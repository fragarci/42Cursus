/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:08:40 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 17:27:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("Wrong Cat") {}

WrongCat::WrongCat(const WrongCat &o) : WrongAnimal(o) {}

WrongCat::~WrongCat() {}

WrongCat &WrongCat::operator=(const WrongCat &o)
{
	this->_type = o._type;
	return (*this);
}
