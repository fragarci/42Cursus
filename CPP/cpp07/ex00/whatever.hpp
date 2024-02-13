/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:30:40 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 18:55:38 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename T> void swap(T &a, T &b)
{
	T aux = a;
	a = b;
	b = aux;
}
template <typename T> T &min(T &a, T &b) { return (a <= b ? a : b); }
template <typename T> T &max(T &a, T &b) { return (a >= b ? a : b); }
#endif
