/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:38:17 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/24 13:07:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include <stdio.h>

void	zoom_hook(double xdelta, double ydelta, void *param)
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
	ft_draw_mandelbrot(data->img, data);
}

void	movement_hook(mlx_key_data_t keydata, void *param)
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
	ft_draw_mandelbrot(data->img, data);
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_mandelbrot	*data;

	mlx = mlx_init(600, 400, "fractol", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	img = mlx_new_image(mlx, 600, 400);
	data = ft_struct_mandelbrot(img, 1, 0, 0);
	ft_draw_mandelbrot(img, data);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_scroll_hook(mlx, &zoom_hook, data);
	mlx_key_hook(mlx, &movement_hook, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
