/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:17:54 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 17:15:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog") {}

Dog::Dog(const Dog &o) : Animal(o) {}

Dog::~Dog() {}

Dog	&Dog::operator=(const Dog &o)
{
	this->_type = o._type;
	return (*this);
}

void Dog::makeSound(void) { std::cout << "[ " << this << " ] " << this->_type << ": Awooooooo" << std::endl; }
