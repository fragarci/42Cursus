/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 11:33:03 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/25 15:08:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() { this->value = 0; }

Fixed::Fixed(const int integer) { this->value = integer << this->fractional_bits; }

Fixed::Fixed(const float floater) { this->value = (int)(roundf(floater * (1 << this->fractional_bits))); }

Fixed::Fixed(const Fixed &copy) { this->value = copy.getRawBits(); }

Fixed::~Fixed() { }

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

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed result;
	result.value = this->value + fixed.value;
	return (result);
}
Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed result;
	result.value = this->value - fixed.value;
	return (result);
}
Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed result(this->toFloat() * fixed.toFloat());
	return (result);
}
Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed result(this->toFloat() / fixed.toFloat());
	return (result);
}

Fixed &Fixed::operator++(void)
{
	*this = *this + 1;
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
	*this = *this - 1;
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
