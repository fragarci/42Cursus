/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:05:10 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/13 19:22:35 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(void): _type("Animal") { std::cout << "[ " << this << " ] Animal created" << std::endl; }

AAnimal::AAnimal(std::string type) : _type(type) { std::cout << "[ " << this << " ] " << this->_type << " created" << std::endl; }

AAnimal::AAnimal(const AAnimal &o) { *this = o; }

AAnimal::~AAnimal()  { std::cout << "[ " << this << " ] " << this->_type << " destroyed" << std::endl; }

AAnimal& AAnimal::operator=(const AAnimal &o)
{
	this->_type = o._type;
	return (*this);
}

void AAnimal::makeSound(void) const { std::cout << "[ " << this << " ] " << this->_type << ": **Generic Animal Sound.mp3**" << std::endl; }

std::string AAnimal::getType(void) { return (this->_type); }
