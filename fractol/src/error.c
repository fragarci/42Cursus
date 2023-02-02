/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:57:41 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/02 18:24:42 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_exit(t_data *data, int status)
{
	if (status == EXIT_SUCCESS)
	{
		mlx_terminate(data->mlx);
		free(data->complex);
		exit(EXIT_SUCCESS);
	}
	else if (status == EXIT_FAILURE)
	{
		ft_printf("\033[31m");
		ft_printf("Usage: ./fractol [fractal name]\n");
		ft_printf("Available fractals: mandelbrot, julia [Constant]\n");
		ft_printf("\033[0m");
		if (data != NULL)
		{
			mlx_terminate(data->mlx);
			free(data->complex);
		}
		exit(EXIT_FAILURE);
	}
}
