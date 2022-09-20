/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:28:33 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/20 09:28:35 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strnstr() function locates the	first occurrence of the
	null-termi-nated string little in the	string big, where not more than
	len characters are searched.  Characters that appear after a `\0'
	character are not searched.

RETURN VALUE
	If	little is an empty string, big is returned; if little occurs nowhere
	in	big, NULL is returned; otherwise a pointer to the first	character of
	the first occurrence of little is returned.
*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*ret;
	size_t	i;

	ret = (char *)big;
	i = 0;
	while (*ret && i < len)
	{
		if (ft_strncmp(ret, little, ft_strlen(little)) == 0)
			return (ret);
		ret++;
		i++;
	}
	return (0);
}
