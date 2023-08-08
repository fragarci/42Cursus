/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/08 14:50:44 by fragarci         ###   ########.fr       */
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

	/*std::cout
		<< "a = " << a << std::endl
		<< "b = " << b << std::endl
		<< "c = " << c << std::endl
		<< "p = " << p << std::endl
		<< "Point inside triangle: " << std::endl;*/
		std::cout << std::boolalpha << bsp(a, b, c, p) << std::endl;
}
