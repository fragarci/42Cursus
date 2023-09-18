/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 11:38:29 by fragarci          #+#    #+#             */
/*   Updated: 2023/09/18 08:52:44 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"
#include "../inc/Dog.hpp"
#include "../inc/Cat.hpp"

int	main(void)
{
	std::cout << "#### ANIMAL CREATION ####" << std::endl;
	AAnimal	*i = new Dog();
	AAnimal	*j = new Cat();

	std::cout << std::endl << "#### ANIMAL DESTRUCTION ####" << std::endl;

	delete (i);
	delete (j);

	std::cout << std::endl << "#### ANIMAL ARRAY CREATION ####" << std::endl;
	const AAnimal *animals[4];

	for (int i = 0; i < 4; i++)
		if (i % 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();

	std::cout << std::endl << "#### ANIMAL ARRAY DESTRUCTION ####" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];
	system("leaks -q ex02");
	return (0);
}
