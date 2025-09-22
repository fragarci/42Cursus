/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 10:57:40 by fragarci          #+#    #+#             */
/*   Updated: 2025/07/24 15:40:02 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
DESCRIPTION
	The atoi() function converts the initial portion of the string pointed to 
	by nptr to int.  The behavior is the same as strtol(nptr, NULL, 10);
	except that atoi() does not detect errors.

RETURN VALUE
       The converted value or 0 on error.
*/

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	ret;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-')
		neg = -1;
	else
		neg = 1;
	if (nptr[i] == '+' || neg == -1)
		i++;
	ret = 0;
	while (ft_isdigit(nptr[i]))
		ret = (ret * 10) + (nptr[i++] - '0');
	return (ret * neg);
}
