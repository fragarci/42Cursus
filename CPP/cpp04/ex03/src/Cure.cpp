/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:21:45 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 12:17:39 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cure.hpp"


Cure::Cure(void) : AMateria("cure") { std::cout << "[ " << this << " ] Cure default constructor called" << std::endl; }

Cure::Cure(Cure const & o) : AMateria(o) { std::cout << "[ " << this << " ] Cure copy constructor called" << std::endl; }

Cure::~Cure() { std::cout << "[ " << this << " ] Cure destructor called" << std::endl; }

AMateria* Cure::clone(void) const { return (new Cure()); }

void Cure::use(ICharacter& target) {std:: cout << "* heals " << target.getName() << " wounds *" << std::endl; }

AMateria & Cure::operator=(AMateria const & o)
{
	this->type = o.getType();
	return (*this);
}
