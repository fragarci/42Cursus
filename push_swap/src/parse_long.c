/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:24:28 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/10 17:56:30 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

long	*ft_one_arg(char *argv)
{
	int		i;
	char	**c_nbrs;
	long	*l_nbrs;

	c_nbrs = ft_split(argv, ' ');
	i = 0;
	while (c_nbrs[i])
		i++;
	l_nbrs = (long *)malloc(sizeof(long) * i);
	if (!l_nbrs)
		return (ft_split_free(c_nbrs), (long *)0);
	i = -1;
	while (c_nbrs[++i])
		l_nbrs[i] = ft_atol(c_nbrs[i]);
	return (ft_split_free(c_nbrs), l_nbrs);
}

long	*ft_multiple_args(int argc, char **argv)
{
	unsigned int	i;
	long			*l_nbrs;

	l_nbrs = (long *)malloc(sizeof(long) * argc - 1);
	if (!l_nbrs)
		return (0);
	i = 0;
	while (argv[++i])
		l_nbrs[i - 1] = ft_atol(argv[i]);
	return (l_nbrs);
}

long	*ft_argstol(int argc, char **argv)
{
	long			*l_nbrs;

	if (argc == 2)
		l_nbrs = ft_one_arg(argv[1]);
	else if (argc > 2)
		l_nbrs = ft_multiple_args(argc, argv);
	return (l_nbrs);
}
