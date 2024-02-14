/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:25:38 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/14 11:41:18 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main (void)
{
	std::vector<int>	vector;
	std::list<int>		list;

	for (int i = 0; i < 5; i++)
		vector.push_back(i);
	for (int i = 5; i > 0; i--)
		vector.push_back(i);

	int	test = 10;
	std::cout << "Vector Test: " << std::endl;
	if (easyfind(vector, test))
		std::cout << "number " << test << " is there" << std::endl;
	else
		std::cout << "number " << test << " isn't there" << std::endl;

	test = 2;
	if (easyfind(vector, test))
		std::cout << "number " << test << " is there" << std::endl;
	else
		std::cout << "number " << test << " isn't there" << std::endl;

	test = 42;
	std::cout << "\nList Test: " << std::endl;
	if (easyfind(list, test))
		std::cout << "number " << test << " is there" << std::endl;
	else
		std::cout << "number " << test << " isn't there" << std::endl;

	test = 4;
	if (easyfind(list, test))
		std::cout << "number " << test << " is there" << std::endl;
	else
		std::cout << "number " << test << " isn't there" << std::endl;

	return (0);
}
