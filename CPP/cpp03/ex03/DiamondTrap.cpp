/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:43:20 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/16 18:56:39 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const DiamondTrap &o) : ClapTrap(o.getName() + "_clap_trap"), ScavTrap(o.getName() + "_clap_trap"), FragTrap(o.getName() + "_clap_trap") { *this = o; }

DiamondTrap::DiamondTrap(void) {}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), ScavTrap(name + "_clap_trap"), FragTrap(name + "_clap_trap")
{
	this->_name = name;
	std::cout << "[ DiamondTrap " << this->_name << " ] Has been created" << std::endl;
}

DiamondTrap::~DiamondTrap() { std::cout << "[ DiamondTrap " << this->_name << " ] Has been destroyed" << std::endl; }

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap's Name: " << this->_name << std::endl;
	std::cout << "ClapTrap's Name: " << this->getName() << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &o)
{
	if (this == &o)
		return (*this);
	this->_name = o._name;
	this->_hit_points = o._hit_points;
	this->_energy_points = o._energy_points;
	this->_attack_damage = o._attack_damage;
	return (*this);
}
