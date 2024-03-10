/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:09:03 by fragarci          #+#    #+#             */
/*   Updated: 2024/03/10 16:34:28 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

static long int	get_time(void)
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	long int us = 1000000 * tp.tv_sec + tp.tv_usec;
	return (us);
}

int	main(int argc, char **argv)
{
	if (argc  < 2)
		return (std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl, 1);

	PmergeMe merge(&argv[1]);
	std::vector<int> v = merge.getVector();
	std::list<int> l = merge.getList();
	long int	start_time;
	long int	vector_time;
	long int	list_time;

	start_time = get_time();
	v = merge.vectorSort(v);
	vector_time = get_time() - start_time;

	start_time = get_time();
	l = merge.listSort(l);
	list_time = get_time() - start_time;

	std::cout << "Before: " << merge.getVector() << std::endl;
	std::cout << "After: " << v << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector:\t"
		<< vector_time << "us" << std::endl;
	std::cout << "Time to process a range of " << l.size() << " elements with std::list:\t"
		<< list_time << "us" << std::endl;
	return (0);
}
// ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" ' ')
