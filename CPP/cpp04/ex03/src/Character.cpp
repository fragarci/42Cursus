/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:37:39 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/14 13:05:43 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(void) : _name("")
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	std::cout << "[ " << this << " ] Character default constructor called" << std::endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	std::cout << "[ " << this << " ] Character string constructor called" << std::endl;
}

Character::Character(Character const & o) { *this = o; }

Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (_inventory[i])
			delete _inventory[i];
	std::cout << "[ " << this << " ] Character destructor called" << std::endl;
}

std::string const & Character::getName(void) const { return (this->_name); }

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	std::cout << "[ " << this << " ] Character " << this->_name << " cannot equip " << m->getType() << std::endl;
}

void Character::unequip(int idx) { this->_inventory[idx] = 0; }

void Character::use(int idx, ICharacter& target) { this->_inventory[idx]->use(target); }

Character& Character::operator=(Character const & o)
{
	this->_name = o._name;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = o._inventory[i];
	return (*this);
}
