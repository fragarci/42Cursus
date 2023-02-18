/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:36:48 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/18 14:42:49 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	ft_check_duplicates_error(long *l_nbrs, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (l_nbrs[i] == l_nbrs[j])
				return (free(l_nbrs), 0);
			j++;
		}
		i++;
	}
	return (free(l_nbrs), 1);
}

static int	ft_check_limits_error(long *l_nbrs, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
		if (l_nbrs[i] <= INT_MIN || l_nbrs[i++] >= INT_MAX)
			return (free(l_nbrs), 0);
	return (free(l_nbrs), 1);
}

static int	ft_check_digit_error(int argc, char **argv)
{
	char			**c_nbrs;
	unsigned int	i;

	c_nbrs = ft_split(argv[1], ' ');
	if (!c_nbrs[0])
		return (ft_split_free(c_nbrs), 0);
	if (argc == 2)
	{
		i = 0;
		while (c_nbrs[i])
			if (!ft_str_isdigit(c_nbrs[i++]))
				return (ft_split_free(c_nbrs), 0);
	}
	else if (argc > 2)
	{
		i = 1;
		while (i < (unsigned int)argc)
			if (!ft_str_isdigit(argv[i++]))
				return (ft_split_free(c_nbrs), 0);
	}
	return (ft_split_free(c_nbrs), 1);
}

void	ft_check_arg_error(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (!ft_check_digit_error(argc, argv)
		|| ! ft_check_limits_error(ft_argstol(argc, argv),
			ft_argvlen(argc, argv[1]))
		|| !ft_check_duplicates_error(ft_argstol(argc, argv),
			ft_argvlen(argc, argv[1])))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}
