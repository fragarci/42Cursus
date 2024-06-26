/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:45:26 by fragarci          #+#    #+#             */
/*   Updated: 2024/01/12 12:01:09 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#if defined(__APPLE__) && defined(__MACH__)
void	ft_leaks(void)
{
	system("leaks -q ex00");
}
#endif

int	main(void)
{
	Bureaucrat *initTooHigh;
	Bureaucrat *initTooLow;
	Bureaucrat *incTooHigh;
	Bureaucrat *decTooLow;
	Bureaucrat *normal;

	#if defined(__APPLE__) && defined(__MACH__)
	atexit(ft_leaks);
	#endif

	(void) initTooHigh;
	(void) initTooLow;
	std::cout << "Init Rank Too Low Test" << std::endl;
	try { initTooLow = new Bureaucrat("initTooLow", 151); }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl << std::endl; }

	std::cout << "Init Rank Too High Test" << std::endl;
	try { initTooHigh = new Bureaucrat("initTooHigh", 0); }
	catch(const std::exception& e) { std::cerr << e.what() << std::endl << std::endl; }

	std::cout << "Increment Rank Too High Test" << std::endl;
	try
	{
		incTooHigh = new Bureaucrat("incTooHigh", 1);
		incTooHigh->incGrade();
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl << std::endl; }

	std::cout << "Decrement Rank Too Low Test" << std::endl;
	try
	{
		decTooLow = new Bureaucrat("decTooLow", 150);
		decTooLow->decGrade();
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl << std::endl; }

	std::cout << "Normal Rank Test" << std::endl;
	try
	{
		normal = new Bureaucrat("normal", 1);
		std::cout << *normal << std::endl;

		normal->decGrade();
		std::cout << *normal << std::endl;

		normal->incGrade();
		std::cout << *normal << std::endl << std::endl;
	}
	catch(const std::exception& e) { std::cerr << e.what() << std::endl << std::endl; }

	delete incTooHigh;
	delete decTooLow;
	delete normal;
	return (EXIT_SUCCESS);
}
