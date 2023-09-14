/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:03:31 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 19:23:59 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"), brain(new Brain()) {}

Cat::Cat(const Cat &o) : AAnimal(o), brain(new Brain()) { *this = o; }

Cat::~Cat() { delete (this->brain); }

Cat &Cat::operator=(const Cat &o)
{
	this->_type = o._type;
	this->brain = o.brain;
	return (*this);
}

void Cat::makeSound(void) const { std::cout << "[ " << this << " ] " << this->_type << ": Meow :3" << std::endl; }
