/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 13:24:21 by fragarci          #+#    #+#             */
/*   Updated: 2023/07/25 15:08:50 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed	a = Fixed(2);

	std::cout << "a: " << a << std::endl;
	a--;
	std::cout << "a-- = " << a << std::endl;

	return (0);
}
