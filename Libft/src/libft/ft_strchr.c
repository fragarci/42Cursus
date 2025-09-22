/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:32:20 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/05 12:32:45 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strchr() function returns a pointer to the first occurrence of the
	character c in the string s.

RETURN VALUE
	The strchr() and strrchr() functions return a pointer to the matched
	character or NULL if the character is not found.  The terminating null
	byte is considered part of the string, so that if c is specified as '\0',
	these functions return a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
