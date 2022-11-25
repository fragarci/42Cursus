/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 09:03:23 by fragarci          #+#    #+#             */
/*   Updated: 2022/11/25 12:28:11 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_julia	*ft_struct_julia(mlx_image_t *img, double real, double imag)
{
	t_julia		*julia;
	t_complex	*constant;

	julia = (t_julia *)malloc(sizeof(t_julia));
	constant = ft_create_complex(real, imag);
	julia->img = img;
	julia->scale_factor = 1;
	julia->movement_x = 0;
	julia->movement_y = 0;
	julia->constant = constant;
	return (julia);
}

double	ft_julia(t_complex *c, t_complex *z0)
{
	t_complex	*z;
	int			n;
	double		res;

	z = ft_create_complex(z0->real, z0->imag);
	n = 0;
	while (ft_complex_module(z) <= 2 && n < 40)
	{
		ft_mul_complex(z, z);
		ft_add_complex(z, c);
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

int	ft_color_julia(double m)
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
	(get_rgba(hue, hue, hue, 255));
}

void	ft_draw_julia(t_julia *data)
{
	int				x;
	int				y;
	t_complex		*z0;

	z0 = ft_create_complex(0, 0);
	x = 0;
	while ((unsigned int)x < data->img -> width)
	{
		y = 0;
		while ((unsigned int)y < data->img -> height)
		{
			z0 -> real = (double)(-2 + data->movement_x
					+ (x * data->scale_factor
						/ (double)data->img -> width) * 3);
			z0 -> imag = (double)(-1 + data->movement_y
					+ (y * data->scale_factor
						/ (double)data->img -> height) * 2);
			mlx_put_pixel(data->img, x, y,
				ft_color_julia(ft_julia(data->constant, z0)));
			y++;
		}
		x++;
	}
}
