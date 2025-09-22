/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:24:55 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/06 11:34:44 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
    The memchr() function scans the initial n bytes of the memory area pointed
	to by s for the first instance of c.  Both c and the bytes of the memory
	area pointed to by s are interpreted as unsigned char.

RETURN VALUE
	The memchr() and memrchr() functions return a pointer to the matching byte
	or NULL if the character does not occur in the given memory area.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
	}
	return (NULL);
}
