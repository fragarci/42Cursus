/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:58:36 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/14 15:58:49 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void): _N(0), _size(0) { return ; }
Span::Span(unsigned int n): _N(n), _size(0) { return ; }
Span::Span(Span const &src) { *this = src; }
Span::~Span(void) { return ; }

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_N = src._N;
		this->_size = src._size;
		this->_lst = src._lst;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (this->_size >= this->_N)
		throw std::length_error("Span limit reached");
	this->_lst.push_back(n);
	this->_size++;
}

int Span::shortestSpan(void)
{
	if (this->_size <= 1)
		throw std::length_error("Span too small");
	std::list<int> aux = this->_lst;
	aux.sort();
	std::list<int> diff;
	std::adjacent_difference(aux.begin(), aux.end(), std::back_inserter(diff));
	return (std::abs(*std::min_element(diff.begin(), diff.end())));
}

int Span::longestSpan(void)
{
	if (this->_size <= 1)
		throw std::length_error("Span too small");
	std::list<int> aux = this->_lst;
	aux.sort();
	return (std::abs(aux.back() - aux.front()));
}

void	Span::createRandom(unsigned int size)
{
	if (this->_size + size > this->_N)
		throw std::length_error("Span limit reached");
	srand(time(NULL));
	for (unsigned int i = 0; i < size; i++)
	{
		this->_lst.push_back(std::rand() % 4242);
		this->_size++;
	}
}

std::list<int> Span::getLst(void) const { return (this->_lst); }

std::ostream &operator<<(std::ostream &o, const Span &src)
{
	std::list<int> aux = src.getLst();
	for (std::list<int>::iterator it = aux.begin(); it != aux.end(); it++)
		o << *it << " ";
	return (o);
}
