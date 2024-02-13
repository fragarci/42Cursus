/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:42:20 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 11:07:53 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		*ptr;
	uintptr_t	raw;

	ptr = new Data(42);
	std::cout << "##### Original Data Structure #####" << std::endl;
	std::cout << "ptr: " << ptr << "; nbr: " << ptr->getNbr() << std::endl;

	raw = Serializer::serialize(ptr);
	std::cout << "\n##### Serialized Pointer #####" << std::endl;
	std::cout << "raw: " << std::hex << raw << std::dec << std::endl;

	ptr = Serializer::deserialize(raw);
	std::cout << "\n##### Deserialized Pointer #####" << std::endl;
	std::cout << "ptr: " << ptr << "; nbr: " << ptr->getNbr() << std::endl;

	delete ptr;
}
