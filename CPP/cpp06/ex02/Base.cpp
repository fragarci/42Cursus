/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:17:05 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 11:33:20 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Base::~Base() {}

Base *generate(void)
{
	int	random;

	srand(time(NULL));
	random = rand() % 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	else
		return (new C);
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Class A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Class B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Class C" << std::endl;
	else
		std::cout << "Neither class A, B or C" << std::endl;
}

void identify(Base &p)
{
	Base	tmp;

	(void)tmp;
	try
	{
		tmp = dynamic_cast<A &>(p);
		std::cout << "Class A" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		tmp = dynamic_cast<B &>(p);
		std::cout << "Class B" << std::endl;
	}
	catch(const std::exception& e) {}
	try
	{
		tmp = dynamic_cast<C &>(p);
		std::cout << "Class C" << std::endl;
	}
	catch(const std::exception& e) {}

}
