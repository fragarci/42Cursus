/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 22:48:14 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/17 23:29:52 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Character.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << _name << " just got into existance!" << std::endl;
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	std::cout << "Character[ " << this << " ] Default constructor called" << std::endl;
}

Character::Character(Character const & o) : _name(o.getName())
{
	std::cout << _name << " just got into existance!" << std::endl;
	for (int i = 0; i < 4; i++)
		if ((o._inventory)[i])
			(this->_inventory)[i] = (o._inventory[i])->clone();
	std::cout << "Character[ " << this << " ] Copy constructor called" << std::endl;
}
Character::~Character()
{
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i])
			delete this->_inventory[i];
	std::cout << "Character[ " << this << " ] Destructor called" << std::endl;
}

std::string const & Character::getName() const { return (this->_name); }

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] == 0)
		{
			this->_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4)
		return ;
	else if (!(this->_inventory)[idx])
		return ;
	else
		this->_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	std::string	name = this->getName();

	if (idx < 0 || idx >= 4 || !this->_inventory[idx])
		return ;
	this->_inventory[idx]->use(target);
}

AMateria	*Character::getInventoryIdx(int idx) { return (this->_inventory[idx]); }

Character & Character::operator=(Character const & o)
{
	for(int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
		if (o._inventory[i])
			this->_inventory[i] = o._inventory[i]->clone();
	}
	return (*this);
}
