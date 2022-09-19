/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 22:09:31 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/13 22:09:31 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	strtrim removes all whitespace characters from the beginning and the end
	of a string. As whitespace is counted everything for which isspace(3)
	returns true.
*/

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	start;
	size_t	end;
	size_t	i;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	ret = (char *)malloc(sizeof(char) * (end - start) + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while (start < end)
	{
		ret[i] = s[start];
		i++;
		start++;
	}
	ret[i] = '\0';
	return (ret);
}
