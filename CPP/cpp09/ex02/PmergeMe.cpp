/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:11:59 by fragarci          #+#    #+#             */
/*   Updated: 2024/03/10 16:56:42 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) { return ; }

PmergeMe::PmergeMe(char **argv)
{
	while (*argv)
	{
		_vector.push_back(atoi(*argv));
		_list.push_back(atoi(*argv));
		argv++;
	}
}

PmergeMe::PmergeMe(const PmergeMe &src) { *this = src; }
PmergeMe::~PmergeMe(void) { return ; }

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_vector = src._vector;
		this->_list = src._list;
	}
	return (*this);
}

static std::vector<int> vector_merge(std::vector<int> a, std::vector<int> b)
{
	std::vector<int> c;

	while (!a.empty() && !b.empty())
	{
		if (a[0] > b[0])
		{
			c.push_back(b[0]);
			b.erase(b.begin() + 0);
		}
		else
		{
			c.push_back(a[0]);
			a.erase(a.begin() + 0);
		}
	}
	while (!a.empty())
	{
		c.push_back(a[0]);
		a.erase(a.begin() + 0);
	}
	while (!b.empty())
	{
		c.push_back(b[0]);
		b.erase(b.begin() + 0);
	}
	return (c);
}

std::vector<int>	PmergeMe::vectorSort(std::vector<int> v)
{
	if (v.size() == 1)
		return (v);

	std::vector<int> v1;
	for (std::size_t i = 0;  i != v.size() / 2; i++)
		v1.push_back(v[i]);

	std::vector<int> v2;
	for (std::size_t i = v.size() / 2; i != v.size(); i++)
		v2.push_back(v[i]);

	v1 = vectorSort(v1);
	v2 = vectorSort(v2);

	return (vector_merge(v1, v2));
}

static std::list<int> list_merge(std::list<int> a, std::list<int> b)
{
	std::list<int> c;

	while (!a.empty() && !b.empty())
	{
		if (a.front() > b.front())
		{
			c.push_back(b.front());
			b.pop_front();
		} else
		{
			c.push_back(a.front());
			a.pop_front();
		}
	}
	while (!a.empty())
	{
		c.push_back(a.front());
		a.pop_front();
	}
	while (!b.empty())
	{
		c.push_back(b.front());
		b.pop_front();
	}
	return (c);
}

std::list<int> PmergeMe::listSort(std::list<int> l)
{
	if (l.size() == 1)
		return l;
	std::list<int> l1, l2;
	std::list<int>::iterator it = l.begin();
	for (std::size_t i = 0; i < l.size() / 2; i++)
		l1.push_back(*it++);
	while (it != l.end())
	{
		l2.push_back(*it);
		it++;
	}
	l1 = listSort(l1);
	l2 = listSort(l2);
	return list_merge(l1, l2);
}

std::vector<int> PmergeMe::getVector(void) const { return (this->_vector); }
std::list<int> PmergeMe::getList(void) const { return (this->_list); }

std::ostream &operator<<(std::ostream &o, const std::vector<int> &src)
{
	for (std::vector<int>::const_iterator it = src.begin(); it != src.end(); it++)
		o << *it << " ";
	return (o);
}

std::ostream &operator<<(std::ostream &o, const std::list<int> &src)
{
	for (std::list<int>::const_iterator it = src.begin(); it != src.end(); it++)
		o << *it << " ";
	return (o);
}
