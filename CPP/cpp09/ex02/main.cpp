/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:09:03 by fragarci          #+#    #+#             */
/*   Updated: 2024/03/11 18:46:59 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>

# define PURPLE "\033[0;35m"
# define GREEN "\033[0;32m"
# define DEFAULT "\033[;0m"

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

	std::cout << PURPLE"Before: " << merge.getVector() << DEFAULT << std::endl;
	std::cout << GREEN"After: " << v << DEFAULT << std::endl;
	std::cout << "Time to process a range of " << v.size() << " elements with std::vector:\t"
		<< vector_time << "us" << std::endl;
	std::cout << "Time to process a range of " << l.size() << " elements with std::list:\t"
		<< list_time << "us" << std::endl;
	return (0);
}
// ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "\n" ' ')
// ./PmergeMe $(jot -r 3000 1 100000 | tr '\n' ' ')
