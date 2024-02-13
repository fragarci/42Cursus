/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 20:11:09 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 20:27:42 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

static void ft_putarr(Array<int> &arr)
{
	std::cout << "{ ";
	for (std::size_t i = 0; i < arr.size(); i++)
		std::cout << arr[i] << (i != arr.size() - 1 ? ", " : "");
	std::cout << " }" << std::endl;
}

int	main(void)
{
	Array<int> arr(5);

	std::cout << "##### Original Array #####" << std::endl;
	for (std::size_t i = 0; i < arr.size(); i++)
		arr[i] = i;
	ft_putarr(arr);

	std::cout << "\n##### Copy Array #####" << std::endl;
	Array<int> dup(arr);
	ft_putarr(dup);

	std::cout << "##### Exception Test #####" << std::endl;
	try { arr[42]; }
	catch(const std::exception& e) { std::cerr << e.what() << '\n'; }

}
