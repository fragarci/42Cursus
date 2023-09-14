/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:17:54 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 19:24:12 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/Dog.hpp"

Dog::Dog(void) : AAnimal("Dog"), brain(new Brain()) {}

Dog::Dog(const Dog &o) : AAnimal(o), brain(new Brain()) { *this = o; }

Dog::~Dog() { delete (this->brain); }

Dog	&Dog::operator=(const Dog &o)
{
	this->_type = o._type;
	this->brain = o.brain;
	return (*this);
}

void Dog::makeSound(void) { std::cout << "[ " << this << " ] " << this->_type << ": Awooooooo" << std::endl; }
