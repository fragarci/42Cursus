/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 22:13:35 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/24 16:33:33 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_mandelbrot	*ft_struct_mandelbrot(mlx_image_t *img, double sclale_factor,
double movement_x, double movement_y)
{
	t_mandelbrot	*mandelbrot;

	mandelbrot = (t_mandelbrot *)malloc(sizeof(t_mandelbrot));
	mandelbrot->img = img;
	mandelbrot->scale_factor = sclale_factor;
	mandelbrot->movement_x = movement_x;
	mandelbrot->movement_y = movement_y;
	return (mandelbrot);
}

int	ft_mandelbrot(t_complex *complex)
{
	t_complex	*z;
	int			n;

	z = ft_create_complex(0, 0);
	n = 0;
	while (ft_complex_module(z) <= 2 && n < 40)
	{
		ft_mul_complex(z, z);
		ft_add_complex(z, complex);
		n++;
	}
	free(z);
	return (n);
}

int	ft_color_mandelbrot(int m)
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
	return (get_rgba(saturation, hue, value, 255));
}

void	ft_draw_mandelbrot(mlx_image_t *img, t_mandelbrot *data)
{
	int				x;
	int				y;
	t_complex		*c;

	c = ft_create_complex(0, 0);
	x = 0;
	while ((unsigned int)x < img -> width)
	{
		y = 0;
		while ((unsigned int)y < img -> height)
		{
			c -> real = (double)(-2 + data->movement_x
					+ (x * data->scale_factor / (double)img -> width) * 3);
			c -> imag = (double)(-1 + data->movement_y
					+ (y * data->scale_factor / (double)img -> height) * 2);
			mlx_put_pixel(img, x, y, ft_color_mandelbrot(ft_mandelbrot(c)));
			y++;
		}
		x++;
	}
}
