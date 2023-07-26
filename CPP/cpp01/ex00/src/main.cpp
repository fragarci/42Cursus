/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:41:32 by fragarci          #+#    #+#             */
/*   Updated: 2023/04/05 16:59:55 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	std::string	name;

	name = "";
	std::cout << "Name of the zombie on the stack: " << std::flush;
	std::cin >> name;

	Zombie zombie_a(name);
	std::cout << "Calling anounce function..." << std::endl;
	zombie_a.anounce();

	std::cout << "Name of the zombie on the heap: " << std::flush;
	std::cin >> name;

	Zombie *zombie_b = newZombie(name);
	std::cout << "Calling anounce function..." << std::endl;
	zombie_b->anounce();
	std::cout << "Calling object destructor..." << std::endl;
	delete zombie_b;

	std::cout << "Calling randomChump(\"pako\")" << std::endl;
	randomChump("pako");

	return (0);
}
