/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:57:41 by fragarci          #+#    #+#             */
/*   Updated: 2023/03/20 12:32:57 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_exit(t_data *data, int status)
{
	if (status == EXIT_SUCCESS)
	{
		if (data->complex)
			free(data->complex);
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
			if (data->complex)
				free(data->complex);
		}
		exit(EXIT_FAILURE);
	}
}
