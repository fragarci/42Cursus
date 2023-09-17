/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:24:09 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/17 23:37:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MateriaSource.hpp"
#include "../inc/AMateria.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	std::cout << "MateriaSource[ " << this << " ] Default constructor called" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const & o)
{
	for (int i = 0; i < 4; i++)
		if (o._inventory[i])
			this->_inventory[i] = o._inventory[i]->clone();
	std::cout << "MateriaSource[ " << this << " ] Copy constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	std::cout << "MateriaSource[ " << this << " ] Destructor called" << std::endl;
}

void MateriaSource::learnMateria(AMateria *m)
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

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;

	while (this->_inventory[i] && this->_inventory[i]->getType() != type && i < 4)
		i++;
	if (i >= 4 || !this->_inventory[i])
		return (NULL);
	return (((this->_inventory)[i])->clone());
}

MateriaSource & MateriaSource::operator=(MateriaSource const & o)
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
