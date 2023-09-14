/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:05:10 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 17:05:37 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(void): _type("Animal") { std::cout << "[ " << this << " ] Animal created" << std::endl; }

Animal::Animal(std::string type) : _type(type) { std::cout << "[ " << this << " ] " << this->_type << " created" << std::endl; }

Animal::Animal(const Animal &o) { *this = o; }

Animal::~Animal()  { std::cout << "[ " << this << " ] " << this->_type << " destroyed" << std::endl; }

Animal& Animal::operator=(const Animal &o)
{
	this->_type = o._type;
	return (*this);
}

void Animal::makeSound(void) const { std::cout << "[ " << this << " ] " << this->_type << ": **Generic Animal Sound.mp3**" << std::endl; }

std::string Animal::getType(void) { return (this->_type); }
