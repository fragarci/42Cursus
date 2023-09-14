/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:21:53 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 10:28:47 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"

AMateria::AMateria(void) : type("") { std::cout << "[ " << this << " ] AMateria default constructor called" << std::endl; }

AMateria::AMateria(std::string const & type) : type(type) { std::cout << "[ " << this << " ] AMateria string constructor called" << std::endl; }

AMateria::AMateria(AMateria const & o) : type(o.type) { std::cout << "[ " << this << " ] AMateria copy constructor called" << std::endl; }

std::string const & AMateria::getType(void) const { return (this->type); }
