/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:25:34 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/21 14:36:53 by fragarci         ###   ########.fr       */
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
	unsigned char	*arr;
	size_t			i;

	aux_src = (unsigned char *)src;
	aux_dest = (unsigned char *)dest;
	i = 0;
	while (aux_src[i] && i < n)
		i++;
	arr = (unsigned char *)malloc(sizeof(char) * i);
	if (!arr)
		return (0);
	i = 0;
	while (aux_src[i] && i < n)
	{
		aux_src[i] = arr[i];
		i++;
	}
	while (*arr)
		*(aux_dest++) = *(arr++);
	free(arr);
	return (dest);
}
