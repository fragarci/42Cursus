/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 12:24:13 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/15 13:43:15 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clap_trap("fragarci");
	clap_trap.attack("Bobolongo");
	clap_trap.takeDamage(4);
	clap_trap.beRepaired(2);
	for (int i = 0; i < 10; i++)
		clap_trap.attack("Bobolongo");
	clap_trap.beRepaired(69);
	clap_trap.takeDamage(420);
	clap_trap.takeDamage(0xFF);
	clap_trap.beRepaired(621);
	clap_trap.attack("Bobolongo");
}
