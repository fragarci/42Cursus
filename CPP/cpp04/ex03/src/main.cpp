/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:44:00 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/18 08:38:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AMateria.hpp"
#include "../inc/Character.hpp"
#include "../inc/Cure.hpp"
#include "../inc/Ice.hpp"
#include "../inc/ICharacter.hpp"
#include "../inc/IMateriaSource.hpp"
#include "../inc/MateriaSource.hpp"

int main()
{
	AMateria	*aMateria1;
	AMateria	*aMateria2;
	AMateria	*aMateria3;
	AMateria	*aMateria4;
	AMateria	*auxMateria;

	IMateriaSource* materiaSource = new MateriaSource();
	materiaSource->learnMateria(new Ice());
	materiaSource->learnMateria(new Cure());
	ICharacter* iCharacter1 = new Character("iCharacter1");
	aMateria1 = materiaSource->createMateria("ice");
	iCharacter1->equip(aMateria1);
	aMateria2 = materiaSource->createMateria("cure");
	iCharacter1->equip(aMateria2);
	aMateria1 = materiaSource->createMateria("nuke");
	iCharacter1->equip(aMateria1);
	ICharacter* iCharacter2 = new Character("iCharacter2");
	iCharacter1->use(1, *iCharacter2);
	Character	*iCharacter3 = new Character("iCharacter3");
	aMateria3 = materiaSource->createMateria("light");
	iCharacter3->equip(aMateria3);
	aMateria4 = materiaSource->createMateria("shadow");
	iCharacter3->equip(aMateria4);
	aMateria1 = materiaSource->createMateria("earth");
	iCharacter3->equip(aMateria1);
	Character	*deep_copy = new Character(*iCharacter3);
	iCharacter3->unequip(0);
	auxMateria = deep_copy->getInventoryIdx(1);
	deep_copy->unequip(1);
	delete (auxMateria);
	aMateria1 = materiaSource->createMateria("electric");
	deep_copy->equip(aMateria1);
	aMateria1 = materiaSource->createMateria("nuke");
	deep_copy->equip(aMateria1);
	iCharacter3->use(2, *iCharacter2);
	deep_copy->use(0, *iCharacter2);
	iCharacter1->unequip(3);
	iCharacter1->use(1, *iCharacter3);
	iCharacter1->unequip(1);
	iCharacter1->use(1, *iCharacter3);
	delete (materiaSource);
	delete (iCharacter1);
	delete (iCharacter2);
	delete (iCharacter3);
	delete (aMateria2);
	delete (aMateria3);
	delete (deep_copy);
	system("leaks -q ex03");
	return (0);
}
