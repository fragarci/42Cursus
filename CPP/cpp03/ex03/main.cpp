/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:24:13 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/16 18:59:37 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond_trap("fragarci");
	diamond_trap.whoAmI();
	diamond_trap.attack("Bobolongo");
	diamond_trap.takeDamage(42);
	diamond_trap.beRepaired(0x2A);
	diamond_trap.highFiveGuys();
	diamond_trap.guardGate();
	for (int i = 0; i < 100; i++)
		diamond_trap.attack("Bobolongo");
	diamond_trap.beRepaired(69);
	diamond_trap.highFiveGuys();
	diamond_trap.guardGate();
	diamond_trap.takeDamage(420);
	diamond_trap.takeDamage(0xFF);
	diamond_trap.beRepaired(621);
	diamond_trap.highFiveGuys();
	diamond_trap.guardGate();
	diamond_trap.attack("Bobolongo");

}
