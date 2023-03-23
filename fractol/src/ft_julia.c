/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:19:03 by fragarci          #+#    #+#             */
/*   Updated: 2023/03/20 10:55:44 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_julia(t_complex *c, t_complex *z0, t_data *data)
{
	t_complex	*j;
	int			n;
	double		module;

	z0->real += 0.5f;
	j = ft_create_complex(z0->real, z0->imagine);
	n = 0;
	while (ft_complex_module(j) <= 4 && n < data->max_iter)
	{
		ft_complex_mul(j, j);
		ft_complex_addnum(j, c);
		n++;
	}
	if (n == data->max_iter)
		return (free(j), data->max_iter);
	module = n + 1 - log(log2(ft_complex_module(j)));
	free(j);
	return (module);
}

void	ft_init_julia(t_data *data, char **argv)
{
	data->fractal = 0;
	data->complex = ft_create_complex(data->real, data->imag);
	if (!ft_is_double(argv[2]) || !ft_is_double(argv[3]))
		ft_exit(data, EXIT_FAILURE);
}
