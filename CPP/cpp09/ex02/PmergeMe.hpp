/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 13:11:22 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/21 19:02:48 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iterator>
# include <cstdlib>
# include <vector>
# include <list>

class PmergeMe
{
	private:
		std::vector<int>	_vector;
		std::list<int>		_list;
	public:
		PmergeMe(void);
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &src);
		~PmergeMe(void);
		PmergeMe &operator=(const PmergeMe &src);
		std::vector<int> vectorSort(std::vector<int> v);
		std::list<int> listSort(std::list<int> l);
		std::vector<int> getVector(void) const;
		std::list<int> getList(void) const;
};

std::ostream &operator<<(std::ostream &o, const std::vector<int> &src);
std::ostream &operator<<(std::ostream &o, const std::list<int> &src);


#endif
