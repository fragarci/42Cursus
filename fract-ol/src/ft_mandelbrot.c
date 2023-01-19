/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:13:35 by fragarci          #+#    #+#             */
/*   Updated: 2023/01/19 17:29:54 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mandelbrot	*ft_struct_mandelbrot(mlx_image_t *img)
{
	t_mandelbrot	*mandelbrot;

	mandelbrot = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	mandelbrot->img = img;
	mandelbrot->scale_factor = 1;
	mandelbrot->movement_x = 0;
	mandelbrot->movement_y = 0;
	return (mandelbrot);
}

double	ft_mandelbrot(t_complex *complex)
{
	t_complex	*z;
	int			n;
	double		res;

	z = ft_create_complex(0, 0);
	n = 0;
	while (ft_complex_module(z) <= 2 && n < 40)
	{
		ft_mul_complex(z, z);
		ft_add_complex(z, complex);
		n++;
	}
	if (n == 40)
	{
		free(z);
		return (40);
	}
	res = n + 1 - log(log2(ft_complex_module(z)));
	free(z);
	return (res);
}

int	ft_color_mandelbrot(double m)
{
	int	hue;
	int	saturation;
	int	value;

	hue = 255 * m / 40;
	saturation = 255;
	if (m == 40)
		value = 255;
	else
		value = 0;
	return (get_rgba(hue, saturation, value, 255));
}

void	ft_draw_mandelbrot(t_mandelbrot *data)
{
	int				x;
	int				y;
	t_complex		*c;

	c = ft_create_complex(0, 0);
	x = 0;
	while ((unsigned int)x < data->img -> width)
	{	
		y = 0;
		while ((unsigned int)y < data->img -> height)
		{
			c -> real = (double)(-2 + data->movement_x
					+ (x * data->scale_factor
						/ (double)data->img -> width) * 3);
			c -> imag = (double)(-1 + data->movement_y
					+ (y * data->scale_factor
						/ (double)data->img -> height) * 2);
			mlx_put_pixel(data->img, x, y,
				ft_color_mandelbrot(ft_mandelbrot(c)));
			y++;
		}
		x++;
	}
	free(c);
}
