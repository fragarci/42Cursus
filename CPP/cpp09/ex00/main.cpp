/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 11:40:53 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 11:01:37 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl, 1);

	BitcoinExchange btc = BitcoinExchange();
	btc.processInput(argv[1]);
	return (0);
}
