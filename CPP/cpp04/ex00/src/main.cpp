/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:29 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/22 13:12:14 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int	main(void)
{
	Animal	*animal;
	Dog			*dog;
	Cat			*cat;

	std::cout << "#### ANIMAL CREATION ####" << std::endl;
	animal = new Animal();
	dog = new Dog();
	cat = new Cat();

	std::cout << std::endl << "#### ANIMAL TYPES ####" << std::endl;
	std::cout << "[ " << animal << " ] Type: " << animal->getType() << std::endl;
	std::cout << "[ " << dog << " ] Type: " << dog->getType() << std::endl;
	std::cout << "[ " << cat << " ] Type: " << cat->getType() << std::endl;

	std::cout << std::endl << "#### ANIMAL METHOD CALL: makeSound() ####" << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl << "#### ANIMAL DESTRUCTION ####" << std::endl;
	delete (animal);
	delete (dog);
	delete (cat);

	std::cout << std::endl << "#### WRONG ANIMAL CREATION ####" << std::endl;
	WrongAnimal *wrong_animal = new WrongAnimal();
	WrongCat		*wrong_cat = new WrongCat();

	std::cout << std::endl << "#### WRONG ANIMAL TYPES ####" << std::endl;
	std::cout << "[ " << wrong_animal << " ] Type: " << wrong_animal->getType() << std::endl;
	std::cout << "[ " << wrong_cat << " ] Type: " << wrong_cat->getType() << std::endl;

	std::cout << std::endl << "#### WRONG ANIMAL METHOD CALL: makeSound() ####" << std::endl;
	wrong_animal->makeSound();
	wrong_cat->makeSound();

	std::cout << std::endl << "#### WRONG ANIMAL DESTRUCTION ####" << std::endl;
	delete (wrong_animal);
	delete (wrong_cat);

	return (0);
}
