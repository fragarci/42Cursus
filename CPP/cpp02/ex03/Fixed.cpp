/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:33:03 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/07 10:41:59 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int integer)
{
	this->value = integer << this->fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floater)
{
	this->value = (int)(roundf(floater * (1 << this->fractional_bits)));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->value = copy.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

float	Fixed::toFloat(void) const { return ((float)this->value / (float)(1 << this->fractional_bits)); }
int	Fixed::toInt(void) const { return ((int)(this->value >> this->fractional_bits)); }

int	Fixed::getRawBits(void) const { return (this->value); }
void	Fixed::setRawBits(int const raw) { this->value = raw; }

Fixed &Fixed::operator=(const Fixed &op)
{
	if (this == &op)
		return (*this);
	this->value = op.getRawBits();
	return (*this);
}

bool Fixed::operator>(const Fixed &fixed) const { return (this->value > fixed.value); }
bool Fixed::operator<(const Fixed &fixed) const { return (this->value < fixed.value); }
bool Fixed::operator>=(const Fixed &fixed) const { return (this->value >= fixed.value); }
bool Fixed::operator<=(const Fixed &fixed) const { return (this->value <= fixed.value); }
bool Fixed::operator==(const Fixed &fixed) const { return (this->value == fixed.value); }
bool Fixed::operator!=(const Fixed &fixed) const { return (this->value != fixed.value); }

Fixed Fixed::operator+(const Fixed &fixed) const { return (Fixed(this->toFloat() + fixed.toFloat())); }
Fixed Fixed::operator-(const Fixed &fixed) const { return (Fixed(this->toFloat() - fixed.toFloat())); }
Fixed Fixed::operator*(const Fixed &fixed) const { return (Fixed(this->toFloat() * fixed.toFloat())); }
Fixed Fixed::operator/(const Fixed &fixed) const { return (Fixed(this->toFloat() / fixed.toFloat())); }

Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}
Fixed Fixed::operator++(int)
{
	Fixed old_value(*this);

	++(*this);
	return (old_value);
}
Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}
Fixed Fixed::operator--(int)
{
	Fixed old_value(*this);

	--(*this);
	return (old_value);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	else
		return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	else
		return (f2);
}
