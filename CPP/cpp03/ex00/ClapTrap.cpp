/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 10:18:10 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/15 13:31:19 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): _name(name),_hit_points(10), _energy_points(10), _attack_damage(10)
{
	std::cout << "[ ClapTrap " << this->_name << " ] Has been created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)	{ *this = copy; }

ClapTrap::~ClapTrap() { std::cout << "[ ClapTrap " << this->_name << " ] Has been destroyed" << std::endl; }

ClapTrap& ClapTrap::operator=(const ClapTrap &copy)
{
	if (this == &copy)
		return (*this);
	this->_name = copy._name;
	this->_hit_points = copy._hit_points;
	this->_energy_points = copy._energy_points;
	this->_attack_damage = copy._attack_damage;
	return (*this);
}

std::ostream& operator<<(std::ostream &out, const ClapTrap &obj)
{
	out << "[ ClapTrap " << &obj << " ]" << std::endl <<
	"_name: " << obj.getName() << std::endl <<
	"_hit_points: " << obj.getHitPoints() << std::endl <<
	"_energy_points: " << obj.getEnergyPoints() << std::endl <<
	"_attack_damage: " << obj.getAttackDamage() << std::endl;
	return (out);
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hit_points <= 0)
		std::cout << "[ ClapTrap " << this->_name << " ] Beep Boop, I'm dead ~w~" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "[ ClapTrap " << this->_name << " ] is eepy and needs a smol sleeb" << std::endl;
	else
		std::cout << "[ ClapTrap " << this->_name << " ]" <<
		" attacks " << target <<
		" causing " << this->_attack_damage <<
		" points of damage! Energy points remaining: " << --this->_energy_points << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points <= 0)
		std::cout << "[ ClapTrap " << this->_name << " ] I'm already dead, why? TT~TT" << std::endl;
	else
	{
		std::cout << "[ ClapTrap " << this->_name << " ] Took " << amount << " points of damage. ";
		this->_hit_points -= amount;
		if (this->_hit_points <= 0)
			std::cout << "It's dead" << std::endl;
		else
			std::cout << "Hit Points left: " << this->_hit_points << std::endl;
	}
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hit_points <= 0)
		std::cout << "[ ClapTrap " << this->_name << " ] Can't repair itself if it's dead" << std::endl;
	else if (this->_energy_points <= 0)
		std::cout << "[ ClapTrap " << this->_name << " ] I'm too tired, srry >~<" << std::endl;
	else
	{
		std::cout << "[ ClapTrap " << this->_name << " ] Got repaired " << amount << " points. ";
		this->_hit_points += amount;
		std::cout << "Current hit points: " << this->_hit_points << std::endl;
	}
}

std::string	ClapTrap::getName(void) const { return (this->_name); }
int	ClapTrap::getHitPoints(void) const { return (this->_hit_points); }
int ClapTrap::getEnergyPoints(void) const { return (this->_energy_points); }
int ClapTrap::getAttackDamage(void) const { return (this->_attack_damage); }
