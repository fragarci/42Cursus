/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:29:44 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/02 18:00:49 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_is_double(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

double	ft_atof(char *str)
{
	double	res;
	double	dec;
	int		i;
	int		sign;

	i = 0;
	res = 0;
	dec = 0;
	sign = 1;
	if (!str)
		return (0);
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] != '.')
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	while (str[i])
		dec = dec * 10 + str[i++] - '0';
	while (dec >= 1)
		dec /= 10;
	return (res + dec * sign);
}
