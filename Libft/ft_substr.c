/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:46:37 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/29 16:35:52 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Reserves (with malloc(3)) and returns a substring of the string 's'. The
	substring starts from the index 'start' and has a maximum length 'len'.

RETURN VALUE
	The resulting substring. NULL if the memory reservation fails.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return ((void *)0);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			ret[j] = s[i];
			j++;
		}
		i++;
	}
	ret[j] = 0;
	return (ret);
}
