/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 10:56:47 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/07 12:10:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {}

Point::Point(const Point &copy) { *this = copy; }

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {}

Point::~Point() {}

Fixed Point::get_X(void) const { return (this->_x); }
Fixed Point::get_Y(void) const { return (this->_y); }

Point &Point::operator=(const Point &point)
{
	(void) point;
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Point &point)
{
	//out << fixed.toFloat();
	out << "{ x: " << point.get_X() << ", y: " << point.get_Y() << " }";
	return (out);
}
