/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/07 12:16:18 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point const a = Point(0, 0);
	Point const b = Point(0, 5);
	Point const c = Point(5, 0);
	Point const p = Point(-1, -1);
	std::cout << std::boolalpha

		<< "a = " << a << std::endl
		<< "b = " << b << std::endl
		<< "c = " << c << std::endl
		<< "p = " << p << std::endl
		<< "Point inside triangle: " << bsp(a, b, c, p) << std::endl;
}
