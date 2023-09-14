/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:03:31 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 18:17:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) : Animal("Cat") {}

Cat::Cat(const Cat &o) : Animal(o) {}

Cat::~Cat() {}

Cat &Cat::operator=(const Cat &o)
{
	this->_type = o._type;
	return (*this);
}

void Cat::makeSound(void) const { std::cout << "[ " << this << " ] " << this->_type << ": Meow :3" << std::endl; }
