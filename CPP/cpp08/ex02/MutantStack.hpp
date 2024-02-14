/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 16:19:52 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/14 16:36:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T> class MutantStack : public std::stack<T>
{
	public:
		MutantStack(void);
		MutantStack(const MutantStack &src);
		~MutantStack(void);
		MutantStack &operator=(const MutantStack &src);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);
};

template <typename T> MutantStack<T>::MutantStack(void) { return ; }
template <typename T> MutantStack<T>::MutantStack(const MutantStack &src) { *this = src; }
template <typename T> MutantStack<T>::~MutantStack(void) { return ; }
template <typename T> MutantStack<T> &MutantStack<T>::operator=(const MutantStack &src)
{
	if (this != &src)
		std::stack<T>::operator=(src);
	return (this);
}

template <typename T> typename MutantStack<T>::iterator MutantStack<T>::begin(void) { return (std::stack<T>::c.begin()); }
template <typename T> typename MutantStack<T>::iterator MutantStack<T>::end(void) { return (std::stack<T>::c.end()); }
#endif
