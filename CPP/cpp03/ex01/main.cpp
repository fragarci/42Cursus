/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:24:13 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/16 17:29:24 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap scav_trap("fragarci");
	scav_trap.attack("Bobolongo");
	scav_trap.takeDamage(42);
	scav_trap.beRepaired(0x2A);
	scav_trap.guardGate();
	for (int i = 0; i < 50; i++)
		scav_trap.attack("Bobolongo");
	scav_trap.beRepaired(69);
	scav_trap.guardGate();
	scav_trap.takeDamage(420);
	scav_trap.takeDamage(0xFF);
	scav_trap.beRepaired(621);
	scav_trap.guardGate();
	scav_trap.attack("Bobolongo");

}
