/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 12:59:09 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/22 13:05:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void): _type("Wrong Animal") { std::cout << "[ " << this << " ] Wrong Animal created" << std::endl; }

WrongAnimal::WrongAnimal(std::string type) : _type(type) { std::cout << "[ " << this << " ] " << this->_type << " created" << std::endl; }

WrongAnimal::WrongAnimal(const WrongAnimal &o) { *this = o; }

WrongAnimal::~WrongAnimal()  { std::cout << "[ " << this << " ] " << this->_type << " destroyed" << std::endl; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &o)
{
	this->_type = o._type;
	return (*this);
}

void WrongAnimal::makeSound(void) { std::cout << "[ " << this << " ] " << this->_type << ": **SCREAMS.mp3**" << std::endl; }

std::string WrongAnimal::getType(void) { return (this->_type); }
