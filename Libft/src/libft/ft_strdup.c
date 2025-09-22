/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:37:57 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/05 15:36:00 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strdup() function returns a pointer to a new string which is a
	duplicate of the string s.  Memory for the new string is obtained with 
	malloc(3), and can be freed with free(3).

RETURN VALUE
	On success, the strdup() function returns a pointer to the duplicated
	string.  It returns NULL if insufficient memory was available, with errno
	set to indicate the error.
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ret;
	size_t	size;

	size = ft_strlen(s) + 1;
	ret = (char *)malloc(sizeof(char) * size);
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s, size);
	return (ret);
}
