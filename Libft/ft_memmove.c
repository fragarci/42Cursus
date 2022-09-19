/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:18:51 by fragarci          #+#    #+#             */
/*   Updated: 2022/08/29 19:18:51 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The memmove() function copies n bytes from memory area src to memory area
	dest.  The memory areas may overlap: copying takes place as though the
	bytes in src are first copied into a temporary array that not overlap
	src or dest, and the bytes are then copied from the temporary array to dest.

RETURN VALUE
	The memmove() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*aux_src;
	unsigned char	*aux_dest;

	aux_src = (unsigned char *)src;
	aux_dest = dest;
	if (dest == src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n--)
			aux_dest[n] = aux_src[n];
	}
	return (dest);
}
