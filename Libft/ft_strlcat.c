/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:13:03 by fragarci          #+#    #+#             */
/*   Updated: 2022/08/31 16:13:03 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strlcat() function appends the NUL-terminated string src to the end
	of dst. It will append at most size - strlen(dst) - 1 bytes,
	NUL-terminating the result.

RETURN VALUE
	strlcat() functions returns the total length of the string they tried to
	create. For strlcat() that means the initial length of dst plus the length
	of src.
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	while (src[i] && size > 0)
	{
		dst[len + i] = src[i];
		i++;
		size--;
	}
	dst[len + i] = '\0';
	return (len + i);
}
