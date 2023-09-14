/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:45:23 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 12:17:27 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"

Ice::Ice(void) : AMateria("ice") { std::cout << "[ " << this << " ] Ice default constructor called" << std::endl; }

Ice::Ice(Ice const & o) : AMateria(o) { std::cout << "[ " << this << " ] Ice copy constructor called" << std::endl; }

Ice::~Ice() { std::cout << "[ " << this << " ] Ice destructor called" << std::endl; }

AMateria* Ice::clone(void) const { return (new Ice()); }

void Ice::use(ICharacter& target) {std:: cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }

AMateria & Ice::operator=(AMateria const & o)
{
	this->type = o.getType();
	return (*this);
}
