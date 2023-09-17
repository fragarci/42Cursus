/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:42:05 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/17 23:43:14 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/IMateriaSource.hpp"

Cure::Cure() : _type("cure") { std::cout << "Cure[ " << this << " ] Default constructor called" << std::endl; }

Cure::Cure(Cure const & o) : AMateria("cure"), _type(o.getType()) { std::cout << "Cure[ " << this << " ] Copy constructor called" << std::endl; }

Cure::~Cure() { std::cout << "Cure[ " << this << " ] Destructor called" << std::endl; }

std::string const & Cure::getType( void ) const { return (this->_type); }

Cure *Cure::clone() const { return (new Cure); }

void Cure::use(ICharacter& target) { std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl; }

Cure & Cure::operator=(Cure const & o)
{
	this->_type = o.getType();
	return (*this);
}
