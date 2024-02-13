/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 16:17:54 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/12 16:22:08 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Usage: ./convert <string>" << std::endl, 1);
	ScalarConverter::convert(argv[1]);
	return (0);
}
