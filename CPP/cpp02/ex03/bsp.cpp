/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:20:41 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/08 14:51:01 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	bool check[3];


	std::cout << std::boolalpha

		<< "a = " << a << std::endl
		<< "b = " << b << std::endl
		<< "c = " << c << std::endl << std::endl;

	check[0] = (Fixed(-1) * (b.get_Y() - a.get_Y()) * (a.get_X() - point.get_X())) + ((b.get_X() - a.get_X()) * (a.get_Y() - point.get_Y())) > 0;
	check[1] = (Fixed(-1) * (c.get_Y() - b.get_Y()) * (b.get_X() - point.get_X())) + ((c.get_X() - b.get_X()) * (b.get_Y() - point.get_Y())) > 0;
	check[2] = (Fixed(-1) * (a.get_Y() - c.get_Y()) * (c.get_X() - point.get_X())) + ((a.get_X() - c.get_X()) * (c.get_Y() - point.get_Y())) > 0;

	/*std::cout << std::boolalpha
	<< "\ncheck[0] = " << Fixed((Fixed(-1) * (b.get_Y() - a.get_Y()) * (a.get_X() - point.get_X())) + ((b.get_X() - a.get_X()) * (a.get_Y() - point.get_Y())))
	<< "\ncheck[1] = " << Fixed((Fixed(-1) * (c.get_Y() - b.get_Y()) * (b.get_X() - point.get_X())) + ((c.get_X() - b.get_X()) * (b.get_Y() - point.get_Y())))
	<< "\ncheck[2] = " << Fixed((Fixed(-1) * (a.get_Y() - c.get_Y()) * (c.get_X() - point.get_X())) + ((a.get_X() - c.get_X()) * (c.get_Y() - point.get_Y())))
	<< std::endl;*/

	return (check[0] == check[1] && check[1] == check[2]);
}
/*
	|--> Points A, B and vector AB represents one side of a triangle <--|
	A(Ax, Ay)
	B(Bx, By)
	AB(Bx - Ax, By - Ay)

	|--> We need to find if point P is inside the triangle <--|
	P(Px, Py)

	|--> PA is the vector that goes from P to A (The start point of the vector AB) <--|
	PA(Ax - Px, Ay - Py)

	|--> P_AB is perpendicular to AB <--|
	P_AB(-(By - Ay), Bx - Ax)

	|--> Now we make the dot product between P_AB and PA <--|
	-(By - Ay) · (Ax - Px) + (Bx - Ax) · (Ay - Py)

	|--> If the dot product is grater than zero, P is at the right side otherwise it's at the left. If its zero is at the same line <--|
*/
