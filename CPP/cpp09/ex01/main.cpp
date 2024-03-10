/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:17:39 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 12:20:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr  << "Usage: " << argv[0] << " <expression>" << std::endl, 1);

	RPN op;

	op.calculate(argv[1]);
	return (0);
}
