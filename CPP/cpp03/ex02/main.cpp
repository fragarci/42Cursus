/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:24:13 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/16 17:54:48 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap frag_trap("fragarci");
	frag_trap.attack("Bobolongo");
	frag_trap.takeDamage(42);
	frag_trap.beRepaired(0x2A);
	frag_trap.highFiveGuys();
	for (int i = 0; i < 100; i++)
		frag_trap.attack("Bobolongo");
	frag_trap.beRepaired(69);
	frag_trap.highFiveGuys();
	frag_trap.takeDamage(420);
	frag_trap.takeDamage(0xFF);
	frag_trap.beRepaired(621);
	frag_trap.highFiveGuys();
	frag_trap.attack("Bobolongo");

}
