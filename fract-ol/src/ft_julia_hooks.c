/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:34:44 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/25 12:43:13 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_zoom_hook(double xdelta, double ydelta, void *param)
{
	t_julia			*data;
	static double	scale_factor = 1;

	data = (t_julia *)param;
	if (xdelta)
	{
	}
	if (ydelta > 0)
		scale_factor -= 0.01;
	else if (ydelta < 0)
		scale_factor += 0.01;
	data->scale_factor = scale_factor;
	ft_draw_julia(data);
}

void	julia_movement_hook(mlx_key_data_t keydata, void *param)
{
	t_julia			*data;
	static double	movement_x = 0;
	static double	movement_y = 0;

	data = (t_julia *)param;
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
	ft_draw_julia(data);
}
