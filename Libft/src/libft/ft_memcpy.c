/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:23 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/06 11:36:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The memcpy() function copies n bytes from memory area src to memory area
	dest.  The memory areas must not overlap.  Use memmove(3) if the memory
	areas do overlap.

RETURN VALUE
	The memcpy() function returns a pointer to dest.
*/

#include "libft.h"

void	*ft_memcpy(void	*dest, const void *src, size_t n)
{
	unsigned char		*aux_dest;
	const unsigned char	*aux_src;

	if (!dest && !src)
		return (0);
	if (dest == src || n == 0)
		return (dest);
	aux_dest = (unsigned char *)dest;
	aux_src = (const unsigned char *)src;
	while (n >= sizeof(u_int64_t))
	{
		*(u_int64_t *)aux_dest = *(u_int64_t *)aux_src;
		aux_dest += sizeof(u_int64_t);
		aux_src += sizeof(u_int64_t);
		n -= sizeof(u_int64_t);
	}
	while (n--)
	{
		*aux_dest = *aux_src;
		aux_dest++;
		aux_src++;
	}
	return (dest);
}
