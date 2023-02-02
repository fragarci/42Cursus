/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:12:23 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/02 18:00:56 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	ft_mandelbrot(t_complex *complex, t_data *data)
{
	t_complex	*j;
	int			n;
	double		result;

	j = ft_create_complex(0, 0);
	n = 0;
	while (ft_complex_module(j) <= 4 && n < data->max_iter)
	{
		ft_complex_mul(j, j);
		ft_complex_addnum(j, complex);
		n++;
	}
	if (n == data->max_iter)
		return (free(j), data->max_iter);
	result = n + 1 - log(log2(ft_complex_module(j)));
	free(j);
	return (result);
}

void	ft_init_mandelbrot(t_data *data, int argc)
{
	if (argc > 2)
		ft_exit(data, EXIT_FAILURE);
	data->fractal = 1;
}
