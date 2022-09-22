/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:08 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/22 10:46:07 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
    The memcmp() function compares the first n bytes (each interpreted as
	unsigned char) of the memory areas s1 and s2.

RETURN VALUE
	The memcmp() function returns an integer less than, equal to, or greater
	than zero if the first n bytes of s1 is found, respectively, to be less
	than, to match, or be greater than the first n bytes of s2.
	For a nonzero return value, the sign is determined by the sign of the
	difference between the first pair bytes (interpreted as unsigned char)
	that differ in s1 and s2. If n is zero, the return value is zero.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux_s1;
	unsigned char	*aux_s2;
	size_t			i;

	aux_s1 = (unsigned char *)s1;
	aux_s2 = (unsigned char *)s2;
	i = 0;
	while (aux_s1[i] == aux_s2[i] && i < n)
		i++;
	return (aux_s1[i] - aux_s2[2]);
}
