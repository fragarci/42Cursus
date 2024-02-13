/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 18:56:00 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 19:31:05 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T> void iter(T *arr, std::size_t len, void (*func)(T &))
{
	if (!arr || !func)
		return ;
	for (std::size_t i = 0; i < len; i++)
		func(arr[i]);
}

#endif
