/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:33:03 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/25 13:34:41 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed:: Fixed object and set value to 0
 *
 */
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int integer)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = integer << this->fractional_bits;
}

Fixed::Fixed(const float floater)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = (int)(roundf(floater * (1 << this->fractional_bits)));
}

/**
 * @brief Given a Fixed object reference, construct a new Fixed:: Fixed object
 *
 * @param copy
 */
Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->value = copy.getRawBits();
}

/**
 * @brief Destroy the Fixed:: Fixed object
 *
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/**
 * @brief Converts Fixed point object to float
 *
 * @return float
 */
float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->fractional_bits));
}

/**
 * @brief Conver Fixed point object to int
 *
 * @return int
 */
int	Fixed::toInt(void) const
{
	return ((int)(this->value >> this->fractional_bits));
}

// Getters & Setters

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void	Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed &Fixed::operator=(const Fixed &op)
{
	std::cout << "Asignation operator called" << std::endl;
	if (this == &op)
		return (*this);
	this->value = op.getRawBits();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
