/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/10 12:01:53 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
		std::cout << std::boolalpha <<
		"Triangle Vertices: a(0, 0) b(0, 5), c(5, 0)" << std::endl <<
		"p(1  ,  1): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 1)) << std::endl <<
		"p(-1 , -1): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(-1, -1)) << std::endl <<
		"p(1  ,  0): " << bsp(Point(0, 0), Point(0, 5), Point(5, 0), Point(1, 0)) << std::endl;
}
