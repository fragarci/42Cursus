/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 15:57:12 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/14 16:13:07 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Span: " << sp << std::endl;
	std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	Span sp2 = Span(10);
	sp2.createRandom(10);
	std::cout << "\nSpan: " << sp2 << std::endl;
	std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;

	try
	{
		Span sp3 = Span();
		sp.createRandom(255);
	}
	catch(const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
	try
	{
		Span sp4 = Span(1);
		sp4.createRandom(1);
		sp4.longestSpan();
	}
	catch(const std::exception& e) { std::cerr << "Error: " << e.what() << std::endl; }
	return (0);
}
