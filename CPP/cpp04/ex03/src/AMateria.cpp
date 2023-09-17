/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:24:15 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/17 22:32:29 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria() { std::cout << "AMateria[ " << this << " ] Default constructor called" << std::endl; }

AMateria::AMateria(std::string const & type) : _type(type) { std::cout << "AMateria[ " << this << " ] String constructor called" << std::endl; }

AMateria::AMateria(AMateria const & ref) : _type(ref._type) { std::cout << "AMateria[ " << this << " ] Copy constructor called" << std::endl; }

AMateria::~AMateria() { std::cout << "AMateria[ " << this << " ] Destructor called" << std::endl; }

std::string const & AMateria::getType() const { return(this->_type); }

void AMateria::use(ICharacter& target) { std::cout << "AMateria[ " << this << " ] Used on " << target.getName() << std::endl; }
