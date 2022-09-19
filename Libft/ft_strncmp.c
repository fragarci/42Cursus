/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:21:01 by fragarci          #+#    #+#             */
/*   Updated: 2022/08/31 17:21:01 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	 The strcmp() function compares the two strings s1 and s2.  The locale is
	 not taken into account (for a locale-aware comparison, see strcoll(3)).
	 The comparison is done using unsigned characters.

RETURN VALUE
	The strcmp() function return an integer less than, equal to, or greater
	 than zero if s1 (or the first n bytes thereof) is found, respectively,
	 to be less than, to match, or be greater than s2.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((int)(s1[i] - s2[i]));
}
