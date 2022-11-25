/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot_hooks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:40:43 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/25 12:37:21 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot_zoom_hook(double xdelta, double ydelta, void *param)
{
	t_mandelbrot	*data;
	static double	scale_factor = 1;

	data = (t_mandelbrot *)param;
	if (xdelta)
	{
	}
	if (ydelta > 0)
		scale_factor -= 0.01;
	else if (ydelta < 0)
		scale_factor += 0.01;
	data->scale_factor = scale_factor;
	ft_draw_mandelbrot(data);
}

void	mandelbrot_movement_hook(mlx_key_data_t keydata, void *param)
{
	t_mandelbrot	*data;
	static double	movement_x = 0;
	static double	movement_y = 0;

	data = (t_mandelbrot *)param;
	if (keydata.key == MLX_KEY_W)
		movement_y -= 0.01;
	if (keydata.key == MLX_KEY_S)
		movement_y += 0.01;
	if (keydata.key == MLX_KEY_A)
		movement_x -= 0.01;
	if (keydata.key == MLX_KEY_D)
		movement_x += 0.01;
	data->movement_x = movement_x;
	data->movement_y = movement_y;
	ft_draw_mandelbrot(data);
}
