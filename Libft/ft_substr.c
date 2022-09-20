/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:46:37 by fragarci          #+#    #+#             */
/*   Updated: 2022/09/20 10:01:31 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	Reserves (with malloc(3)) and returns a substring of the string 's'. The
	substring starts from the index 'start' and has a maximum length 'len'.

RETURN VALUE
	The resulting substring. NULL if the memory reservation fails.
*/

#include "libft.h";

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*aux_str;
	char	*ret;
	size_t	size;

	aux_str = (char *)s;
	while (aux_str[size] != '\0' && size < len)
		size++;
	ret = (char *)malloc((sizeof(char) * size) + 1);
	size = 0;
	while (aux_str[start] != '\0' && start < len)
	{
		ret[size] = aux_str[start];
		size++;
		start++;
	}
	ret[size] = '\0';
	return (ret);
}
