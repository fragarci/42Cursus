/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:33:40 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/17 23:43:27 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Ice.hpp"
#include "../inc/Character.hpp"
#include "../inc/IMateriaSource.hpp"

Ice::Ice() : _type("ice") { std::cout << "Ice[ " << this << " ] Default constructor called" << std::endl; }

Ice::Ice(Ice const & o) : AMateria("ice"), _type(o.getType()) { std::cout << "Ice[ " << this << " ] Copy constructor called" << std::endl; }

Ice::~Ice() { std::cout << "Ice[ " << this << " ] Destructor called" << std::endl; }

std::string const & Ice::getType( void ) const { return (this->_type); }

Ice *Ice::clone() const { return (new Ice); }

void Ice::use(ICharacter& target) { std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl; }

Ice & Ice::operator=(Ice const & o)
{
	this->_type = o.getType();
	return (*this);
}
