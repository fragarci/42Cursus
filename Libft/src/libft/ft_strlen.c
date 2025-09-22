/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 09:27:57 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/19 00:23:34 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The strlen() function calculates the length of the string pointed to by s,
	excluding the terminating null byte ('\0').

RETURN VALUE
	The strlen() function returns the number of bytes in the string pointed
	to by s.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	register const char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}
