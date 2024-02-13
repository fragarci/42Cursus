/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:53:53 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 19:43:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <string>

static void	ft_putnbr(int &nbr) { std::cout << nbr << " "; }
static void	ft_putchr(char &chr) { std::cout << chr << " "; }
static void	ft_putstr(std::string &str) { std::cout << str << " "; }


int	main(void)
{
	int nbrs[5] = {1, 2, 3, 4, 5};
	char chrs[5] = {'a', 'b', 'c', 'd', 'e'};
	std::string	strs[5] = {"STR1", "STR2", "STR3", "STR4", "STR5"};

	std::cout << "Int Array: ";
	iter(nbrs, sizeof(nbrs) / sizeof(int), ft_putnbr);
	std::cout << std::endl;

	std::cout << "Char Array: ";
	iter(chrs, sizeof(chrs) / sizeof(char), ft_putchr);
	std::cout << std::endl;

	std::cout << "String Array: ";
	iter(strs, 5, ft_putstr);
	std::cout << std::endl;
	return (0);
}
