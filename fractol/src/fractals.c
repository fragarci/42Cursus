/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:49:49 by fragarci          #+#    #+#             */
/*   Updated: 2023/03/20 12:26:25 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_data	ft_init_fractal(void)
{
	t_data	data;

	data.mlx = mlx_init(WIDTH, HEIGHT, "Fract-Ol", true);
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	data.scale = 1;
	data.rainbow = 0;
	data.hue_off = 0;
	data.max_iter = 40;
	if (!data.mlx)
		exit(EXIT_FAILURE);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	data.complex = NULL;
	return (data);
}

void	ft_choose_fractal(char **argv, int argc, t_data *data)
{
	if (!ft_strncmp(argv[1], "julia", ft_strlen(argv[1])))
	{
		data->real = ft_atof(argv[2]);
		data->imag = ft_atof(argv[3]);
		ft_init_julia(data, argv);
	}
	else if (!ft_strncmp(argv[1], "mandelbrot", ft_strlen(argv[1])))
		ft_init_mandelbrot(data, argc);
	else
		ft_exit(data, EXIT_FAILURE);
}

void	ft_draw_fractal(t_data *data)
{
	int			x;
	int			y;
	t_complex	*complex;

	complex = ft_create_complex(0, 0);
	x = 0;
	while ((unsigned int)x < WIDTH)
	{
		y = 0;
		while ((unsigned int)y < HEIGHT)
		{
			ft_render_pixel(data, complex, x, y);
			y++;
		}
		x++;
	}
	free(complex);
}

void	ft_render_pixel(t_data *data, t_complex *complex, int x, int y)
{
	complex->real = (double)(-2 + data->x_mov + (x * data->scale
				/ (double)WIDTH) * 3);
	complex->imagine = (double)(-1 + data->y_mov + (y * data->scale
				/ (double)HEIGHT) * 2);
	if (data->fractal == 1)
		mlx_put_pixel(data->img, x, y, ft_fractal_color(ft_mandelbrot(complex,
					data), data));
	else if (data->fractal == 0)
		mlx_put_pixel(data->img, x, y, ft_fractal_color(ft_julia(data->complex,
					complex, data), data));
}
