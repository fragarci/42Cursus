/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:45 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/06 11:37:39 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The memset() function fills the first n bytes of the memory area pointed
	to by s with the constant byte c.

RETURN VALUE
    The memset() function returns a pointer to the memory area s.
*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	register unsigned char	*dest;
	register unsigned char	val;
	register size_t			*word_ptr;
	register size_t			word;

	if (n == 0)
		return (s);
	dest = (unsigned char *)s;
	val = (unsigned char)c;
	word = val;
	word |= word << 8;
	word |= word << 16;
	word |= word << 32;
	while (((uintptr_t)dest % sizeof(size_t)) && n-- > 0)
		*dest++ = val;
	word_ptr = (size_t *)dest;
	while (n >= sizeof(size_t))
	{
		*word_ptr++ = word;
		n -= sizeof(size_t);
	}
	dest = (unsigned char *)word_ptr;
	while (n--)
		*dest++ = val;
	return (s);
}
