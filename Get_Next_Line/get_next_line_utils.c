/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 12:15:22 by fragarci          #+#    #+#             */
/*   Updated: 2022/10/04 01:14:07 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	size_t	len1;
	size_t	len2;
	char	*ret;

	if (!s1 || !s2)
		return ((void *)0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len1 + len2) + 1);
	if (!ret)
		return ((void *)0);
	i = -1;
	while (++i < (int)len1)
		ret[i] = s1[i];
	i = -1;
	while (++i < (int)len2)
		ret[len1 + i] = s2[i];
	ret[len1 + i] = '\0';
	return (ret);
}

char	*ft_get_line(char *full_str)
{
	
}