/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:27:47 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/06 11:54:49 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strlcpy() function copies up to size - 1 characters from the
	NUL-terminated string src to dst, NUL-terminating the result.

RETURN VALUE
	strlcpy() returns the total length of the string they tried to create.
	That means the length of src.
*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	copy_size;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	if (size > 0)
	{
		if (len < size - 1)
			copy_size = len;
		else
			copy_size = size - 1;
		ft_memcpy(dst, src, copy_size);
		dst[copy_size] = 0;
	}
	return (len);
}
