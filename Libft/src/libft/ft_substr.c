/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:46:37 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/06 12:00:52 by fragarci         ###   ########.fr       */
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
	size_t	str_len;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (str_len < start)
		return ((char *)ft_calloc(sizeof(char), 1));
	if (len > str_len - start)
		len = str_len - start;
	ret = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s + start, len);
	return (ret);
}
