/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:22:04 by fragarci          #+#    #+#             */
/*   Updated: 2023/03/20 12:31:04 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	ft_main_hook(struct mlx_key_data keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
	}
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP)
			data->y_mov -= 0.50;
		if (keydata.key == MLX_KEY_DOWN)
			data->y_mov += 0.50;
		if (keydata.key == MLX_KEY_LEFT)
			data->x_mov -= 0.50;
		if (keydata.key == MLX_KEY_RIGHT)
			data->x_mov += 0.50;
		ft_color_hook(keydata, data);
		if (data->fractal == 0)
			ft_julia_move_hook(keydata, data);
		ft_draw_fractal(data);
	}
}

void	ft_color_hook(struct mlx_key_data keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_P)
		data->max_iter += 10;
	if (keydata.key == MLX_KEY_L)
		data->max_iter -= 10;
	if (keydata.key == MLX_KEY_N)
	{
		data->hue_off = 0.;
		data->rainbow = 0;
	}
	if (keydata.key == MLX_KEY_M)
		data->rainbow = !data->rainbow;
}

void	ft_julia_move_hook(struct mlx_key_data keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_Y)
		data->imag += 0.01f;
	if (keydata.key == MLX_KEY_H)
		data->imag -= 0.01f;
	if (keydata.key == MLX_KEY_G)
		data->real -= 0.01f;
	if (keydata.key == MLX_KEY_T)
		data->real += 0.01f;
	free(data->complex);
	data->complex = ft_create_complex(data->real, data->imag);
}
