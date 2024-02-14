/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:51:20 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/14 15:56:08 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <stdexcept>
# include <algorithm>
# include <iostream>
# include <numeric>
# include <list>

class Span
{
	private:
		unsigned int	_N;
		unsigned int	_size;
		std::list<int>	_lst;
	public:
		Span(void);
		Span(unsigned int n);
		Span(const Span &src);
		~Span(void);
		Span &operator=(const Span &src);

		void	addNumber(int n);
		int		shortestSpan(void);
		int		longestSpan(void);
		void	createRandom(unsigned int size);
		std::list<int> getLst(void) const;
};

std::ostream &operator<<(std::ostream &o, const Span &src);

#endif
