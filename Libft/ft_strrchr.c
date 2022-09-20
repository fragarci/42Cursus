/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:42 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/20 09:28:46 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strrchr() function returns a pointer to the last occurrence of the
	character c in the string s.

RETURN VALUE
	return a pointer to the matched character or NULL if the character is not
	found. The terminating null byte is considered part of the string, so that
	if c is specified as aq\0aq, these functions return a pointer to the
	terminator.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	size_t	i;

	last = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			last = (char *)(s + i);
	}
	return (last);
}
