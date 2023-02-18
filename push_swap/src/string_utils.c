/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:29:25 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/11 17:09:06 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_split_free(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_str_isdigit(char *str)
{
	unsigned int	i;
	unsigned int	neg;

	i = -1;
	neg = 0;
	if (!str)
		return (0);
	while (str[++i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
		{
			if (str[i] == '-')
			{
				if (neg >= 1 || i > 0)
					return (0);
				neg++;
			}
		}
		else
			return (0);
	}
	if ((i == 1 && neg == 1) || str[0] == 0)
		return (0);
	return (1);
}

long	ft_atol(const char *nptr)
{
	int		i;
	int		neg;
	long	ret;

	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\v')
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

size_t	ft_argvlen(int argc, char *argv)
{
	size_t	len;
	char	**c_nbrs;

	len = 0;
	if (argc == 2)
	{
		c_nbrs = ft_split(argv, ' ');
		while (c_nbrs[len])
			len++;
		return (ft_split_free(c_nbrs), len);
	}
	else if (argc > 2)
		len = argc - 1;
	return (len);
}
